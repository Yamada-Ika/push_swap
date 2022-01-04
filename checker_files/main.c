/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:40:35 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/04 12:23:10 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*arry;
	int		size;

	if (argc == 1)
		return (0);
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
		ft_putendl_fd("KO", STDOUT_FILENO);
	return (0);
}
