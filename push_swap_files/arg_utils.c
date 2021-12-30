/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:13:56 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 14:12:10 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_is_exist(int *arry, int size, long long val)
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

static bool	ft_is_wrong_arry(int argc, char *argv[])
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
	if (ft_is_wrong_arry(argc, argv))
		return (true);
	return (false);
}
