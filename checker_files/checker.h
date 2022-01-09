/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:29:17 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/10 00:46:48 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "macro.h"
# include "error.h"
# include "t_stack.h"

// arg_utils.c
bool	ft_is_wrong_arg(int argc, char *argv[]);
int		*ft_get_arry_from_arg(int argc, char *argv[]);

// error.c
void	ft_error(char *fmt, int status);

// create_stack.c
t_stack	*ft_new_stack(int	*arry, size_t size);
bool	ft_is_sorted(t_stack *bilist);
int		ft_get_stack_size(t_stack *stack);

// op
void	ft_get_operation(t_stack *a, t_stack *b);

#endif
