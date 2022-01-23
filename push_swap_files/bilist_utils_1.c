/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilist_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:47:10 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:47:25 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "order_helper.h"

// t_stack	*ft_pop_bilist(t_stack *bilist)
// {
// 	t_stack	*end_node;
// 	t_stack	*second_from_end_node;

// 	if (bilist->front == bilist && bilist->back == bilist)
// 		return (NULL);
// 	end_node = bilist->back;
// 	second_from_end_node = end_node->back;
// 	second_from_end_node->front = bilist;
// 	bilist->back = second_from_end_node;
// 	return (end_node);
// }

int	ft_get_min_val_from_stack(t_stack *bilist)
{
	int		index;
	int		min_val;
	t_stack	*sentinel;

	sentinel = bilist;
	index = 0;
	min_val = INT_MAX;
	while (true)
	{
		bilist = bilist->back;
		if (bilist == sentinel)
			break ;
		if (min_val > bilist->val)
			min_val = bilist->val;
		index++;
	}
	return (min_val);
}

int	ft_get_min_val_at(t_stack *bilist)
{
	int		index;
	int		min_val_index;
	int		min_val;
	t_stack	*dummy;

	dummy = bilist;
	index = 0;
	min_val = INT_MAX;
	while (true)
	{
		bilist = bilist->back;
		if (bilist == dummy)
			break ;
		if (min_val > bilist->val)
		{
			min_val = bilist->val;
			min_val_index = index;
		}
		index++;
	}
	return (min_val_index);
}

void	ft_pb_min_val(t_stack *a, t_stack *b)
{
	int	min_val_index;
	int	a_size;
	int	rra_cnt;
	int	ra_cnt;

	min_val_index = ft_get_min_val_at(a);
	a_size = ft_get_stack_size(a);
	if (min_val_index > a_size / 2)
	{
		rra_cnt = a_size - min_val_index;
		while (rra_cnt-- > 0)
			ft_rra(a);
	}
	else
	{
		ra_cnt = min_val_index;
		while (ra_cnt-- > 0)
			ft_ra(a);
	}
	ft_pb(a, b);
}
