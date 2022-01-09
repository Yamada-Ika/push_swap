/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:06 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/10 01:26:11 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	int	a_size;

	if (ft_is_sorted(a))
		return ;
	a_size = ft_get_stack_size(a);
	if (a_size == 1)
		return ;
	if (a_size == 2)
		ft_sa(a);
	else if (a_size == 3)
		ft_sort_three(a);
	else if (a_size <= 5)
		ft_sort_below_five(a, b, a_size);
	else
		ft_pb_half(a, b, 0, a_size - 1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*arry;
	int		size;

	if (argc == 1)
		return (0);
	if (ft_is_wrong_arry(argc, argv))
		ft_error("Error", ARG_ERROR);
	arry = ft_get_arry_from_arg(argc, argv);
	if (arry == NULL)
		ft_error("Error", MEM_ERROR);
	size = argc - 1;
	ft_arry_compress(arry, size);
	a = ft_new_stack(arry, size);
	b = ft_new_stack(NULL, 0);
	free(arry);
	push_swap(a, b);
	ft_delete_stack(a);
	ft_delete_stack(b);
	return (0);
}
