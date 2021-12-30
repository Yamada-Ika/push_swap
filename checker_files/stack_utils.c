/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:19:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 19:18:55 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_stack.h"
#include "macro.h"
#include <stdbool.h>

int	ft_get_stack_size(t_stack *stack)
{
	t_stack	*dummy;
	int		size;

	dummy = stack;
	size = 0;
	while (true)
	{
		stack = stack->front;
		if (stack == dummy)
			break ;
		size++;
	}
	return (size);
}

bool	ft_is_sorted(t_stack *bilist)
{
	t_stack	*dummy;
	int		prev_val;

	dummy = bilist;
	bilist = bilist->front;
	prev_val = bilist->val;
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

bool	ft_is_size_one(t_stack *bilist)
{
	return (bilist->back == bilist->front);
}
