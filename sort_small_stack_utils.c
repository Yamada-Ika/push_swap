/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:10:40 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/28 22:59:05 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

static void ft_sort_three_helper(t_stack *a, int vals[3])
{
	if (vals[2] > vals[1] && vals[1] < vals[0] && vals[2] < vals[0])
		ft_sa(a);
	else if (vals[2] > vals[1] && vals[1] > vals[0])
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (vals[2] > vals[1] && vals[1] < vals[0] && vals[2] > vals[0])
		ft_ra(a);
	else if (vals[2] < vals[1] && vals[1] > vals[0] && vals[2] < vals[0])
	{
		ft_sa(a);
		ft_ra(a);
	}
	else
		ft_rra(a);
}

void	ft_sort_three(t_stack *a)
{
	int	vals[3];

	if (ft_is_sorted(a))
		return ;
	vals[0] = a->front->val;
	vals[1] = a->front->front->val;
	vals[2] = a->back->val;
	// ft_sort_three_helper(a, vals);
	if (vals[2] > vals[1] && vals[1] < vals[0] && vals[2] < vals[0])
		ft_sa(a);
	else if (vals[2] > vals[1] && vals[1] > vals[0])
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (vals[2] > vals[1] && vals[1] < vals[0] && vals[2] > vals[0])
		ft_ra(a);
	else if (vals[2] < vals[1] && vals[1] > vals[0] && vals[2] < vals[0])
	{
		ft_sa(a);
		ft_ra(a);
	}
	else
		ft_rra(a);
}

void	ft_sort_under_six(t_stack *a, t_stack *b, int a_size)
{
	int	pb_cnt;
	int	now_a_size;

	pb_cnt = 0;
	now_a_size = a_size;
	while (now_a_size-- > 3)
	{
		ft_pb_min_val(a, b);
		pb_cnt++;
	}
	ft_sort_three(a);
	while (pb_cnt-- > 0)
		ft_pa(a, b);
}