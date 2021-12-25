/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:03 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 05:17:35 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "bilist.h"
# include "order.h"
# include "sort_utils.h"
# include "arg_utils.h"
# include "array_utils.h"

# include <stdbool.h>
# include <stdio.h>
# include <string.h>

# define ERROR 1

// error
void	ft_error(const char *msg);

t_stack	*ft_new_bilist_sentinel(void);
t_stack	*ft_new_bilist(int val);
void		ft_add_bilist(t_stack *bilist1, t_stack *bilist2);
t_stack	*ft_new_stack(int	*arry, size_t size);
void		ft_del_bilist(t_stack **bilist);
t_stack	*ft_pop_bilist(t_stack *bilist);
void		ft_push(t_stack *stack_1, t_stack *stack_2);
void		ft_swap(t_stack *stack);
void		ft_swap_helper(t_stack *stack, int index_1, int index_2);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
void	ft_delete_stack(t_stack *stack);
int	ft_get_median_from_bilist(t_stack *a, int upper_limit);
void	ft_print_stack(t_stack *stack);
void	ft_print_sepline(void);
void	ft_print_stacks(t_stack *a, t_stack *b);
bool	ft_is_sorted(t_stack *bilist);
int	ft_get_sorted_bilist_num(t_stack *bilist);
int		ft_get_stack_size(t_stack *stack);
void	ft_pb_min_val(t_stack *a, t_stack *b);
void	ft_pa_minimum_element(t_stack *a, t_stack *b);
bool	ft_is_val_in_stack(t_stack *stack, int val);
int	ft_get_min_val_from_stack(t_stack *bilist);

void	ft_send_half_to_b(t_stack *a, t_stack *b, int a_min_val, int a_max_val);
void	ft_send_half_to_a(t_stack *a, t_stack *b, int b_min_val, int b_max_val);

#endif
