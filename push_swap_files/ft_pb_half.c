/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb_half.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 21:39:31 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/29 21:54:46 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"
#include "sort_utils.h"

static void	ft_sort_left_in_a(t_stack *a, int a_size)
{
	if (a_size == 1)
		ft_ra(a);
	if (a_size == 2)
	{
		if (a->back->val > a->back->back->val)
			ft_sa(a);
		ft_ra(a);
		ft_ra(a);
	}
}

static void	ft_restore_stack_order(t_stack *a, t_stack *b, int cnt, int min_val)
{
	while (cnt-- > 0 && min_val)
	{
		if (b->back->val != min_val)
			ft_rrr(a, b);
		else
			ft_rra(a);
	}
}

void	ft_pb_half(t_stack *a, t_stack *b, int min_val, int max_val)
{
	int	pivot;
	int	ra_cnt;
	int	a_size;

	a_size = max_val - min_val + 1;
	if (a_size <= 2)
		return (ft_sort_left_in_a(a, a_size));
	pivot = (max_val - min_val) / 2 + min_val;
	ra_cnt = 0;
	while (a_size-- > 0)
	{
		if (a->back->val <= pivot)
			ft_pb(a, b);
		else
		{
			if (b->back->val != min_val)
				ft_rr(a, b);
			else
				ft_ra(a);
			ra_cnt++;
		}
	}
	ft_restore_stack_order(a, b, ra_cnt, min_val);
	ft_pa_half(a, b, min_val, pivot);
	ft_pb_half(a, b, pivot + 1, max_val);
}
