/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:39:11 by iyamada           #+#    #+#             */
/*   Updated: 2022/02/12 04:44:27 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "order.h"
#include "order_helper.h"

// void	ft_sa(t_stack *a, t_order)
void	ft_sa(t_stack *a, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putstr_fd("sa\n", STDOUT_FILENO);
	ft_swap(a);
	kind = ORDER_SA;
	ft_add_order_list(order_list, kind);
}

// void	ft_sb(t_stack *b)
void	ft_sb(t_stack *b, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("sb", STDOUT_FILENO);
	ft_swap(b);
	kind = ORDER_SB;
	ft_add_order_list(order_list, kind);
}

// void	ft_pa(t_stack *a, t_stack *b)
void	ft_pa(t_stack *a, t_stack *b, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("pa", STDOUT_FILENO);
	ft_push(a, b);
	kind = ORDER_PA;
	ft_add_order_list(order_list, kind);
}

// void	ft_pb(t_stack *a, t_stack *b)
void	ft_pb(t_stack *a, t_stack *b, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("pb", STDOUT_FILENO);
	ft_push(b, a);
	kind = ORDER_PB;
	ft_add_order_list(order_list, kind);
}

// void	ft_ra(t_stack *a)
void	ft_ra(t_stack *a, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("ra", STDOUT_FILENO);
	ft_rotate(a);
	kind = ORDER_RA;
	ft_add_order_list(order_list, kind);
}
