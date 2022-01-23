/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilist_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 01:59:37 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:16:38 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
