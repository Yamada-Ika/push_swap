/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:01:03 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/08 13:01:24 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	ft_error(char *fmt, int status)
{
	ft_putendl_fd(fmt, STDERR_FILENO);
	exit(status);
}
