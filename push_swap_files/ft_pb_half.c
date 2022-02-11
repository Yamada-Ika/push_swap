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

#include "push_swap.h"

#include "order.h"
#include "sort_utils.h"

// static void	ft_sort_left_in_a(t_stack *a, int a_size)
static void	ft_sort_left_in_a(t_push_swap *psw, int a_size)
{
	if (a_size == 1)
		ft_ra(psw->a, psw->order_list);
	if (a_size == 2)
	{
		if (psw->a->back->val > psw->a->back->back->val)
			ft_sa(psw->a, psw->order_list);
		ft_ra(psw->a, psw->order_list);
		ft_ra(psw->a, psw->order_list);
	}
}

// static void	ft_restore_stack_order(t_stack *a, t_stack *b, int cnt, int min_val)
static void	ft_restore_stack_order(t_push_swap *psw, int cnt, int min_val)
{
	while (cnt-- > 0 && min_val)
	{
		if (psw->b->back->val != min_val)
			ft_rrr(psw->a, psw->b, psw->order_list);
		else
			ft_rra(psw->a, psw->order_list);
	}
}

// void	ft_pb_half(t_stack *a, t_stack *b, int min_val, int max_val)
void	ft_pb_half(t_push_swap *psw, int min_val, int max_val)
{
	int	pivot;
	int	ra_cnt;
	int	a_size;

	a_size = max_val - min_val + 1;
	if (a_size <= 2)
		return (ft_sort_left_in_a(psw, a_size));
	pivot = (max_val - min_val) / 2 + min_val;
	ra_cnt = 0;
	while (a_size-- > 0)
	{
		if (psw->a->back->val <= pivot)
			ft_pb(psw->a, psw->b, psw->order_list);
		else
		{
			if (psw->b->back->val != min_val)
				ft_rr(psw->a, psw->b, psw->order_list);
			else
				ft_ra(psw->a, psw->order_list);
			ra_cnt++;
		}
	}
	// ft_restore_stack_order(psw->a, psw->b, ra_cnt, min_val);
	ft_restore_stack_order(psw, ra_cnt, min_val);
	// ft_pa_half(psw->a, psw->b, min_val, pivot);
	ft_pa_half(psw, min_val, pivot);
	ft_pb_half(psw, pivot + 1, max_val);
}
