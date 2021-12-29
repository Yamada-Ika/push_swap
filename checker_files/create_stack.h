/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:52:12 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/30 01:39:56 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_STACK_H
# define CREATE_STACK_H

# include "../libft/libft.h"
# include "t_stack.h"
# include "macro.h"

void	ft_error(char *fmt, int status);
t_stack	*ft_new_bilist_sentinel(void);
void	ft_add_bilist(t_stack *bilist_1, t_stack *bilist_2);
t_stack	*ft_new_bilist(int val);
t_stack	*ft_new_stack(int	*arry, size_t size);

#endif
