/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilist_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 02:01:51 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 02:03:45 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BILIST_UTILS_H
# define BILIST_UTILS_H

# include "t_stack.h"

void	ft_add_bilist(t_stack *bilist_1, t_stack *bilist_2);
t_stack	*ft_pop_bilist(t_stack *bilist);

#endif