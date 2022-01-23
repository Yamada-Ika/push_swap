/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arry_from_arg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 23:31:20 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:18:48 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arry_utils.h"

int	*ft_get_arry_from_arg(char **argv)
{
	int			*arry;
	char		**strs;
	size_t		i;
	size_t		j;
	size_t		k;

	arry = (int *)malloc(ft_get_size(argv) * sizeof(int));
	if (arry == NULL)
		return (NULL);
	i = 0;
	j = 1;
	while (argv[j] != NULL)
	{
		strs = ft_split2(argv[j], ' ');
		k = 0;
		while (strs[k] != NULL)
		{
			arry[i] = ft_atoi(strs[k]);
			i++;
			k++;
		}
		ft_frees(strs);
		j++;
	}
	return (arry);
}
