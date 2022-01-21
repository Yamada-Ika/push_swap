/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:33:14 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/22 00:16:33 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_frees(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

size_t	ft_get_size(char **argv)
{
	char	**strs;
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		strs = ft_split(argv[i], ' ');
		j = 0;
		while (strs[j] != NULL)
		{
			size++;
			j++;
		}
		ft_frees(strs);
		i++;
	}
	return (size);
}
