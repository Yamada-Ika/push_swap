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

int	*ft_get_arry_from_arg(int argc, char *argv[])
{
	int		arry_size;
	int		i;
	int		*arry;
	char	*end;

	arry_size = argc - 1;
	arry = (int *)malloc(arry_size * sizeof(int));
	if (arry == NULL)
		ft_error("Error\n");
	i = 0;
	while (i < arry_size)
	{
		arry[i] = strtoll(argv[i + 1], &end, 10);
		i++;
	}
	return (arry);
}

int	ft_get_rank_from_arry(int *sorted_arry, int size, int element)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arry[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_sort_ascending_order(int *arry, int size)
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

int	*ft_copy_arry(int *copied_arry, int size)
{
	int	i;
	int	*new_arry;

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
	int	i;
	int	rank;
	int	*sorted_arry;

	sorted_arry = ft_copy_arry(arry, size);
	if (sorted_arry == NULL)
		ft_error("Error\n");
	ft_sort_ascending_order(sorted_arry, size);
	i = 0;
	while (i < size)
	{
		rank = ft_get_rank_from_arry(sorted_arry, size, arry[i]);
		arry[i] = rank;
		i++;
	}
}
