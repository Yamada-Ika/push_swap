/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:04:32 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 05:08:40 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "order.h"
#include "order_helper.h"

void	ft_rr(t_stack *a, t_stack *b)
{
	printf("rr\n");
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rra(t_stack *a)
{
	printf("rra\n");
	ft_reverse_rotate(a);
}

void	ft_rrb(t_stack *b)
{
	printf("rrb\n");
	ft_reverse_rotate(b);
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	printf("rrr\n");
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}
