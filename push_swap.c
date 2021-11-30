/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:06 by iyamada           #+#    #+#             */
/*   Updated: 2021/11/30 16:04:54 by iyamada          ###   ########.fr       */
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

void	ft_send_half_to_a(t_bilist *stack_a, t_bilist *stack_b, int stack_b_size)
{
	int	i;
	int	stack_a_size;
	int	pivot;
	int	b_size_after_pa;

	// ft_print_stacks(stack_a, stack_b);
	if (stack_b_size <= 20)
	{
		i = 0;
		while (i < stack_b_size) // aの末尾にソート済み配列をくっつける
		{
			ft_pa_minimum_element(stack_a, stack_b);
			ft_ra(stack_a);
			i++;
		}
		return ;
	}
	i = 0;
	stack_a_size = 0;
	pivot = ft_get_median_from_bilist(stack_b, stack_b_size);
	while (i < stack_b_size)
	{
		if (stack_b->back->value > pivot)
		{
			ft_pa(stack_a, stack_b);
			stack_a_size++;
		}
		else
		{
			ft_rb(stack_b);
		}
		i++;
	}
	b_size_after_pa = stack_b_size - stack_a_size;
	ft_send_half_to_a(stack_a, stack_b, b_size_after_pa);
	i = 0;
	while (i < stack_a_size)
	{
		ft_pb(stack_a, stack_b);
		i++;
	}
	ft_send_half_to_a(stack_a, stack_b, stack_a_size);
}

void	ft_send_half_to_b(t_bilist *stack_a, t_bilist *stack_b, int stack_a_size, int flg)
{
	int	i;
	int	stack_b_size;
	int	pivot;
	int	a_size_left;
	int	ra_count;

	// ft_print_stacks(stack_a, stack_b);
	if (stack_a_size <= 2)
	{
		if (stack_a_size == 1)
			ft_ra(stack_a);
		if (stack_a_size == 2)
		{
			if (stack_a->back->value > stack_a->back->back->value)
				ft_sa(stack_a);
			ft_ra(stack_a);
			ft_ra(stack_a);
		}
		return ;
	}
	i = 0;
	stack_b_size = 0;
	ra_count = 0;
	pivot = ft_get_median_from_bilist(stack_a, stack_a_size);
	while (i < stack_a_size)
	{
		if (stack_a->back->value <= pivot)
		{
			ft_pb(stack_a, stack_b);
			stack_b_size++;
		}
		else
		{
			ft_ra(stack_a);
			ra_count++;
		}
		i++;
	}
	while (ra_count > 0 && flg)
	{
		ft_rra(stack_a);
		ra_count--;
	}
	ft_send_half_to_a(stack_a, stack_b, stack_b_size);
	a_size_left = stack_a_size - stack_b_size;
	ft_send_half_to_b(stack_a, stack_b, a_size_left, 1);
}

void	ft_bigger(t_bilist *stack_a, t_bilist *stack_b)
{
	int	stack_a_size;

	stack_a_size = ft_get_bilist_element(stack_a);
	ft_send_half_to_b(stack_a, stack_b, stack_a_size, 0);
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
