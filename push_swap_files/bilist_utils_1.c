/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilist_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:47:10 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 16:57:03 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "order_helper.h"

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
