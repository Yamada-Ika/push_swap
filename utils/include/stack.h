/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:15:28 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:13:07 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include "libft.h"

// error status
# define ARG_ERROR 1
# define MEM_ERROR 2
# define SORT_ERROR 3
# define OP_ERROR 3

// utils/stack_utils.c
# define SECOND_TAIL -2
# define TAIL -1
# define SENTINEL 0
# define HEAD 1

typedef struct s_stack
{
	int				val;
	struct s_stack	*front;
	struct s_stack	*back;
}	t_stack;

// bilist_utils.c
void	ft_add_bilist(t_stack *bilist_1, t_stack *bilist_2);
t_stack	*ft_pop_bilist(t_stack *bilist);

// ft_new_stack.c
t_stack	*ft_new_stack(int *arry, size_t size);

// ft_delete_stack.c
void	ft_delete_stack(t_stack *stack);

// stack_utils.c
int		ft_get_stack_size(t_stack *stack);
bool	ft_is_sorted(t_stack *bilist);
t_stack	*ft_get_element_at_index(t_stack *stack, int index);
bool	ft_is_sentinel(t_stack *bilist);
bool	ft_is_size_one(t_stack *bilist);

// utils/error.c
void	ft_error(char *fmt, int status);

#endif
