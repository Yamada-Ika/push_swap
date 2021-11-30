/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:56:54 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/30 16:01:15 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bilist	*ft_new_bilist_sentinel(void)
{
	t_bilist	*sentinel;

	sentinel = (t_bilist *)malloc(sizeof(t_bilist));
	if (sentinel == NULL)
		return (NULL);
	sentinel->front = sentinel;
	sentinel->back = sentinel;
	return (sentinel);
}

t_bilist	*ft_new_bilist(int value)
{
	t_bilist	*new_bilist;

	new_bilist = (t_bilist *)malloc(sizeof(t_bilist));
	if (new_bilist == NULL)
		return (NULL);
	new_bilist->value = value;
	new_bilist->front = NULL;
	new_bilist->back = NULL;
	return (new_bilist);
}

void	ft_add_bilist(t_bilist *bilist_1, t_bilist *bilist_2)
{
	t_bilist	*prev_end_node;
	t_bilist	*sentinel_node;

	sentinel_node = bilist_1;
	// bilist_1が番兵ノード
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

t_bilist	*ft_create_stack(int	*array, size_t size)
{
	t_bilist	*new_stack;
	t_bilist	*new_node;
	size_t		i;

	new_stack = ft_new_bilist_sentinel();
	if (array == NULL || new_stack == NULL)
		return (new_stack);
	i = size - 1;
	while (i >= 0)
	{
		new_node = ft_new_bilist(array[i]);
		if (new_node == NULL)
			return (NULL);
		ft_add_bilist(new_stack, new_node);
		if (i == 0)
			break ;
		i--;
	}
	return (new_stack);
}

void	ft_del_bilist(t_bilist **bilist)
{
	free(*bilist);
	*bilist = NULL;
}

t_bilist	*ft_pop_bilist(t_bilist *bilist)
{
	t_bilist	*end_node;
	t_bilist	*second_from_end_node;

	if (bilist->front == bilist && bilist->back == bilist)
		return (NULL);
	end_node = bilist->back;
	second_from_end_node = end_node->back;
	second_from_end_node->front = bilist;
	bilist->back = second_from_end_node;
	return (end_node);
}

void	ft_push(t_bilist *stack_1, t_bilist *stack_2)
{
	t_bilist	*popped_element;

	popped_element = ft_pop_bilist(stack_2);
	ft_add_bilist(stack_1, popped_element);
}

t_bilist	*ft_get_element_at_index(t_bilist *stack, int index)
{
	t_bilist	*sentinental_node;

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

bool	ft_is_sentinel(t_bilist *bilist)
{
	return (bilist->front == bilist && bilist->back == bilist);
}

bool	ft_is_less_than_one_element(t_bilist *bilist)
{
	if (ft_is_sentinel(bilist))
		return (true);
	return (bilist->back == bilist->front);
}

void	ft_swap_helper(t_bilist *stack, int index_1, int index_2)
{
	t_bilist	*element_1;
	t_bilist	*element_2;
	t_bilist	*front_element_2;

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

void	ft_swap(t_bilist *stack)
{
	ft_swap_helper(stack, SECOND_TAIL, TAIL);
}

void	ft_rotate(t_bilist *stack)
{
	ft_swap_helper(stack, TAIL, SENTINEL);
}

void	ft_reverse_rotate(t_bilist *stack)
{
	ft_swap_helper(stack, SENTINEL, HEAD);
}

void	ft_delete_stack(t_bilist *stack)
{
	t_bilist	*dummy;
	t_bilist	*prev_stack;

	dummy = stack;
	while (1) {
		prev_stack = stack;
		stack = stack->front;
		ft_del_bilist(&prev_stack);
		if (stack == dummy)
			break;
	}
}

int		ft_get_bilist_element(t_bilist *stack)
{
	t_bilist	*dummy = stack;
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

void	ft_sort(int *array, int size)
{
	int	is_swap;
	int	tmp;

	while (1)
	{
		is_swap = 0;
		for (int i = 0; i < size - 1; i++) {
			if (array[i] < array[i+1])
			{
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
				is_swap = 1;
			}
		}
		if (is_swap == 0)
			break ;
	}
}

int	ft_get_median_from_bilist(t_bilist *stack_a, int upper_limit)
{
	t_bilist	*sentinel_node;
	int			median;
	int			element_count;
	int			median_index;
	int			i;
	int			*array;

	// element_count = ft_get_bilist_element(stack_a);
	array = (int *)malloc(sizeof(int) * upper_limit);
	median_index = upper_limit / 2;
	i = 0;
	sentinel_node = stack_a;
	while (i < upper_limit)
	{
		stack_a = stack_a->back;
		if (stack_a == sentinel_node)
			break ;
		array[i] = stack_a->value;
		i++;
	}
	ft_sort(array, upper_limit);
	median = array[median_index];
	return (median);
}

void	ft_sa(t_bilist *stack_a)
{
	printf("sa\n");
	ft_swap(stack_a);
}

void	ft_pa(t_bilist *stack_a, t_bilist *stack_b)
{
	printf("pa\n");
	ft_push(stack_a, stack_b);
}

void	ft_pb(t_bilist *stack_a, t_bilist *stack_b)
{
	printf("pb\n");
	ft_push(stack_b, stack_a);
}

void	ft_ra(t_bilist *stack_a)
{
	printf("ra\n");
	ft_rotate(stack_a);
}

void	ft_rb(t_bilist *stack_b)
{
	printf("rb\n");
	ft_rotate(stack_b);
}


void	ft_rra(t_bilist *stack_a)
{
	printf("rra\n");
	ft_reverse_rotate(stack_a);
}

void	ft_rrb(t_bilist *stack_b)
{
	printf("rrb\n");
	ft_reverse_rotate(stack_b);
}

int	ft_get_minimum_value_index_from_bilist(t_bilist *bilist)
{
	int	index;
	int	minimum_value_index;
	int	minimum_value;
	t_bilist	*sentinel;

	sentinel = bilist;
	index = 0;
	minimum_value = INT_MAX;
	while (1)
	{
		bilist = bilist->back;
		if (bilist == sentinel)
			break ;
		if (minimum_value > bilist->value)
		{
			minimum_value = bilist->value;
			minimum_value_index = index; 
		}
		index++;
	}
	return (minimum_value_index);
}

void	ft_pa_minimum_element(t_bilist *stack_a, t_bilist *stack_b)
{
	int	minimum_value_index = ft_get_minimum_value_index_from_bilist(stack_b);
	int	element_count = ft_get_bilist_element(stack_b);
	int	reverse_rotate_count = 0;
	int	rotate_count = 0;

	if (minimum_value_index > element_count / 2)
	{
		reverse_rotate_count = element_count - minimum_value_index;
		while (reverse_rotate_count > 0)
		{
			ft_rrb(stack_b);
			reverse_rotate_count--;
		}
	}
	else
	{
		rotate_count = minimum_value_index;
		while (rotate_count > 0)
		{
			ft_rb(stack_b);
			rotate_count--;
		}
	}
	ft_pa(stack_a, stack_b);
}

void	ft_pb_minimum_element(t_bilist *stack_a, t_bilist *stack_b)
{
	int	minimum_value_index = ft_get_minimum_value_index_from_bilist(stack_a);
	int	element_count = ft_get_bilist_element(stack_a);
	int	reverse_rotate_count = 0;
	int	rotate_count = 0;

	if (minimum_value_index > element_count / 2)
	{
		reverse_rotate_count = element_count - minimum_value_index;
		while (reverse_rotate_count > 0)
		{
			ft_rra(stack_a);
			reverse_rotate_count--;
		}
	}
	else
	{
		rotate_count = minimum_value_index;
		while (rotate_count > 0)
		{
			ft_ra(stack_a);
			rotate_count--;
		}
	}
	ft_pb(stack_a, stack_b);
}

void	ft_print_stack(t_bilist *stack)
{
	t_bilist	*dummy = stack;

	while (1) {
		stack = stack->front;
		if (stack == dummy)
			break;
		printf(" %d", stack->value);
	}
	putchar('\n');
}

void	ft_print_sepline(void)
{
	printf("---------------------------------\n");
}

void	ft_print_stacks(t_bilist *stack_a, t_bilist *stack_b)
{
	ft_print_sepline();
	printf("a :");
	ft_print_stack(stack_a);
	printf("b :");
	ft_print_stack(stack_b);
	ft_print_sepline();
}

bool	ft_is_sorted_bilist(t_bilist *bilist)
{
	t_bilist	*sentinel_node;
	int			prev_value;

	prev_value = bilist->front->value;
	sentinel_node = bilist;
	while (1)
	{
		bilist = bilist->front;
		if (sentinel_node == bilist)
			break ;
		if (bilist->value > prev_value)
			return (false);
		prev_value = bilist->value;
	}
	return (true);
}

int	ft_get_sorted_bilist_num(t_bilist *bilist)
{
	t_bilist	*sentinel_node;
	int			prev_value;
	int			sorted_bilist_num;

	prev_value = bilist->back->value;
	sentinel_node = bilist;
	sorted_bilist_num = 0;
	while (1)
	{
		bilist = bilist->back;
		if (sentinel_node == bilist)
			break ;
		if (bilist->value < prev_value)
			break ;
		prev_value = bilist->value;
		sorted_bilist_num++;
	}
	return (sorted_bilist_num);
}

