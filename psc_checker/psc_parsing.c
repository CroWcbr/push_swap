/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:37:19 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 18:00:14 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psc_checker.h"

static int	psc_check_num(const char *str)
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

int	*psc_parsing_array(int size, char **num_arr)
{
	int	i;
	int	j;
	int	*arr;

	arr = (int *)malloc(size * sizeof(int));
	if (!arr)
		psc_error("Error: parsing - no malloc array");
	i = -1;
	while (++i < size)
	{
		if (psc_check_num(num_arr[i]))
			arr[i] = ft_atoi(num_arr[i]);
		else
			psc_error("Error: parsing - incorrect number in array");
	}
	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
			if (arr[i] == arr[j])
				psc_error("Error: parisng - there are duplicates");
	}
	return (arr);
}

static t_node	*psc_dl_lstnew(int value)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

static void	psc_dl_lstadd_back(t_dl_list **lst, t_node *new)
{
	if (!(*lst)->size)
	{
		(*lst)->head = new;
		(*lst)->tail = new;
	}
	else
	{
		new->prev = (*lst)->tail;
		(*lst)->tail->next = new;
		(*lst)->tail = new;
	}
	(*lst)->size++;
}

void	psc_parsing_stack_a(t_dl_list *a, int size, char **num_arr)
{
	int			*arr;
	t_node		*tmp;
	int			i;

	if (size == 1)
	{
		num_arr = ft_split(num_arr[0], ' ');
		size = 0;
		while (num_arr[size])
			size++;
		arr = psc_parsing_array(size, num_arr);
		ft_free_split(num_arr);
	}
	else
		arr = psc_parsing_array(size, num_arr);
	i = 0;
	while (i < size)
	{
		tmp = psc_dl_lstnew(arr[i]);
		if (!tmp)
			psc_error("Error: no malloc new dl_list");
		psc_dl_lstadd_back(&a, tmp);
		i++;
	}
	free(arr);
}
