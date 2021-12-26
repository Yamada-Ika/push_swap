/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:42:33 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 17:47:03 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

t_stack	*ft_new_stack(int	*arry, size_t size)
{
	t_stack	*new_stack;
	t_stack	*new_node;
	size_t	i;

	new_stack = ft_new_bilist_sentinel();
	if (arry == NULL || new_stack == NULL)
		return (new_stack);
	i = size - 1;
	while (i >= 0)
	{
		new_node = ft_new_bilist(arry[i]);
		if (new_node == NULL)
			return (NULL);
		ft_add_bilist(new_stack, new_node);
		if (i == 0)
			break ;
		i--;
	}
	return (new_stack);
}

int	ft_get_stack_size(t_stack *stack)
{
	t_stack	*dummy;
	int		size;

	dummy = stack;
	size = 0;
	while (true)
	{
		stack = stack->front;
		if (stack == dummy)
			break;
		size++;
	}
	return (size);
}

void	ft_delete_stack(t_stack *stack)
{
	t_stack	*dummy;
	t_stack	*prev_stack;

	dummy = stack;
	while (true)
	{
		prev_stack = stack;
		stack = stack->front;
		ft_del_bilist(&prev_stack);
		if (stack == dummy)
			break;
	}
	ft_del_bilist(&dummy);
}
