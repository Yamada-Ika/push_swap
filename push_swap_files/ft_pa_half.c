/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_half.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:35:58 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/29 21:53:36 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"
#include "sort_utils.h"

static void	ft_join_a_helper(t_stack *a, t_stack *b, int min_val, int size)
{
	int	j;

	j = 0;
	while (j < size && ft_is_val_in_stack(b, min_val))
	{
		if (min_val == b->back->val)
		{
			ft_pa(a, b);
			break ;
		}
		if (a->back->val > b->back->val)
		{
			ft_pa(a, b);
			size--;
		}
		else
		{
			ft_rb(b);
			j++;
		}
	}
}

static void	ft_join_a(t_stack *a, t_stack *b, int min_val, int size)
{
	int	tmp_size;
	int	next_min_val;

	tmp_size = size;
	while (size-- > 0)
	{
		next_min_val = min_val + 1;
		ft_join_a_helper(a, b, min_val, tmp_size);
		min_val = next_min_val;
		ft_ra(a);
	}
}

static void	ft_move_to_b(t_stack *a, t_stack *b, int pa_cnt)
{
	while (pa_cnt-- > 0)
	{
		if (!ft_is_sentinel(a) && a->back->val + 1 == a->front->val)
			ft_ra(a);
		else
			ft_pb(a, b);
	}
}

static int	ft_pa_half_helper(t_stack *a, t_stack *b, int *min_val, int max_val)
{
	int	pivot;
	int	pa_cnt;
	int	b_size;

	b_size = max_val - *min_val + 1;
	pa_cnt = 0;
	pivot = (max_val - *min_val) / 2 + *min_val;
	while (b_size-- > 0)
	{
		if (b->back->val == *min_val)
		{
			ft_pa(a, b);
			ft_ra(a);
			(*min_val)++;
		}
		else if (b->back->val > pivot)
		{
			ft_pa(a, b);
			pa_cnt++;
		}
		else
			ft_rb(b);
	}
	return (pa_cnt);
}

void	ft_pa_half(t_stack *a, t_stack *b, int min_val, int max_val)
{
	int	pa_cnt;
	int	pivot;
	int	b_size;

	b_size = max_val - min_val + 1;
	if (b_size <= 20)
		return (ft_join_a(a, b, min_val, b_size));
	pa_cnt = 0;
	pivot = (max_val - min_val) / 2 + min_val;
	pa_cnt = ft_pa_half_helper(a, b, &min_val, max_val);
	ft_pa_half(a, b, min_val, pivot);
	ft_move_to_b(a, b, pa_cnt);
	ft_pa_half(a, b, pivot + 1, max_val);
}
