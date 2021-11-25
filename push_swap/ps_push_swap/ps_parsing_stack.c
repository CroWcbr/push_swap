/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:37:19 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 18:26:57 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static t_node	*ps_dl_lstnew(int num, int sort, int value)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	tmp->num = num;
	tmp->sort = sort;
	tmp->value = value;
	tmp->in_b = 0;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

static void	ps_dl_lstadd_back(t_dl_list **lst, t_node *new)
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

static int	ps_find_position(int size, int *arr, int position)
{
	int	sort;
	int	i;

	i = 0;
	sort = size;
	while (i < size)
	{
		if (arr[position] < arr[i])
			sort--;
		i++;
	}
	return (sort);
}

static int	*ps_update_num_arr_argc_one(int *size, char **num_arr)
{
	int	*arr;

	if (*size == 1)
	{
		num_arr = ft_split(num_arr[0], ' ');
		*size = 0;
		while (num_arr[*size])
			*size += 1;
		arr = ps_parsing_array(*size, num_arr);
		ft_free_split(num_arr);
	}
	else
		arr = ps_parsing_array(*size, num_arr);
	return (arr);
}

void	ps_parsing_list(t_dl_list *a, int size, char **num_arr)
{
	int			*arr;
	t_node		*tmp;
	int			i;
	int			sort_position;

	arr = ps_update_num_arr_argc_one(&size, num_arr);
	i = -1;
	while (++i < size)
	{
		sort_position = ps_find_position(size, arr, i);
		tmp = ps_dl_lstnew(i + 1, sort_position, arr[i]);
		if (!tmp)
			ps_error("Error: no malloc new dl_list");
		ps_dl_lstadd_back(&a, tmp);
	}
	free(arr);
}
