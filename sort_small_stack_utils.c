/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:10:40 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/29 12:26:26 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

static void	ft_sort_three_helper(t_stack *a, int bottm, int centr, int top)
{
	if (top > centr && centr < bottm && top < bottm)
		ft_sa(a);
	else if (top > centr && centr > bottm)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (top > centr && centr < bottm && top > bottm)
		ft_ra(a);
	else if (top < centr && centr > bottm && top < bottm)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else
		ft_rra(a);
}

void	ft_sort_three(t_stack *a)
{
	int	bottm;
	int	centr;
	int	top;

	if (ft_is_sorted(a))
		return ;
	bottm = a->front->val;
	centr = a->front->front->val;
	top = a->back->val;
	ft_sort_three_helper(a, bottm, centr, top);
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
