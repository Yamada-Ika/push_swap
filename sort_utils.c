/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:35:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 03:50:18 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size_three(t_stack *a)
{
	int	vals[3];

	if (ft_is_sorted(a))
		return ;
	vals[0] = a->front->val;
	vals[1] = a->front->front->val;
	vals[2] = a->back->val;
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

void	ft_size_under_six(t_stack *a, t_stack *b, int a_size)
{
	int	pb_count;

	pb_count = 0;
	while (a_size - pb_count > 3)
	{
		ft_pb_min_val(a, b);
		pb_count++;
	}
	ft_size_three(a);
	while (pb_count > 0)
	{
		ft_pa(a, b);
		pb_count--;
	}
}

void	ft_join_sorted_b_to_end_of_a(t_stack *a, t_stack *b, int b_size)
{
	int	i;
	int	j;
	int	tmp_b_size;
	int	min_val = ft_get_min_val_from_stack(b);
	int	next_min_val;
	bool	is_min_val_in_b;

	tmp_b_size = b_size;
	i = 0;
	while (i < b_size)
	{
		is_min_val_in_b = ft_is_val_in_stack(b, min_val);
		next_min_val = min_val + 1;
		j = 0;
		while (j < tmp_b_size && is_min_val_in_b)
		{
			if (min_val == b->back->val)
			{
				ft_pa(a, b);
				break ;
			}
			if (a->back->val > b->back->val)
			{
				ft_pa(a, b);
				tmp_b_size--;
			}
			else
			{
				ft_rb(b);
				j++;
			}
		}
		min_val = next_min_val;
		ft_ra(a);
		i++;
	}
}

void	ft_sort_left_in_a(t_stack *a, t_stack *b, int a_size)
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

void	ft_send_half_to_a(t_stack *a, t_stack *b, int b_min_val, int b_max_val)
{
	int	pa_count;
	int	pb_count;
	int	pivot;
	int	b_size;

	b_size = b_max_val - b_min_val + 1;
	if (b_size <= 20)
		return ft_join_sorted_b_to_end_of_a(a, b, b_size);
	pa_count = 0;
	pivot = (b_max_val - b_min_val) / 2 + b_min_val;
	while (b_size > 0)
	{
		if (b->back->val == b_min_val)
		{
			ft_pa(a, b);
			ft_ra(a);
			b_min_val++;
		}
		else if (b->back->val > pivot)
		{
			ft_pa(a, b);
			pa_count++;
		}
		else
			ft_rb(b);
		b_size--;
	}
	ft_send_half_to_a(a, b, b_min_val, pivot);
	pb_count = 0;
	while (pa_count > 0)
	{
		if (a->back->val + 1 == a->front->val)
			ft_ra(a);
		else
		{
			ft_pb(a, b);
			pb_count++;
		}
		pa_count--;
	}
	ft_send_half_to_a(a, b, pivot + 1, b_max_val);
}

void	ft_send_half_to_b(t_stack *a, t_stack *b, int a_min_val, int a_max_val)
{
	int	pivot;
	int	ra_count;
	int	a_size;

	a_size = a_max_val - a_min_val + 1;
	if (a_size <= 2)
		return ft_sort_left_in_a(a, b, a_size);
	ra_count = 0;
	pivot = (a_max_val - a_min_val) / 2 + a_min_val;
	while (a_size-- > 0)
	{
		if (a->back->val <= pivot)
			ft_pb(a, b);
		else
		{
			if (b->back->val != a_min_val)
				ft_rr(a, b);
			else
				ft_ra(a);
			ra_count++;
		}
	}
	while (ra_count-- > 0 && a_min_val)
	{
		if (b->back->val != a_min_val)
			ft_rrr(a, b);
		else
			ft_rra(a);
	}
	ft_send_half_to_a(a, b, a_min_val, pivot);
	ft_send_half_to_b(a, b, pivot + 1, a_max_val);
}
