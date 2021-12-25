/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:39:11 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 05:08:36 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"
#include "order_helper.h"

void	ft_sa(t_stack *a)
{
	printf("sa\n");
	ft_swap(a);
}

void	ft_pa(t_stack *a, t_stack *b)
{
	printf("pa\n");
	ft_push(a, b);
}

void	ft_pb(t_stack *a, t_stack *b)
{
	printf("pb\n");
	ft_push(b, a);
}

void	ft_ra(t_stack *a)
{
	printf("ra\n");
	ft_rotate(a);
}

void	ft_rb(t_stack *b)
{
	printf("rb\n");
	ft_rotate(b);
}
