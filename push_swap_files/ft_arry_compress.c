/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:24:28 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 01:31:23 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_get_rank_from_arry(int *arry, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arry[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_sort_ascending_order(int *arry, int size)
{
	bool	is_swap;
	int		tmp;
	int		i;

	while (true)
	{
		i = 0;
		is_swap = 0;
		while (i < size - 1)
		{
			if (arry[i] > arry[i + 1])
			{
				tmp = arry[i];
				arry[i] = arry[i + 1];
				arry[i + 1] = tmp;
				is_swap = true;
			}
			i++;
		}
		if (is_swap == false)
			break ;
	}
}

static int	*ft_copy_arry(int *copied_arry, int size)
{
	int	*new_arry;
	int	i;

	new_arry = (int *)malloc(size * sizeof(int));
	if (new_arry == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_arry[i] = copied_arry[i];
		i++;
	}
	return (new_arry);
}

void	ft_arry_compress(int *arry, int size)
{
	int	*sorted_arry;
	int	i;

	sorted_arry = ft_copy_arry(arry, size);
	if (sorted_arry == NULL)
	{
		ft_error("Error");
		exit(1);
	}
	ft_sort_ascending_order(sorted_arry, size);
	i = 0;
	while (i < size)
	{
		arry[i] = ft_get_rank_from_arry(sorted_arry, size, arry[i]);
		i++;
	}
	free(sorted_arry);
}
