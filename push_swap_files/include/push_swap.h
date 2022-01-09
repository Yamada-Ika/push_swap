/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:03 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/08 16:34:12 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "order.h"
# include "sort_utils.h"
# include "stack_utils.h"
# include "error.h"

# include <stdbool.h>

// utils
bool	ft_is_wrong_arry(int argc, char *argv[]);

// stack
t_stack	*ft_new_stack(int	*arry, size_t size);
void	ft_delete_stack(t_stack *stack);

// array
int		*ft_get_arry_from_arg(int argc, char *argv[]);
void	ft_arry_compress(int *arry, int size);

#endif
