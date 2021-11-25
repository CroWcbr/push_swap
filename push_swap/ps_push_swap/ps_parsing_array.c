/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:21:01 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 17:59:39 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static int	ps_check_num(const char *str)
{
	int		znak;
	long	lnbr;
	int		i;

	znak = 1;
	if (*str == '-')
		znak = -1;
	if (*str == '+' || *str == '-')
		str++;
	lnbr = 0;
	i = 0;
	while (ft_isdigit(*str) && lnbr - 1 < MAX_INT)
	{
		lnbr = lnbr * 10 + *str - '0';
		str++;
		i = 1;
	}
	lnbr = lnbr * znak;
	if (*str != '\0' || i == 0 || \
		lnbr < MIN_INT || lnbr > MAX_INT)
		return (0);
	return (1);
}

static int	ps_check_duplicates(int size, int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ps_parsing_array(int size, char **num_arr)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		ps_error("Error: parsing - no malloc array");
	i = -1;
	while (++i < size)
	{
		if (ps_check_num(num_arr[i]))
			arr[i] = ft_atoi(num_arr[i]);
		else
			ps_error("Error: parsing - incorrect number in array");
	}
	if (!ps_check_duplicates(size, arr))
		ps_error("Error: parisng - there are duplicates");
	return (arr);
}
