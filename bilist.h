/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilist.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:08:22 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 16:57:06 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BILIST_H
# define BILIST_H

# include <stdbool.h>

typedef struct s_stack
{
	int		val;
	struct	s_stack	*front;
	struct	s_stack	*back;
}	t_stack;

t_stack	*ft_new_bilist_sentinel(void);
t_stack	*ft_new_bilist(int val);
void	ft_del_bilist(t_stack **bilist);

void	ft_add_bilist(t_stack *bilist_1, t_stack *bilist_2);
void	ft_pb_min_val(t_stack *a, t_stack *b);
t_stack	*ft_pop_bilist(t_stack *bilist);
t_stack	*ft_get_element_at_index(t_stack *stack, int index);
bool	ft_is_sentinel(t_stack *bilist);
bool	ft_is_less_than_one_element(t_stack *bilist);
bool	ft_is_sorted(t_stack *bilist);
bool	ft_is_val_in_stack(t_stack *stack, int val);
int		ft_get_min_val_from_stack(t_stack *bilist);

#endif
