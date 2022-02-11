/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:04:32 by iyamada           #+#    #+#             */
/*   Updated: 2022/02/12 04:45:06 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "order.h"
#include "order_helper.h"

// void	ft_rb(t_stack *b)
void	ft_rb(t_stack *b, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("rb", STDOUT_FILENO);
	ft_rotate(b);
	kind = ORDER_RB;
	ft_add_order_list(order_list, kind);
}

// void	ft_rr(t_stack *a, t_stack *b)
void	ft_rr(t_stack *a, t_stack *b, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("rr", STDOUT_FILENO);
	ft_rotate(a);
	ft_rotate(b);
	kind = ORDER_RR;
	ft_add_order_list(order_list, kind);
}

// void	ft_rra(t_stack *a)
void	ft_rra(t_stack *a, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("rra", STDOUT_FILENO);
	ft_reverse_rotate(a);
	kind = ORDER_RRA;
	ft_add_order_list(order_list, kind);
}

// void	ft_rrb(t_stack *b)
void	ft_rrb(t_stack *b, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("rrb", STDOUT_FILENO);
	ft_reverse_rotate(b);
	kind = ORDER_RRB;
	ft_add_order_list(order_list, kind);
}

// void	ft_rrr(t_stack *a, t_stack *b)
void	ft_rrr(t_stack *a, t_stack *b, t_order_list *order_list)
{
	t_order_kind	kind;

	ft_putendl_fd("rrr", STDOUT_FILENO);
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	kind = ORDER_RRR;
	ft_add_order_list(order_list, kind);
}
