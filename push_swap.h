/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:03 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/05 23:40:45 by iyamada          ###   ########.fr       */
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

typedef struct s_bilist
{
	int		value;
	struct	s_bilist	*front;
	struct	s_bilist	*back;
}	t_bilist;

// argument
int		ft_is_arg_correct(int argc, char *argv[]);
int		*ft_get_intarray_from_arg(int argc, char *argv[]);
void	ft_array_compress(int *array, int size);

void	ft_sa(t_bilist *stack_a);
void	ft_pa(t_bilist *stack_a, t_bilist *stack_b);
void	ft_pb(t_bilist *stack_a, t_bilist *stack_b);
void	ft_ra(t_bilist *stack_a);
void	ft_rb(t_bilist *stack_a);
void	ft_rr(t_bilist *stack_a, t_bilist *stack_b);
void	ft_rra(t_bilist *stack_a);
void	ft_rrb(t_bilist *stack_a);
void	ft_rrr(t_bilist *stack_a, t_bilist *stack_b);

t_bilist	*ft_new_bilist_sentinel(void);
t_bilist	*ft_new_bilist(int value);
void		ft_add_bilist(t_bilist *bilist1, t_bilist *bilist2);
t_bilist	*ft_create_stack(int	*array, size_t size);
void		ft_del_bilist(t_bilist **bilist);
t_bilist	*ft_pop_bilist(t_bilist *bilist);
void		ft_push(t_bilist *stack_1, t_bilist *stack_2);
void		ft_swap(t_bilist *stack);
void		ft_swap_helper(t_bilist *stack, int index_1, int index_2);
void	ft_rotate(t_bilist *stack);
void	ft_reverse_rotate(t_bilist *stack);
void	ft_delete_stack(t_bilist *stack);
int	ft_get_median_from_bilist(t_bilist *stack_a, int upper_limit);
void	ft_print_stack(t_bilist *stack);
void	ft_print_sepline(void);
void	ft_print_stacks(t_bilist *stack_a, t_bilist *stack_b);
bool	ft_is_sorted_bilist(t_bilist *bilist);
int	ft_get_sorted_bilist_num(t_bilist *bilist);
int		ft_get_bilist_element(t_bilist *stack);
void	ft_pb_minimum_element(t_bilist *stack_a, t_bilist *stack_b);
void	ft_pa_minimum_element(t_bilist *stack_a, t_bilist *stack_b);
bool	ft_is_value_in_stack(t_bilist *stack, int val);
int	ft_get_minimum_value_from_stack(t_bilist *bilist);

void	ft_send_half_to_b(t_bilist *stack_a, t_bilist *stack_b, int stack_a_min_val, int stack_a_max_val);
void	ft_send_half_to_a(t_bilist *stack_a, t_bilist *stack_b, int stack_b_min_val, int stack_b_max_val);

#endif
