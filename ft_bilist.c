/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:56:54 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 03:42:10 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new_bilist_sentinel(void)
{
	t_stack	*sentinel;

	sentinel = (t_stack *)malloc(sizeof(t_stack));
	if (sentinel == NULL)
		return (NULL);
	sentinel->front = sentinel;
	sentinel->back = sentinel;
	sentinel->val = -1;
	return (sentinel);
}

t_stack	*ft_new_bilist(int val)
{
	t_stack	*new_bilist;

	new_bilist = (t_stack *)malloc(sizeof(t_stack));
	if (new_bilist == NULL)
		return (NULL);
	new_bilist->val = val;
	new_bilist->front = NULL;
	new_bilist->back = NULL;
	return (new_bilist);
}

void	ft_add_bilist(t_stack *bilist_1, t_stack *bilist_2)
{
	t_stack	*prev_end_node;
	t_stack	*sentinel_node;

	sentinel_node = bilist_1;
	if (bilist_1->front == bilist_1 && bilist_1->back == bilist_1)
	{
		sentinel_node->front = bilist_2;
		sentinel_node->back = bilist_2;
		bilist_2->front = sentinel_node;
		bilist_2->back = sentinel_node;
		return ;
	}
	prev_end_node = sentinel_node->back;
	sentinel_node->back = bilist_2;
	prev_end_node->front = bilist_2;
	bilist_2->front = sentinel_node;
	bilist_2->back = prev_end_node;
}

t_stack	*ft_new_stack(int	*arry, size_t size)
{
	t_stack	*new_stack;
	t_stack	*new_node;
	size_t		i;

	new_stack = ft_new_bilist_sentinel();
	if (arry == NULL || new_stack == NULL)
		return (new_stack);
	i = size - 1;
	while (i >= 0)
	{
		new_node = ft_new_bilist(arry[i]);
		if (new_node == NULL)
			return (NULL);
		ft_add_bilist(new_stack, new_node);
		if (i == 0)
			break ;
		i--;
	}
	return (new_stack);
}

void	ft_del_bilist(t_stack **bilist)
{
	free(*bilist);
	*bilist = NULL;
}

t_stack	*ft_pop_bilist(t_stack *bilist)
{
	t_stack	*end_node;
	t_stack	*second_from_end_node;

	if (bilist->front == bilist && bilist->back == bilist)
		return (NULL);
	end_node = bilist->back;
	second_from_end_node = end_node->back;
	second_from_end_node->front = bilist;
	bilist->back = second_from_end_node;
	return (end_node);
}

void	ft_push(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*popped_element;

	popped_element = ft_pop_bilist(stack_2);
	ft_add_bilist(stack_1, popped_element);
}

t_stack	*ft_get_element_at_index(t_stack *stack, int index)
{
	t_stack	*sentinental_node;

	if (index == TAIL)
		return (stack->back);
	if (index == SECOND_TAIL)
		return (stack->back->back);
	if (index == SENTINEL)
		return (stack);
	if (index > 0)
	{
		while (index > 0)
		{
			stack = stack->front;
			index--;
		}
	}
	return (stack);
}

bool	ft_is_sentinel(t_stack *bilist)
{
	return (bilist->front == bilist && bilist->back == bilist);
}

bool	ft_is_less_than_one_element(t_stack *bilist)
{
	if (ft_is_sentinel(bilist))
		return (true);
	return (bilist->back == bilist->front);
}

void	ft_swap_helper(t_stack *stack, int index_1, int index_2)
{
	t_stack	*element_1;
	t_stack	*element_2;
	t_stack	*front_element_2;

	if (ft_is_sentinel(stack) || ft_is_less_than_one_element(stack))
		return ;
	element_1 = ft_get_element_at_index(stack, index_1);
	element_2 = ft_get_element_at_index(stack, index_2);
	if (element_1 == element_2)
		return ;
	front_element_2 = element_2->front;
	element_1->back->front = element_2;
	element_2->back = element_1->back;
	element_2->front = element_1;
	element_1->back = element_2;
	element_1->front = front_element_2;
	front_element_2->back = element_1;
}

void	ft_swap(t_stack *stack)
{
	ft_swap_helper(stack, SECOND_TAIL, TAIL);
}

void	ft_rotate(t_stack *stack)
{
	ft_swap_helper(stack, TAIL, SENTINEL);
}

void	ft_reverse_rotate(t_stack *stack)
{
	ft_swap_helper(stack, SENTINEL, HEAD);
}

void	ft_delete_stack(t_stack *stack)
{
	t_stack	*dummy;
	t_stack	*prev_stack;

	dummy = stack;
	while (1) {
		prev_stack = stack;
		stack = stack->front;
		ft_del_bilist(&prev_stack);
		if (stack == dummy)
			break;
	}
}

int		ft_get_stack_size(t_stack *stack)
{
	t_stack	*dummy = stack;
	int			element_count = 0;

	dummy = stack;
	while (1) {
		stack = stack->front;
		if (stack == dummy)
			break;
		element_count++;
	}
	return (element_count);
}

void	ft_sort(int *arry, int size)
{
	int	is_swap;
	int	tmp;

	while (1)
	{
		is_swap = 0;
		for (int i = 0; i < size - 1; i++) {
			if (arry[i] < arry[i+1])
			{
				tmp = arry[i];
				arry[i] = arry[i+1];
				arry[i+1] = tmp;
				is_swap = 1;
			}
		}
		if (is_swap == 0)
			break ;
	}
}

int	ft_get_median_from_bilist(t_stack *a, int upper_limit)
{
	t_stack	*sentinel_node;
	int			median;
	int			element_count;
	int			median_index;
	int			i;
	int			*arry;

	// element_count = ft_get_stack_size(a);
	arry = (int *)malloc(sizeof(int) * upper_limit);
	median_index = upper_limit / 2;
	i = 0;
	sentinel_node = a;
	while (i < upper_limit)
	{
		a = a->back;
		if (a == sentinel_node)
			break ;
		arry[i] = a->val;
		i++;
	}
	ft_sort(arry, upper_limit);
	median = arry[median_index];
	return (median);
}

void	ft_sa(t_stack *a)
{
	printf("sa\n");
	ft_swap(a);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	printf("pa\n");
	ft_push(a, b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	printf("pb\n");
	ft_push(b, a);
}

void	ft_ra(t_stack *a)
{
	printf("ra\n");
	ft_rotate(a);
}

void	ft_rb(t_stack *b)
{
	printf("rb\n");
	ft_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(t_stack *a)
{
	printf("rra\n");
	ft_reverse_rotate(a);
}

void	ft_rrb(t_stack *b)
{
	printf("rrb\n");
	ft_reverse_rotate(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	printf("rrr\n");
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}

bool	ft_is_val_in_stack(t_stack *stack, int val)
{
	t_stack	*sentinel;

	sentinel = stack;
	while (1)
	{
		stack = stack->back;
		if (stack == sentinel)
			return (false);
		if (stack->val == val)
			return (true);
	}
}

int	ft_get_min_val_from_stack(t_stack *bilist)
{
	int	index;
	int	minimum_val;
	t_stack	*sentinel;

	sentinel = bilist;
	index = 0;
	minimum_val = INT_MAX;
	while (1)
	{
		bilist = bilist->back;
		if (bilist == sentinel)
			break ;
		if (minimum_val > bilist->val)
		{
			minimum_val = bilist->val;
		}
		index++;
	}
	return (minimum_val);
}

int	ft_get_minimum_val_index_from_bilist(t_stack *bilist)
{
	int	index;
	int	minimum_val_index;
	int	minimum_val;
	t_stack	*sentinel;

	sentinel = bilist;
	index = 0;
	minimum_val = INT_MAX;
	while (1)
	{
		bilist = bilist->back;
		if (bilist == sentinel)
			break ;
		if (minimum_val > bilist->val)
		{
			minimum_val = bilist->val;
			minimum_val_index = index; 
		}
		index++;
	}
	return (minimum_val_index);
}

void	ft_pa_minimum_element(t_stack *a, t_stack *b)
{
	int	minimum_val_index = ft_get_minimum_val_index_from_bilist(b);
	int	element_count = ft_get_stack_size(b);
	int	reverse_rotate_count = 0;
	int	rotate_count = 0;

	if (minimum_val_index > element_count / 2)
	{
		reverse_rotate_count = element_count - minimum_val_index;
		while (reverse_rotate_count > 0)
		{
			ft_rrb(b);
			reverse_rotate_count--;
		}
	}
	else
	{
		rotate_count = minimum_val_index;
		while (rotate_count > 0)
		{
			ft_rb(b);
			rotate_count--;
		}
	}
	ft_pa(a, b);
}

void	ft_pb_min_val(t_stack *a, t_stack *b)
{
	int	minimum_val_index = ft_get_minimum_val_index_from_bilist(a);
	int	element_count = ft_get_stack_size(a);
	int	reverse_rotate_count = 0;
	int	rotate_count = 0;

	if (minimum_val_index > element_count / 2)
	{
		reverse_rotate_count = element_count - minimum_val_index;
		while (reverse_rotate_count > 0)
		{
			ft_rra(a);
			reverse_rotate_count--;
		}
	}
	else
	{
		rotate_count = minimum_val_index;
		while (rotate_count > 0)
		{
			ft_ra(a);
			rotate_count--;
		}
	}
	ft_pb(a, b);
}

void	ft_print_stack(t_stack *stack)
{
	t_stack	*dummy = stack;

	while (1) {
		stack = stack->front;
		if (stack == dummy)
			break;
		printf(" %d", stack->val);
	}
	putchar('\n');
}

void	ft_print_sepline(void)
{
	printf("---------------------------------\n");
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	ft_print_sepline();
	printf("a :");
	ft_print_stack(a);
	printf("b :");
	ft_print_stack(b);
	ft_print_sepline();
}

bool	ft_is_sorted(t_stack *bilist)
{
	t_stack	*sentinel_node;
	int			prev_val;

	prev_val = bilist->front->val;
	sentinel_node = bilist;
	while (1)
	{
		bilist = bilist->front;
		if (sentinel_node == bilist)
			break ;
		if (bilist->val > prev_val)
			return (false);
		prev_val = bilist->val;
	}
	return (true);
}

int	ft_get_sorted_bilist_num(t_stack *bilist)
{
	t_stack	*sentinel_node;
	int			prev_val;
	int			sorted_bilist_num;

	prev_val = bilist->back->val;
	sentinel_node = bilist;
	sorted_bilist_num = 0;
	while (1)
	{
		bilist = bilist->back;
		if (sentinel_node == bilist)
			break ;
		if (bilist->val < prev_val)
			break ;
		prev_val = bilist->val;
		sorted_bilist_num++;
	}
	return (sorted_bilist_num);
}

