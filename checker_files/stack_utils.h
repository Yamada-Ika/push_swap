/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:08:55 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 19:18:34 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include "t_stack.h"
# include <stdbool.h>

bool	ft_is_sentinel(t_stack *bilist);
bool	ft_is_size_one(t_stack *bilist);
t_stack	*ft_get_element_at_index(t_stack *stack, int index);

#endif
