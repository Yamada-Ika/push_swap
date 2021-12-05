/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:06 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/05 14:51:57 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_join_sorted_b_to_end_a(t_bilist *stack_a, t_bilist *stack_b, int stack_b_size)
{
	int	i;
	int	j;
	int	tmp_b_size;
	int	min_value = ft_get_minimum_value_from_stack(stack_b);
	int	next_min_value;
	bool	is_min_value_in_stack_b;

	tmp_b_size = stack_b_size;
	i = 0;
	while (i < stack_b_size)
	{
		// ft_print_stacks(stack_a, stack_b);
		// ft_pa_minimum_element(stack_a, stack_b);
		// printf("min_value : %d\n", min_value);
		is_min_value_in_stack_b = ft_is_value_in_stack(stack_b, min_value);
		// printf("is_min_value_in_stack_b : %d\n", is_min_value_in_stack_b);
		next_min_value = min_value + 1;
		j = 0;
		while (j < tmp_b_size && is_min_value_in_stack_b)
		{
			if (min_value == stack_b->back->value)
			{
				ft_pa(stack_a, stack_b);
				break ;
			}
			if (stack_a->back->value > stack_b->back->value)
			{
				ft_pa(stack_a, stack_b);
				tmp_b_size--;
			}
			else
			{
				ft_rb(stack_b);
				j++;
			}
		}
		min_value = next_min_value;
		ft_ra(stack_a);
		i++;
	}
}

void	ft_send_half_to_a(t_bilist *stack_a, t_bilist *stack_b, int stack_b_size)
{
	int	i;
	int	stack_a_size;
	int	pivot;
	int	b_size_after_pa;

	if (stack_b_size <= 20)
	{
		ft_join_sorted_b_to_end_a(stack_a, stack_b, stack_b_size);
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
	ft_array_compress(array, array_size);
	stack_a = ft_create_stack(array, array_size);
	stack_b = ft_create_stack(NULL, 0);
	push_swap(stack_a, stack_b);
	ft_delete_stack(stack_a);
	ft_delete_stack(stack_b);
}
