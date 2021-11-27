/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:06 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/27 00:47:23 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_arg_correct(int argc, char *argv[])
{
	if (argc < 2)
		return (0);
	return (1);
}

int	*ft_get_intarray_from_arg(int argc, char *argv[])
{
	size_t	array_size;
	size_t	i;
	int		*array;

	array_size = (size_t)argc - 1;
	array = (int *)malloc(array_size * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < array_size)
	{
		array[i] = atoi(argv[i + 1]);
		i++;
	}
	return (array);
}

void	ft_three(t_bilist *stack_a)
{
	int	values[3];

	if (ft_is_sorted_bilist(stack_a))
		return ;
	values[0] = stack_a->front->value;
	values[1] = stack_a->front->front->value;
	values[2] = stack_a->back->value;
	if (values[2] > values[1] && values[1] < values[0] && values[2] < values[0])
		ft_sa(stack_a);
	else if (values[2] > values[1] && values[1] > values[0])
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (values[2] > values[1] && values[1] < values[0] && values[2] > values[0])
		ft_ra(stack_a);
	else if (values[2] < values[1] && values[1] > values[0] && values[2] < values[0])
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else
		ft_rra(stack_a);
}

void	ft_five(t_bilist *stack_a, t_bilist *stack_b)
{
	ft_pb_minimum_element(stack_a, stack_b);
	ft_pb_minimum_element(stack_a, stack_b);
	ft_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_bigger(t_bilist *stack_a, t_bilist *stack_b)
{
	int	stack_a_size = ft_get_bilist_element(stack_a);
	int i;

	i = 0;
	while (i < stack_a_size)
	{
		ft_pb_minimum_element(stack_a, stack_b);
		i++;
	}
	i = 0;
	while (i < stack_a_size)
	{
		ft_pa(stack_a, stack_b);
		i++;
	}
}

void	push_swap(t_bilist *stack_a, t_bilist *stack_b)
{
	int	element_count;

	if (ft_is_sorted_bilist(stack_a))
		return ;
	element_count = ft_get_bilist_element(stack_a);
	if (element_count == 3)
		ft_three(stack_a);
	else if (element_count == 5)
		ft_five(stack_a, stack_b);
	else
		ft_bigger(stack_a, stack_b);
	// ft_print_stacks(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_bilist	*stack_a;
	t_bilist	*stack_b;
	int			*array;
	size_t		array_size;

	if (ft_is_arg_correct(argc, argv) != 1)
	{
		printf("Error\n");
		return (-1);
	}
	array = ft_get_intarray_from_arg(argc, argv);
	if (array == NULL)
	{
		printf("Error\n");
		return (-1);
	}
	array_size = (size_t)argc - 1;
	stack_a = ft_create_stack(array, array_size);
	stack_b = ft_create_stack(NULL, 0);
	push_swap(stack_a, stack_b);
	ft_delete_stack(stack_a);
	ft_delete_stack(stack_b);
}
