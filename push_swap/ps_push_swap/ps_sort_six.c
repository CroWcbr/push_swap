/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_six.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:45:03 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/31 20:50:18 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static int	ps_check_sort_max_min(t_dl_list *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	while (tmp->next)
	{
		if (tmp->sort < tmp->next->sort)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	ps_sort_three_max_min_b(t_stacks *data)
{
	while (!ps_check_sort_max_min(data->b))
	{
		if (data->b->head->sort == data->b->head->next->sort - 1)
			ps_comands(data, "sb");
		else if (data->b->head->sort == data->b->head->next->sort - 2)
			ps_comands(data, "rb");
		else
			ps_comands(data, "rrb");
	}
}

static void	ps_sort_three_min_max_a(t_stacks *data)
{
	while (!ps_check_sort(data->a))
	{
		if (data->a->head->sort - 1 == data->a->head->next->sort)
			ps_comands(data, "sa");
		else if (data->a->head->sort - 2 == data->a->head->next->sort)
			ps_comands(data, "ra");
		else
			ps_comands(data, "rra");
	}
}

void	ps_sort_six(t_stacks *data)
{
	if (data->a->size <= 3)
		ps_sort_three_min_max_a(data);
	else
	{
		while (data->a->size > 3)
		{
			if (data->a->head->sort <= data->size_list - 3)
				ps_comands(data, "pb");
			else
				ps_comands(data, "ra");
		}
		ps_sort_three_min_max_a(data);
		ps_sort_three_max_min_b(data);
		while (data->b->size)
			ps_comands(data, "pa");
	}
	data->sorted = data->size_list;
	data->unsorted = 0;
}
