/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 16:12:44 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 16:14:03 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

#include "bilist.h"
#include "push_swap.h"

t_stack	*ft_new_stack(int	*arry, size_t size);
int		ft_get_stack_size(t_stack *stack);
void	ft_delete_stack(t_stack *stack);

#endif

