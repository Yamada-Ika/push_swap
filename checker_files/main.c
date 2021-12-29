/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:40:35 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 02:32:50 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include "create_stack.h"
#include "order.h"

void	ft_error(char *fmt, int status)
{
	ft_putendl_fd(fmt, STDERR_FILENO);
	exit(status);
}

bool	ft_is_exist(int *arry, int size, long long val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arry[i] == val)
			return (true);
		i++;
	}
	return (false);
}

bool	ft_is_wrong_arry(int argc, char *argv[])
{
	int		*arry;
	int		arry_size;
	int		i;
	char	*non_num;

	arry_size = argc - 1;
	arry = (int *)malloc(arry_size * sizeof(long long));
	i = 0;
	while (i < arry_size)
	{
		if (ft_strcmp(argv[i + 1], "") == 0)
			return (true);
		arry[i] = ft_strtoll(argv[i + 1], &non_num, 10);
		if (ft_strcmp(non_num, "") || arry[i] > INT_MAX || arry[i] < INT_MIN)
			return (true);
		if (ft_is_exist(arry, i, arry[i]))
			return (true);
		i++;
	}
	free(arry);
	return (false);
}

bool	ft_is_wrong_arg(int argc, char *argv[])
{
	if (argc == 1)
		return (true);
	if (ft_is_wrong_arry(argc, argv))
		return (true);
	return (false);
}

int	*ft_get_arry_from_arg(int argc, char *argv[])
{
	int		*arry;
	int		size;
	int		i;

	size = argc - 1;
	arry = (int *)malloc(size * sizeof(int));
	if (arry == NULL)
		ft_error("Error", MEM_ERROR);
	i = 0;
	while (i < size)
	{
		arry[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arry);
}

bool	ft_is_sorted(t_stack *bilist)
{
	t_stack	*dummy;
	int		prev_val;

	dummy = bilist;
	bilist = bilist->front;
	prev_val = bilist->val;
	while (true)
	{
		bilist = bilist->front;
		if (dummy == bilist)
			break ;
		if (bilist->val > prev_val)
			return (false);
		prev_val = bilist->val;
	}
	return (true);
}

int	ft_get_stack_size(t_stack *stack)
{
	t_stack	*dummy;
	int		size;

	dummy = stack;
	size = 0;
	while (true)
	{
		stack = stack->front;
		if (stack == dummy)
			break ;
		size++;
	}
	return (size);
}

void	ft_get_operation_helper(t_stack *a, t_stack *b, char op[5])
{
	if (ft_strcmp(op, "sa\n") == 0)
		ft_sa(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		ft_sb(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ft_ss(a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ft_ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		ft_rb(b);
	else if (ft_strcmp(op, "rr\n") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		ft_rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		ft_rrb(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		ft_rrr(a, b);
	else
		ft_error("Error", OP_ERROR);
}

void	ft_get_operation(t_stack *a, t_stack *b)
{
	char	op[5];
	ssize_t	op_len;

	while (true)
	{
		op_len = read(STDIN_FILENO, op, 5);
		if (op_len == 0)
			return ;
		op[op_len] = '\0';
		ft_get_operation_helper(a, b, op);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*arry;
	int		size;

	if (ft_is_wrong_arg(argc, argv))
		ft_error("Error", ARG_ERROR);
	arry = ft_get_arry_from_arg(argc, argv);
	if (arry == NULL)
		ft_error("Error", MEM_ERROR);
	size = argc - 1;
	a = ft_new_stack(arry, size);
	b = ft_new_stack(NULL, 0);
	ft_get_operation(a, b);
	if (ft_is_sorted(a) && ft_get_stack_size(b) == 0)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_error("KO", SORT_ERROR);
	return (0);
}
