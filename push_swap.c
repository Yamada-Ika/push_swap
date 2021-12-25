/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:06 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 01:36:01 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_bilist *stack_a, t_bilist *stack_b)
{
	int	stack_a_size;
	int	min_value_in_a;
	int	max_value_in_a;

	if (ft_is_sorted_bilist(stack_a))
		return ;
	stack_a_size = ft_get_bilist_element(stack_a);
	if (stack_a_size == 2)
		ft_sa(stack_a);
	else if (stack_a_size == 3)
		ft_three(stack_a);
	else if (stack_a_size <= 6)
		ft_under_six(stack_a, stack_b, stack_a_size);
	else
	{
		min_value_in_a = 0;
		max_value_in_a = stack_a_size - 1;
		ft_send_half_to_b(stack_a, stack_b, min_value_in_a, max_value_in_a);
	}
	// ft_print_stacks(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_bilist	*stack_a;
	t_bilist	*stack_b;
	int			*array;
	size_t		array_size;

	if (ft_is_wrong_arg(argc, argv))
	{
		printf("Error\n");
		return (ERROR);
	}
	array = ft_get_array_from_arg(argc, argv);
	if (array == NULL)
	{
		printf("Error\n");
		return (ERROR);
	}
	array_size = (size_t)argc - 1;
	ft_array_compress(array, array_size);
	stack_a = ft_create_stack(array, array_size);
	stack_b = ft_create_stack(NULL, 0);
	push_swap(stack_a, stack_b);
	ft_delete_stack(stack_a);
	ft_delete_stack(stack_b);
	return (0);
}
