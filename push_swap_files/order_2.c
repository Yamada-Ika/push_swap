/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:04:32 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 01:21:57 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"
#include "order_helper.h"

void	ft_rb(t_stack *b)
{
	ft_putendl_fd("rb", STDOUT_FILENO);
	ft_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_putendl_fd("rr", STDOUT_FILENO);
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(t_stack *a)
{
	ft_putendl_fd("rra", STDOUT_FILENO);
	ft_reverse_rotate(a);
}

void	ft_rrb(t_stack *b)
{
	ft_putendl_fd("rrb", STDOUT_FILENO);
	ft_reverse_rotate(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_putendl_fd("rrr", STDOUT_FILENO);
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
