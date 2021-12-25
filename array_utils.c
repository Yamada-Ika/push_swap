/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 01:24:28 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 01:31:23 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_array_from_arg(int argc, char *argv[])
{
	size_t	array_size;
	size_t	i;
	int		*array;
	char	*end;

	array_size = (size_t)argc - 1;
	array = (int *)malloc(array_size * sizeof(long long));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < array_size)
	{
		array[i] = strtoll(argv[i + 1], &end, 10);
		i++;
	}
	return (array);
}

int	ft_get_rank_from_array(int *sorted_array, int size, int element)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_array[i] == element)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_sort_ascending_order(int *array, int size)
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
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				is_swap = true;
			}
			i++;
		}
		if (is_swap == false)
			break ;
	}
}

int	*ft_copy_array(int *copied_array, int size)
{
	int	i;
	int	*new_array;

	new_array = (int *)malloc(size * sizeof(int));
	if (new_array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_array[i] = copied_array[i];
		i++;
	}
	return (new_array);
}

void	ft_array_compress(int *array, int size)
{
	int	i;
	int	rank;
	int	*sorted_array;

	sorted_array = ft_copy_array(array, size);
	if (sorted_array == NULL)
		return ;
	ft_sort_ascending_order(sorted_array, size);
	i = 0;
	while (i < size)
	{
		rank = ft_get_rank_from_array(sorted_array, size, array[i]);
		array[i] = rank;
		i++;
	}
}
