/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 02:41:55 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:47:14 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	ft_is_val_in_stack(t_stack *stack, int val)
{
	t_stack	*sentinel;

	sentinel = stack;
	while (true)
	{
		stack = stack->back;
		if (stack == sentinel)
			return (false);
		if (stack->val == val)
			return (true);
	}
}

void	ft_pb_min_val(t_stack *a, t_stack *b)
{
	int	min_val_index;
	int	a_size;
	int	rra_cnt;
	int	ra_cnt;

	min_val_index = ft_get_min_val_at(a);
	a_size = ft_get_stack_size(a);
	if (min_val_index > a_size / 2)
	{
		rra_cnt = a_size - min_val_index;
		while (rra_cnt-- > 0)
			ft_rra(a);
	}
	else
	{
		ra_cnt = min_val_index;
		while (ra_cnt-- > 0)
			ft_ra(a);
	}
	ft_pb(a, b);
}
