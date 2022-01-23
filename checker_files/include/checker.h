/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:29:17 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:36:51 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "macro.h"
# include "stack.h"

// utils/ft_is_wrong_arry.c
bool	ft_is_wrong_arry(char *argv[]);

// utils/ft_get_arry_from_arg.c
int		*ft_get_arry_from_arg(char *argv[]);

// error.c
void	ft_error(char *fmt, int status);

// create_stack.c
t_stack	*ft_new_stack(int	*arry, size_t size);
bool	ft_is_sorted(t_stack *bilist);
int		ft_get_stack_size(t_stack *stack);

// ft_get_operation.c
void	ft_get_operation(t_stack *a, t_stack *b);

// ft_delete_stack.c
void	ft_delete_stack(t_stack *stack);

// utils/arry_utils.c
size_t	ft_get_size(char **argv);

#endif
