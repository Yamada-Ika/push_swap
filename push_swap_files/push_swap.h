/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:03 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 00:26:05 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "bilist.h"
# include "order.h"
# include "sort_utils.h"
# include "stack_utils.h"

# include <stdbool.h>
# include <stdio.h>
# include <string.h>

# define ARG_ERROR 1
# define MEM_ERROR 1

// utils
bool	ft_is_wrong_arg(int argc, char *argv[]);

// array
int		*ft_get_arry_from_arg(int argc, char *argv[]);
void	ft_arry_compress(int *arry, int size);

// error
void	ft_error(char *fmt, int status);

#endif
