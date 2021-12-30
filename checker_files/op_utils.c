/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:37:39 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 19:20:21 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "macro.h"
#include "stack_utils.h"
#include "bilist_utils.h"

static void	ft_swap_helper(t_stack *stack, int index_1, int index_2)
{
	t_stack	*element_1;
	t_stack	*element_2;
	t_stack	*front_element_2;

	if (ft_is_sentinel(stack) || ft_is_size_one(stack))
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
	ft_add_bilist(stack_1, ft_pop_bilist(stack_2));
}

void	ft_rotate(t_stack *stack)
{
	ft_swap_helper(stack, TAIL, SENTINEL);
}

void	ft_reverse_rotate(t_stack *stack)
{
	ft_swap_helper(stack, SENTINEL, HEAD);
}
