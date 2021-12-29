/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:35:10 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 02:13:30 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"
#include "macro.h"
#include "bilist_utils.h"
#include <stdbool.h>

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

void	ft_push(t_stack *stack_1, t_stack *stack_2)
{
	t_stack	*popped_element;

	popped_element = ft_pop_bilist(stack_2);
	ft_add_bilist(stack_1, popped_element);
}

void	ft_rotate(t_stack *stack)
{
	ft_swap_helper(stack, TAIL, SENTINEL);
}

void	ft_reverse_rotate(t_stack *stack)
{
	ft_swap_helper(stack, SENTINEL, HEAD);
}

void	ft_sa(t_stack *a)
{
	ft_swap(a);
}

void	ft_sb(t_stack *b)
{
	ft_swap(b);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(a, b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(b, a);
}

void	ft_ra(t_stack *a)
{
	ft_rotate(a);
}

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate(a);
}

void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
