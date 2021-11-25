/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dyn_arr_free_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 02:47:26 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/30 02:47:28 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dyn_arr_free_char(char **arr, int row)
{
	int	i;

	i = -1;
	while (++i < row)
		free(arr[i]);
	free(arr);
}
