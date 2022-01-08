/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:42:33 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/08 13:14:01 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdbool.h>

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
			break ;
		size++;
	}
	return (size);
}
