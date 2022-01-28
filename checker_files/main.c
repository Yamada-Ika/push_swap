/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:40:35 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/28 22:30:57 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#include <stdio.h>


int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*arry;
	int		size;

	if (argc == 1)
		return (0);
	if (ft_is_wrong_arry(argv))
	{
		fprintf(stderr, "here?\n");
		ft_error("Error", ARG_ERROR);
	}
	arry = ft_get_arry_from_arg(argv);
	if (arry == NULL)
	{
		fprintf(stderr, "here?\n");
		ft_error("Error", MEM_ERROR);
	}
	size = ft_get_size(argv);;
	a = ft_new_stack(arry, size);
	b = ft_new_stack(NULL, 0);
	free(arry);
	ft_get_operation(a, b);
	if (ft_is_sorted(a) && ft_get_stack_size(b) == 0)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_delete_stack(a);
	ft_delete_stack(b);
	return (0);
}
