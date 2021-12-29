/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:06 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/29 22:17:00 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *fmt, int status)
{
	ft_putendl_fd(fmt, STDERR_FILENO);
	exit(status);
}

static void	push_swap(t_stack *a, t_stack *b)
{
	int	a_size;
	int	min_val_in_a;
	int	max_val_in_a;

	if (ft_is_sorted(a))
		return ;
	a_size = ft_get_stack_size(a);
	if (a_size == 2)
		ft_sa(a);
	else if (a_size == 3)
		ft_sort_three(a);
	else if (a_size <= 6)
		ft_sort_under_six(a, b, a_size);
	else
	{
		min_val_in_a = 0;
		max_val_in_a = a_size - 1;
		ft_pb_half(a, b, min_val_in_a, max_val_in_a);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*arry;
	int		size;

	if (ft_is_wrong_arg(argc, argv))
		ft_error("Error\n");
	arry = ft_get_arry_from_arg(argc, argv);
	if (arry == NULL)
		ft_error("Error\n");
	size = argc - 1;
	ft_arry_compress(arry, size);
	a = ft_new_stack(arry, size);
	b = ft_new_stack(NULL, 0);
	push_swap(a, b);
	ft_delete_stack(a);
	ft_delete_stack(b);
	return (0);
}
