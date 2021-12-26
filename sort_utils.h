/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:59:36 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 17:11:27 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_UTILS_H
# define SORT_UTILS_H

# include "bilist.h"

void	ft_sort_three(t_stack *a);
void	ft_sort_under_six(t_stack *a, t_stack *b, int a_size);
void	ft_join_sorted_b_to_end_of_a(t_stack *a, t_stack *b, int b_size);
void	ft_sort_left_in_a(t_stack *a, t_stack *b, int a_size);
void	ft_send_half_to_a(t_stack *a, t_stack *b, int b_min_val, int b_max_val);
void	ft_send_half_to_b(t_stack *a, t_stack *b, int a_min_val, int a_max_val);

#endif
