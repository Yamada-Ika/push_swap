/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilist_utils_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:55:30 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 05:11:15 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "order_helper.h"

int	ft_get_min_val_from_stack(t_stack *bilist)
{
	int		index;
	int		minimum_val;
	t_stack	*sentinel;

	sentinel = bilist;
	index = 0;
	minimum_val = INT_MAX;
	while (true)
	{
		bilist = bilist->back;
		if (bilist == sentinel)
			break ;
		if (minimum_val > bilist->val)
		{
			minimum_val = bilist->val;
		}
		index++;
	}
	return (minimum_val);
}

int	ft_get_minimum_val_index_from_bilist(t_stack *bilist)
{
	int		index;
	int		minimum_val_index;
	int		minimum_val;
	t_stack	*sentinel;

	sentinel = bilist;
	index = 0;
	minimum_val = INT_MAX;
	while (true)
	{
		bilist = bilist->back;
		if (bilist == sentinel)
			break ;
		if (minimum_val > bilist->val)
		{
			minimum_val = bilist->val;
			minimum_val_index = index; 
		}
		index++;
	}
	return (minimum_val_index);
}

void	ft_pa_minimum_element(t_stack *a, t_stack *b)
{
	int	minimum_val_index;
	int	element_count;
	int	reverse_rotate_count;
	int	rotate_count;

	minimum_val_index = ft_get_minimum_val_index_from_bilist(b);
	element_count = ft_get_stack_size(b);
	reverse_rotate_count = 0;
	rotate_count = 0;
	if (minimum_val_index > element_count / 2)
	{
		reverse_rotate_count = element_count - minimum_val_index;
		while (reverse_rotate_count > 0)
		{
			ft_rrb(b);
			reverse_rotate_count--;
		}
	}
	else
	{
		rotate_count = minimum_val_index;
		while (rotate_count > 0)
		{
			ft_rb(b);
			rotate_count--;
		}
	}
	ft_pa(a, b);
}

void	ft_pb_min_val(t_stack *a, t_stack *b)
{
	int	minimum_val_index;
	int	element_count;
	int	reverse_rotate_count;
	int	rotate_count;

	minimum_val_index = ft_get_minimum_val_index_from_bilist(a);
	element_count = ft_get_stack_size(a);
	reverse_rotate_count = 0;
	rotate_count = 0;
	if (minimum_val_index > element_count / 2)
	{
		reverse_rotate_count = element_count - minimum_val_index;
		while (reverse_rotate_count > 0)
		{
			ft_rra(a);
			reverse_rotate_count--;
		}
	}
	else
	{
		rotate_count = minimum_val_index;
		while (rotate_count > 0)
		{
			ft_ra(a);
			rotate_count--;
		}
	}
	ft_pb(a, b);
}
