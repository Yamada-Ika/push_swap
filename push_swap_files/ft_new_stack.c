/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:44:33 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/08 13:20:47 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack struct
#include "stack.h"
// malloc
#include "stdlib.h"
// error
#include "error.h"

void	ft_add_bilist(t_stack *bilist_1, t_stack *bilist_2);

static t_stack	*ft_new_bilist_sentinel(void)
{
	t_stack	*sentinel;

	sentinel = (t_stack *)malloc(sizeof(t_stack));
	if (sentinel == NULL)
		return (NULL);
	sentinel->front = sentinel;
	sentinel->back = sentinel;
	sentinel->val = -1;
	return (sentinel);
}

static t_stack	*ft_new_bilist(int val)
{
	t_stack	*new_bilist;

	new_bilist = (t_stack *)malloc(sizeof(t_stack));
	if (new_bilist == NULL)
		return (NULL);
	new_bilist->val = val;
	new_bilist->front = NULL;
	new_bilist->back = NULL;
	return (new_bilist);
}

t_stack	*ft_new_stack(int	*arry, size_t size)
{
	t_stack	*new_stack;
	t_stack	*new_node;
	size_t	i;

	new_stack = ft_new_bilist_sentinel();
	if (new_stack == NULL)
		ft_error("Error", MEM_ERROR);
	if (arry == NULL)
		return (new_stack);
	i = size - 1;
	while (i >= 0)
	{
		new_node = ft_new_bilist(arry[i]);
		if (new_node == NULL)
			ft_error("Error", MEM_ERROR);
		ft_add_bilist(new_stack, new_node);
		if (i == 0)
			break ;
		i--;
	}
	return (new_stack);
}
