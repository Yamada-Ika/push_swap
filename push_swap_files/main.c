/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:06 by iyamada           #+#    #+#             */
/*   Updated: 2022/02/12 04:41:08 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	push_swap(t_stack *a, t_stack *b)
static void	push_swap(t_push_swap *psw)
{
	int	a_size;

	if (ft_is_sorted(psw->a))
		return ;
	a_size = ft_get_stack_size(psw->a);
	if (a_size == 1)
		return ;
	if (a_size == 2)
		ft_sa(psw->a, psw->order_list);
	else if (a_size == 3)
		ft_sort_three(psw);
	else if (a_size <= 5)
		ft_sort_below_five(psw, a_size);
	else
	{
		ft_pb_half(psw, 0, a_size - 1);
	}
		// ft_pb_half(psw->a, psw->b, 0, a_size - 1);
}

void	print_order_list(t_order_list *order_list)
{
	t_order_list	*dummy;

	ft_putendl_fd("start print_order_list", STDOUT_FILENO);
	dummy = order_list;
	while (true)
	{
		order_list = order_list->next;
		if (order_list == dummy)
			break ;
		if (order_list->order_kind == ORDER_SA)
			ft_putendl_fd("sa", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_SB)
			ft_putendl_fd("sb", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_SS)
			ft_putendl_fd("ss", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_PA)
			ft_putendl_fd("pa", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_PB)
			ft_putendl_fd("pb", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_RA)
			ft_putendl_fd("ra", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_RB)
			ft_putendl_fd("rb", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_RR)
			ft_putendl_fd("rr", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_RRA)
			ft_putendl_fd("rra", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_RRB)
			ft_putendl_fd("rrb", STDOUT_FILENO);
		if (order_list->order_kind == ORDER_RRR)
			ft_putendl_fd("rrr", STDOUT_FILENO);
	}
	ft_putendl_fd("end print_order_list", STDOUT_FILENO);
}

int	main(int argc, char *argv[])
{
	t_push_swap	psw;
	// t_stack		*a;
	// t_stack		*b;
	int			*arry;
	int			size;

	if (argc == 1)
		return (0);
	if (ft_is_wrong_arry(argv))
		return (ft_error("Error"));
	arry = ft_get_arry_from_arg(argv);
	if (arry == NULL)
		return (ft_error("Error"));
	size = ft_get_size(argv);
	ft_arry_compress(arry, size);
	// a = ft_new_stack(arry, size);
	// b = ft_new_stack(NULL, 0);
	psw.a = ft_new_stack(arry, size);
	psw.b = ft_new_stack(NULL, 0);
	psw.order_list = (t_order_list *)ft_calloc(1, sizeof(t_order_list));
	psw.order_list->next = psw.order_list;
	psw.order_list->prev = psw.order_list;
	if (psw.a == NULL || psw.b == NULL)
		return (ft_error("Error"));
	free(arry);
	// push_swap(psw.a, psw.b);
	push_swap(&psw);
	ft_delete_stack(psw.a);
	ft_delete_stack(psw.b);
	print_order_list(psw.order_list);
	return (0);
}
