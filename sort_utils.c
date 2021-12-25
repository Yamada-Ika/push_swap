/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:35:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 01:42:27 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three(t_bilist *stack_a)
{
	int	vals[3];

	if (ft_is_sorted_bilist(stack_a))
		return ;
	vals[0] = stack_a->front->value;
	vals[1] = stack_a->front->front->value;
	vals[2] = stack_a->back->value;
	if (vals[2] > vals[1] && vals[1] < vals[0] && vals[2] < vals[0])
		ft_sa(stack_a);
	else if (vals[2] > vals[1] && vals[1] > vals[0])
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (vals[2] > vals[1] && vals[1] < vals[0] && vals[2] > vals[0])
		ft_ra(stack_a);
	else if (vals[2] < vals[1] && vals[1] > vals[0] && vals[2] < vals[0])
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else
		ft_rra(stack_a);
}

void	ft_under_six(t_bilist *stack_a, t_bilist *stack_b, int stack_a_size)
{
	int	pb_count;

	pb_count = 0;
	while (stack_a_size - pb_count > 3)
	{
		ft_pb_minimum_element(stack_a, stack_b);
		pb_count++;
	}
	ft_three(stack_a);
	while (pb_count > 0)
	{
		ft_pa(stack_a, stack_b);
		pb_count--;
	}
}

void	ft_join_sorted_b_to_end_a(t_bilist *stack_a, t_bilist *stack_b, int stack_b_size)
{
	int	i;
	int	j;
	int	tmp_b_size;
	int	min_value = ft_get_minimum_value_from_stack(stack_b);
	int	next_min_value;
	bool	is_min_value_in_stack_b;

	tmp_b_size = stack_b_size;
	i = 0;
	while (i < stack_b_size)
	{
		is_min_value_in_stack_b = ft_is_value_in_stack(stack_b, min_value);
		next_min_value = min_value + 1;
		j = 0;
		while (j < tmp_b_size && is_min_value_in_stack_b)
		{
			if (min_value == stack_b->back->value)
			{
				ft_pa(stack_a, stack_b);
				break ;
			}
			if (stack_a->back->value > stack_b->back->value)
			{
				ft_pa(stack_a, stack_b);
				tmp_b_size--;
			}
			else
			{
				ft_rb(stack_b);
				j++;
			}
		}
		min_value = next_min_value;
		ft_ra(stack_a);
		i++;
	}
}

void	ft_sort_left_in_a(t_bilist *stack_a, t_bilist *stack_b, int stack_a_size)
{
	if (stack_a_size == 1)
		ft_ra(stack_a);
	if (stack_a_size == 2)
	{
		if (stack_a->back->value > stack_a->back->back->value)
			ft_sa(stack_a);
		ft_ra(stack_a);
		ft_ra(stack_a);
	}
}

void	ft_send_half_to_a(t_bilist *stack_a, t_bilist *stack_b, int stack_b_min_val, int stack_b_max_val)
{
	int	pa_count;
	int	pivot;
	int	stack_b_size;

	stack_b_size = stack_b_max_val - stack_b_min_val + 1;
	if (stack_b_size <= 20)
		return ft_join_sorted_b_to_end_a(stack_a, stack_b, stack_b_size);
	pa_count = 0;
	pivot = (stack_b_max_val - stack_b_min_val) / 2 + stack_b_min_val;
	while (stack_b_size > 0)
	{
		if (stack_b->back->value == stack_b_min_val)
		{
			ft_pa(stack_a, stack_b);
			ft_ra(stack_a);
			stack_b_min_val++;
		}
		else if (stack_b->back->value > pivot)
		{
			ft_pa(stack_a, stack_b);
			pa_count++;
		}
		else
			ft_rb(stack_b);
		stack_b_size--;
	}
	ft_send_half_to_a(stack_a, stack_b, stack_b_min_val, pivot);
	while (pa_count > 0)
	{
		if (stack_a->back->value + 1 == stack_a->front->value)
			ft_ra(stack_a);
		else
			ft_pb(stack_a, stack_b);
		pa_count--;
	}
	ft_send_half_to_a(stack_a, stack_b, pivot + 1, stack_b_max_val);
}

void	ft_send_half_to_b(t_bilist *stack_a, t_bilist *stack_b, int stack_a_min_val, int stack_a_max_val)
{
	int	pivot;
	int	ra_count;
	int	stack_a_size;

	stack_a_size = stack_a_max_val - stack_a_min_val + 1;
	if (stack_a_size <= 2)
		return ft_sort_left_in_a(stack_a, stack_b, stack_a_size);
	ra_count = 0;
	pivot = (stack_a_max_val - stack_a_min_val) / 2 + stack_a_min_val;
	while (stack_a_size-- > 0)
	{
		if (stack_a->back->value <= pivot)
			ft_pb(stack_a, stack_b);
		else
		{
			if (stack_b->back->value != stack_a_min_val)
				ft_rr(stack_a, stack_b);
			else
				ft_ra(stack_a);
			ra_count++;
		}
	}
	while (ra_count-- > 0 && stack_a_min_val)
	{
		if (stack_b->back->value != stack_a_min_val)
			ft_rrr(stack_a, stack_b);
		else
			ft_rra(stack_a);
	}
	ft_send_half_to_a(stack_a, stack_b, stack_a_min_val, pivot);
	ft_send_half_to_b(stack_a, stack_b, pivot + 1, stack_a_max_val);
}