/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:30:18 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/10 01:10:55 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "macro.h"
#include "error.h"

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

bool	ft_is_wrong_arry(int argc, char *argv[])
{
	long long	*arry;
	int			arry_size;
	int			i;
	char		*end;
	bool		is_wrong;

	is_wrong = false;
	arry_size = argc - 1;
	arry = (long long *)malloc(arry_size * sizeof(long long));
	i = 0;
	while (i < arry_size)
	{
		arry[i] = ft_strtoll(argv[i + 1], &end, 10);
		if (ft_strcmp(argv[i + 1], "\0") == 0 || ft_strcmp(end, "") != 0
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

int	*ft_get_arry_from_arg(int argc, char *argv[])
{
	int		*arry;
	int		size;
	int		i;

	size = argc - 1;
	arry = (int *)malloc(size * sizeof(int));
	if (arry == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arry[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (arry);
}
