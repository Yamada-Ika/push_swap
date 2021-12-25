/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyamada <iyamada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 05:15:47 by iyamada           #+#    #+#             */
/*   Updated: 2021/12/26 05:17:13 by iyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

int		*ft_get_arry_from_arg(int argc, char *argv[]);
int		ft_get_rank_from_arry(int *sorted_arry, int size, int element);
void	ft_sort_ascending_order(int *arry, int size);
int		*ft_copy_arry(int *copied_arry, int size);
void	ft_arry_compress(int *arry, int size);

#endif
