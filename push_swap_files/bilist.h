/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:08:22 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/08 12:54:16 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BILIST_H
# define BILIST_H

# include <stdbool.h>
# include "stack.h"

void	ft_pb_min_val(t_stack *a, t_stack *b);
t_stack	*ft_pop_bilist(t_stack *bilist);
t_stack	*ft_get_element_at_index(t_stack *stack, int index);
bool	ft_is_sentinel(t_stack *bilist);
bool	ft_is_less_than_one_element(t_stack *bilist);
bool	ft_is_sorted(t_stack *bilist);
bool	ft_is_val_in_stack(t_stack *stack, int val);
int		ft_get_min_val_from_stack(t_stack *bilist);

#endif
