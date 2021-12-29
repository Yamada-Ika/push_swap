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
#include "order_helper.h"

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

bool	ft_is_val_in_stack(t_stack *stack, int val)
{
	t_stack	*sentinel;

	sentinel = stack;
	while (true)
	{
		stack = stack->back;
		if (stack == sentinel)
			return (false);
		if (stack->val == val)
			return (true);
	}
}

bool	ft_is_sorted(t_stack *bilist)
{
	t_stack	*dummy;
	int		prev_val;

	prev_val = INT_MAX;
	dummy = bilist;
	while (true)
	{
		bilist = bilist->front;
		if (dummy == bilist)
			break ;
		if (bilist->val > prev_val)
			return (false);
		prev_val = bilist->val;
	}
	return (true);
}
