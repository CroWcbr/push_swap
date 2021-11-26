/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_all_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crow <crow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 19:17:43 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/24 22:32:01 by crow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

void	ps_sort_all_b_five(t_stacks *data)
{
	int	need_sort_b;
	int	i;

	need_sort_b = data->b->size;
	while (data->b->size > 3)
	{
		ps_comands(data, "pa");
		if (data->a->head->sort == data->sorted + 1)
		{
			ps_sort_a_head_to_a_tail(data);
			need_sort_b -= 1;
		}
	}
	ps_sort_three_min_max_b(data);
	if (data->a->head->sort > data->a->head->next->sort \
		&& data->a->head->next->in_b != -1)
		ps_comands(data, "sa");
	i = -1;
	while (++i < need_sort_b)
	{
		if (data->b->head && data->b->head->sort == data->sorted + 1)
			ps_comands(data, "pa");
		ps_sort_a_head_to_a_tail(data);
	}
}

static int	ps_sort_last_two_elem(t_stacks *data)
{
	ps_comands(data, "pa");
	if (data->a->tail->in_b == -2)
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
	{
		data->a->head->in_b = -2;
		ps_comands(data, "ra");
	}
	return (1);
}

void	ps_sort_all_b_to_a(t_stacks *data)
{
	int		i;
	int		size_b;
	int		sort_middle;
	int		flag;

	flag = 1;
	sort_middle = data->b->size / 2 + data->sorted;
	i = -1;
	size_b = data->b->size;
	while (++i < size_b)
	{
		if (flag == 1 && data->b->head->sort <= data->sorted + 2)
			flag = ps_sort_last_two_elem(data);
		else if (flag == 0 && data->b->head->sort == data->sorted + 1)
		{
			ps_comands(data, "pa");
			ps_sort_a_head_to_a_tail(data);
		}
		else if (data->b->head->sort > sort_middle)
			ps_comands(data, "pa");
		else
			ps_comands(data, "rb");
	}
}
