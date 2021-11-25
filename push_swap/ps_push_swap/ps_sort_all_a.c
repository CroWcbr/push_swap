/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_all_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crow <crow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:41:38 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/24 22:00:56 by crow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static void	ps_sort_a_b(t_stacks *data)
{
	if (data->b->size == 3)
		ps_sort_three_min_max_b(data);
	else if (data->b->size == 2 && \
			data->b->head->sort > data->b->head->next->sort)
		ps_comands(data, "sb");
	if (data->a->head->sort > data->a->head->next->sort && \
			data->a->head->next->in_b != -1)
		ps_comands(data, "sa");
}

void	ps_sort_all_a_five(t_stacks *data)
{
	int	need_sort_a;
	int	i;
	int	i_tmp;

	need_sort_a = ps_find_same_in_b_into_a(data->a->head);
	i = -1;
	i_tmp = need_sort_a;
	while (i_tmp > ++i + 2)
	{
		if (data->a->head->sort == data->sorted + 1)
		{
			ps_sort_a_head_to_a_tail(data);
			need_sort_a -= 1;
		}
		else
			ps_comands(data, "pb");
	}
	ps_sort_a_b(data);
	i = -1;
	while (++i < need_sort_a)
	{
		if (data->b->head && data->b->head->sort == data->sorted + 1)
			ps_comands(data, "pa");
		ps_sort_a_head_to_a_tail(data);
	}
}

static int	ps_sort_last_two_elem(t_stacks *data)
{
	if (data->a->head->in_b == data->a->tail->in_b)
	{
		if (data->a->head->sort > data->a->tail->sort)
		{
			data->a->tail->in_b = -1;
			data->sorted += 1;
			data->unsorted -= 1;
			ps_sort_a_head_to_a_tail(data);
		}
		else
		{
			ps_comands(data, "rra");
			ps_comands(data, "sa");
			ps_sort_a_head_to_a_tail(data);
			ps_sort_a_head_to_a_tail(data);
		}
		return (0);
	}
	else
		ps_comands(data, "ra");
	return (1);
}

void	ps_sort_all_a_to_b(t_stacks *data)
{
	int		tmp_b;
	int		flag;

	flag = 1;
	tmp_b = data->a->head->in_b;
	while (data->a->head && tmp_b == data->a->head->in_b)
	{
		if (flag == 1 && data->a->head->sort <= data->sorted + 2)
			flag = ps_sort_last_two_elem(data);
		else if (flag == 0 && data->a->head->sort == data->sorted + 1)
			ps_sort_a_head_to_a_tail(data);
		else
			ps_comands(data, "pb");
	}
}
