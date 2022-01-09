/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_helper.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:05:13 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/08 13:24:07 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_HELPER_H
# define ORDER_HELPER_H

# include "order.h"

# define SECOND_TAIL -2
# define TAIL -1
# define SENTINEL 0
# define HEAD 1

int		ft_get_stack_size(t_stack *stack);
void	ft_push(t_stack *stack_1, t_stack *stack_2);
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

#endif
