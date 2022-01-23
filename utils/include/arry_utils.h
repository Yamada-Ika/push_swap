/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arry_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 00:15:28 by iyamada           #+#    #+#             */
/*   Updated: 2022/01/24 02:17:50 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRY_UTILS_H
# define ARRY_UTILS_H

# include <stdbool.h>
# include "libft.h"

// arry_utils.c
void	ft_frees(char **strs);
size_t	ft_get_size(char **argv);

#endif
