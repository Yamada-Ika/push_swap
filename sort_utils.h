/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:59:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/29 22:53:47 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "bilist.h"

void	ft_sort_three(t_stack *a);
void	ft_sort_below_five(t_stack *a, t_stack *b, int a_size);
void	ft_pa_half(t_stack *a, t_stack *b, int b_min_val, int b_max_val);
void	ft_pb_half(t_stack *a, t_stack *b, int a_min_val, int a_max_val);

#endif
