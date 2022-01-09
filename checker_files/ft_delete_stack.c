/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:51:36 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/10 01:20:34 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

static void	ft_del_bilist(t_stack **bilist)
{
	free(*bilist);
	*bilist = NULL;
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
			break ;
	}
}
