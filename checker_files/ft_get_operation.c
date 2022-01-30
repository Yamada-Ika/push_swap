/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:45:08 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/30 15:48:21 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "macro.h"
#include "libft.h"
#include "get_next_line.h"

static bool	ft_get_operation_helper(t_stack *a, t_stack *b, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		ft_sa(a);
	else if (ft_strcmp(op, "sb\n") == 0)
		ft_sb(b);
	else if (ft_strcmp(op, "ss\n") == 0)
		ft_ss(a, b);
	else if (ft_strcmp(op, "pa\n") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(op, "pb\n") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(op, "ra\n") == 0)
		ft_ra(a);
	else if (ft_strcmp(op, "rb\n") == 0)
		ft_rb(b);
	else if (ft_strcmp(op, "rr\n") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(op, "rra\n") == 0)
		ft_rra(a);
	else if (ft_strcmp(op, "rrb\n") == 0)
		ft_rrb(b);
	else if (ft_strcmp(op, "rrr\n") == 0)
		ft_rrr(a, b);
	else
		return (false);
	return (true);
}

void	ft_get_operation(t_stack *a, t_stack *b)
{
	char	*op;

	while (true)
	{
		op = get_next_line(STDIN_FILENO);
		if (op == NULL)
			return ;
		if (!ft_get_operation_helper(a, b, op))
			ft_error("Error", OP_ERROR);
		free(op);
	}
}
