/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:39:11 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 01:21:52 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"
#include "order_helper.h"

void	ft_sa(t_stack *a)
{
	ft_putendl_fd("sa", STDOUT_FILENO);
	ft_swap(a);
}

void	ft_sb(t_stack *b)
{
	ft_putendl_fd("sb", STDOUT_FILENO);
	ft_swap(b);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	ft_putendl_fd("pa", STDOUT_FILENO);
	ft_push(a, b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	ft_putendl_fd("pb", STDOUT_FILENO);
	ft_push(b, a);
}

void	ft_ra(t_stack *a)
{
	ft_putendl_fd("ra", STDOUT_FILENO);
	ft_rotate(a);
}
