/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:13:56 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 01:28:12 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_already_exist(int *array, int size, long long val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == val)
			return (true);
		i++;
	}
	return (false);
}

bool	ft_is_wrong_array(int argc, char *argv[])
{
	int		*array;
	int		array_size;
	int		i;
	char	*non_num;

	array_size = argc - 1;
	array = (int *)malloc(array_size * sizeof(long long));
	i = 0;
	while (i < array_size)
	{
		array[i] = strtoll(argv[i + 1], &non_num, 10);
		if (strcmp(non_num, "") || array[i] > INT_MAX || array[i] < INT_MIN)
			return (true);
		if (ft_is_already_exist(array, i, array[i]))
			return (true);
		i++;
	}
	return (false);
}

bool	ft_is_wrong_arg(int argc, char *argv[])
{
	if (argc == 1)
		return (true);
	if (ft_is_wrong_array(argc, argv))
		return (true);
	return (false);
}
