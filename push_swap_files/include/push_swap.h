/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:03 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/22 00:24:48 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "order.h"
# include "sort_utils.h"
# include "stack_utils.h"
# include "error.h"

# include <stdbool.h>

// ft_is_wrong_arry.c
bool	ft_is_wrong_arry(char *argv[]);

// stack
t_stack	*ft_new_stack(int	*arry, size_t size);
void	ft_delete_stack(t_stack *stack);

// ft_get_arry_from_arg.c
int		*ft_get_arry_from_arg(char *argv[]);
void	ft_arry_compress(int *arry, int size);

// utils/arry_utils.c
size_t	ft_get_size(char **argv);

#endif
