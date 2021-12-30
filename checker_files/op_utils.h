/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:04:35 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 17:06:15 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_UTILS_H
# define OP_UTILS_H

# include "t_stack.h"

void	ft_swap(t_stack *stack);
void	ft_push(t_stack *stack_1, t_stack *stack_2);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

#endif
