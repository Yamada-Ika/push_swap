/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:35:07 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 17:06:28 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"

void	ft_rb(t_stack *b)
{
	ft_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(t_stack *a)
{
	ft_reverse_rotate(a);
}

void	ft_rrb(t_stack *b)
{
	ft_reverse_rotate(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
