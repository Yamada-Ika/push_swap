/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_wrong_arry.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:13:56 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:18:50 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arry_utils.h"

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

static bool	_ft_is_wrong_arry_helper(char **strs, size_t *i, long long *arry)
{
	char	*end;
	size_t	k;

	k = 0;
	while (strs[k] != NULL)
	{
		arry[*i] = ft_strtoll(strs[k], &end, 10);
		if (ft_strcmp(strs[k], "\0") == 0 || ft_strcmp(end, "") != 0
			|| arry[*i] > INT_MAX || arry[*i] < INT_MIN
			|| ft_is_exist(arry, *i, arry[*i]))
			return (true);
		(*i)++;
		k++;
	}
	return (false);
}

bool	ft_is_wrong_arry(char **argv)
{
	long long	*arry;
	char		**strs;
	size_t		i;
	size_t		j;

	arry = (long long *)malloc(ft_get_size(argv) * sizeof(long long));
	i = 0;
	j = 1;
	while (argv[j] != NULL)
	{
		strs = ft_split2(argv[j], ' ');
		if (_ft_is_wrong_arry_helper(strs, &i, arry))
			return (true);
		ft_frees(strs);
		j++;
	}
	free(arry);
	return (false);
}
