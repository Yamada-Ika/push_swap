/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:35:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/29 18:11:14 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"

static void	ft_join_sorted_b_to_end_of_a(t_stack *a, t_stack *b, int min_val, int size)
{
	int		j;
	int		tmp_size;
	int		next_min_val;

	tmp_size = size;
	while (size-- > 0)
	{
		next_min_val = min_val + 1;
		j = 0;
		while (j < tmp_size && ft_is_val_in_stack(b, min_val))
		{
			if (min_val == b->back->val)
			{
				ft_pa(a, b);
				break ;
			}
			if (a->back->val > b->back->val)
			{
				ft_pa(a, b);
				tmp_size--;
			}
			else
			{
				ft_rb(b);
				j++;
			}
		}
		min_val = next_min_val;
		ft_ra(a);
	}
}

static void	ft_sort_left_in_a(t_stack *a, t_stack *b, int a_size)
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

static void	ft_move_to_b(t_stack *a, t_stack *b, int pa_cnt)
{
	while (pa_cnt-- > 0)
	{
		if (a->back->val + 1 == a->front->val)
			ft_ra(a);
		else
			ft_pb(a, b);
	}
}

static void	ft_send_half_to_a(t_stack *a, t_stack *b, int min_val, int max_val)
{
	int	pa_cnt;
	int	pivot;
	int	b_size;

	b_size = max_val - min_val + 1;
	if (b_size <= 20)
		return (ft_join_sorted_b_to_end_of_a(a, b, min_val, b_size));
	pa_cnt = 0;
	pivot = (max_val - min_val) / 2 + min_val;
	while (b_size-- > 0)
	{
		if (b->back->val == min_val)
		{
			ft_pa(a, b);
			ft_ra(a);
			min_val++;
		}
		else if (b->back->val > pivot)
		{
			ft_pa(a, b);
			pa_cnt++;
		}
		else
			ft_rb(b);
	}
	ft_send_half_to_a(a, b, min_val, pivot);
	ft_move_to_b(a, b, pa_cnt);
	ft_send_half_to_a(a, b, pivot + 1, max_val);
}

static void	ft_restore_stack_order(t_stack *a, t_stack *b, int ra_cnt, int min_val)
{
	while (ra_cnt-- > 0 && min_val)
	{
		if (b->back->val != min_val)
			ft_rrr(a, b);
		else
			ft_rra(a);
	}
}

void	ft_send_half_to_b(t_stack *a, t_stack *b, int min_val, int max_val)
{
	int	pivot;
	int	ra_cnt;
	int	a_size;

	a_size = max_val - min_val + 1;
	if (a_size <= 2)
		return (ft_sort_left_in_a(a, b, a_size));
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
	ft_send_half_to_a(a, b, min_val, pivot);
	ft_send_half_to_b(a, b, pivot + 1, max_val);
}
