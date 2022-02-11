/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:10:40 by iyamada           #+#    #+#             */
/*   Updated: 2022/02/12 04:39:41 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

static void	ft_sort_three_helper(t_push_swap *psw, int bottm, int centr, int top)
{
	if (top > centr && centr < bottm && top < bottm)
		ft_sa(psw->a, psw->order_list);
	else if (top > centr && centr > bottm)
	{
		ft_sa(psw->a, psw->order_list);
		ft_rra(psw->a, psw->order_list);
	}
	else if (top > centr && centr < bottm && top > bottm)
		ft_ra(psw->a, psw->order_list);
	else if (top < centr && centr > bottm && top < bottm)
	{
		ft_sa(psw->a, psw->order_list);
		ft_ra(psw->a, psw->order_list);
	}
	else
		ft_rra(psw->a, psw->order_list);
}

void	ft_sort_three(t_push_swap *psw)
{
	int	bottm;
	int	centr;
	int	top;

	if (ft_is_sorted(psw->a))
		return ;
	bottm = psw->a->front->val;
	centr =psw-> a->front->front->val;
	top = psw->a->back->val;
	ft_sort_three_helper(psw, bottm, centr, top);
}

void	ft_sort_below_five(t_push_swap *psw, int a_size)
{
	int	pb_cnt;
	int	now_a_size;

	pb_cnt = 0;
	now_a_size = a_size;
	while (now_a_size-- > 3)
	{
		ft_pb_min_val(psw);
		pb_cnt++;
	}
	ft_sort_three(psw);
	while (pb_cnt-- > 0)
		ft_pa(psw->a, psw->b, psw->order_list);
}
