/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:50:48 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/31 16:15:28 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

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
		return (NULL);
	if (arry == NULL)
		return (new_stack);
	i = size - 1;
	while (i >= 0)
	{
		new_node = ft_new_bilist(arry[i]);
		if (new_node == NULL)
		{
			ft_delete_stack(new_stack);
			return (NULL);
		}
		ft_add_bilist(new_stack, new_node);
		if (i == 0)
			break ;
		i--;
	}
	return (new_stack);
}
