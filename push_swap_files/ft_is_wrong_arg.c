/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_wrong_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:13:56 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/09 23:54:52 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../libft/libft.h"

static bool	ft_is_exist(long long *arry, int size, long long val)
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

bool	ft_is_wrong_arry(int n, char **strs)
{
	long long	*arry;
	int			arry_size;
	int			i;
	char		*end;
	bool		is_wrong;

	is_wrong = false;
	arry_size = n - 1;
	arry = (long long *)malloc(arry_size * sizeof(long long));
	i = 0;
	while (i < arry_size)
	{
		arry[i] = ft_strtoll(strs[i + 1], &end, 10);
		if (ft_strcmp(strs[i + 1], "\0") == 0 || ft_strcmp(end, "") != 0
			|| arry[i] > INT_MAX || arry[i] < INT_MIN
			|| ft_is_exist(arry, i, arry[i]))
		{
			is_wrong = true;
			break ;
		}
		i++;
	}
	free(arry);
	return (is_wrong);
}
