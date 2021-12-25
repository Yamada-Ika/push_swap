/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:03 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 04:01:12 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

# define SECOND_TAIL -2
# define TAIL -1
# define SENTINEL 0
# define HEAD 1
# define ERROR 1

typedef struct s_stack
{
	int		val;
	struct	s_stack	*front;
	struct	s_stack	*back;
}	t_stack;

// error
void	ft_error(const char *msg);

// argument
bool	ft_is_wrong_arg(int argc, char *argv[]);
int		*ft_get_arry_from_arg(int argc, char *argv[]);
void	ft_arry_compress(int *arry, int size);

// sort
void	ft_size_three(t_stack *a);
void	ft_size_under_six(t_stack *a, t_stack *b, int a_size);
void	ft_join_sorted_b_to_end_of_a(t_stack *a, t_stack *b, int b_size);
void	ft_sort_left_in_a(t_stack *a, t_stack *b, int a_size);
void	ft_send_half_to_a(t_stack *a, t_stack *b, int b_min_val, int b_max_val);
void	ft_send_half_to_b(t_stack *a, t_stack *b, int a_min_val, int a_max_val);

// order
void	ft_sa(t_stack *a);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *a);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *a);
void	ft_rrr(t_stack *a, t_stack *b);

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
