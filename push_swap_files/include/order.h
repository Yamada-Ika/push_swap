/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 04:05:13 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 00:26:05 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ORDER_H
# define ORDER_H

# include "bilist.h"
# include "../libft/libft.h"

void	ft_sa(t_stack *a);
void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

#endif
