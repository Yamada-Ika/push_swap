/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:19:03 by iyamada           #+#    #+#             */
/*   Updated: 2022/02/12 04:35:40 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "order.h"
# include "sort_utils.h"
# include "stack_utils.h"
# include "error.h"

# include <stdbool.h>

typedef enum e_order_kind
{
	ORDER_SA,
	ORDER_SB,
	ORDER_SS,
	ORDER_PA,
	ORDER_PB,
	ORDER_RA,
	ORDER_RB,
	ORDER_RR,
	ORDER_RRA,
	ORDER_RRB,
	ORDER_RRR
}	t_order_kind;

typedef struct s_order_list
{
	t_order_kind		order_kind;
	struct s_order_list	*next;
	struct s_order_list	*prev;
}	t_order_list;

typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	t_order_list	*order_list;
}	t_push_swap;

// utils/ft_is_wrong_arry.c
bool	ft_is_wrong_arry(char *argv[]);

// stack
t_stack	*ft_new_stack(int	*arry, size_t size);
void	ft_delete_stack(t_stack *stack);

// utils/ft_get_arry_from_arg.c
int		*ft_get_arry_from_arg(char *argv[]);
void	ft_arry_compress(int *arry, int size);

// utils/arry_utils.c
size_t	ft_get_size(char **argv);

void	ft_add_order_list(t_order_list *order_list, t_order_kind kind);

// order
void	ft_sa(t_stack *a, t_order_list *order_list);
void	ft_sb(t_stack *b, t_order_list *order_list);
void	ft_pa(t_stack *a, t_stack *b, t_order_list *order_list);
void	ft_pb(t_stack *a, t_stack *b, t_order_list *order_list);
void	ft_ra(t_stack *a, t_order_list *order_list);
void	ft_rb(t_stack *b, t_order_list *order_list);
void	ft_rr(t_stack *a, t_stack *b, t_order_list *order_list);
void	ft_rra(t_stack *a, t_order_list *order_list);
void	ft_rrb(t_stack *b, t_order_list *order_list);
void	ft_rrr(t_stack *a, t_stack *b, t_order_list *order_list);

void	ft_sort_three(t_push_swap *psw);
void	ft_sort_below_five(t_push_swap *psw, int a_size);
void	ft_pa_half(t_push_swap *psw, int min_val, int max_val);
void	ft_pb_half(t_push_swap *psw, int min_val, int max_val);

void	ft_pb_min_val(t_push_swap *psw);

#endif
