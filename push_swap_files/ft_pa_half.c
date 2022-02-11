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

#include "push_swap.h"

#include "order.h"
#include "sort_utils.h"

static void	ft_join_a_helper(t_push_swap *psw, int min_val, int size)
{
	int	j;

	j = 0;
	while (j < size && ft_is_val_in_stack(psw->b, min_val))
	{
		if (min_val == psw->b->back->val)
		{
			ft_pa(psw->a, psw->b, psw->order_list);
			break ;
		}
		if (psw->a->back->val > psw->b->back->val)
		{
			ft_pa(psw->a, psw->b, psw->order_list);
			size--;
		}
		else
		{
			ft_rb(psw->b, psw->order_list);
			j++;
		}
	}
}

// static void	ft_join_a(t_stack *a, t_stack *b, int min_val, int size)
static void	ft_join_a(t_push_swap *psw, int min_val, int size)
{
	int	tmp_size;
	int	next_min_val;

	tmp_size = size;
	while (size-- > 0)
	{
		next_min_val = min_val + 1;
		ft_join_a_helper(psw, min_val, tmp_size);
		min_val = next_min_val;
		ft_ra(psw->a, psw->order_list);
	}
}

// static void	ft_move_to_b(t_stack *a, t_stack *b, int pa_cnt)
static void	ft_move_to_b(t_push_swap *psw, int pa_cnt)
{
	while (pa_cnt-- > 0)
	{
		if (!ft_is_sentinel(psw->a) && psw->a->back->val + 1 == psw->a->front->val)
			ft_ra(psw->a, psw->order_list);
		else
			ft_pb(psw->a, psw->b, psw->order_list);
	}
}

// static int	ft_pa_half_helper(t_stack *a, t_stack *b, int *min_val, int max_val)
static int	ft_pa_half_helper(t_push_swap *psw, int *min_val, int max_val)
{
	int	pivot;
	int	pa_cnt;
	int	b_size;

	b_size = max_val - *min_val + 1;
	pa_cnt = 0;
	pivot = (max_val - *min_val) / 2 + *min_val;
	while (b_size-- > 0)
	{
		if (psw->b->back->val == *min_val)
		{
			ft_pa(psw->a, psw->b, psw->order_list);
			ft_ra(psw->a, psw->order_list);
			(*min_val)++;
		}
		else if (psw->b->back->val > pivot)
		{
			ft_pa(psw->a, psw->b, psw->order_list);
			pa_cnt++;
		}
		else
			ft_rb(psw->b, psw->order_list);
	}
	return (pa_cnt);
}

// void	ft_pa_half(t_stack *a, t_stack *b, int min_val, int max_val)
void	ft_pa_half(t_push_swap *psw, int min_val, int max_val)
{
	int	pa_cnt;
	int	pivot;
	int	b_size;

	b_size = max_val - min_val + 1;
	if (b_size <= 20)
		return (ft_join_a(psw, min_val, b_size));
	pa_cnt = 0;
	pivot = (max_val - min_val) / 2 + min_val;
	pa_cnt = ft_pa_half_helper(psw, &min_val, max_val);
	ft_pa_half(psw, min_val, pivot);
	ft_move_to_b(psw, pa_cnt);
	ft_pa_half(psw, pivot + 1, max_val);
}
