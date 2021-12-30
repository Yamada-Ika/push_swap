/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:36:03 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 17:06:41 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op_utils.h"

void	ft_sa(t_stack *a)
{
	ft_swap(a);
}

void	ft_sb(t_stack *b)
{
	ft_swap(b);
}

void	ft_ss(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_push(a, b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_push(b, a);
}
