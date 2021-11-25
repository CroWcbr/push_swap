/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_all_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:45:26 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/31 19:08:13 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static void	ps_sort_all_first_last_three(t_stacks *data)
{
	int	i;

	ps_comands(data, "rrb");
	ps_comands(data, "pa");
	ps_comands(data, "rrb");
	ps_comands(data, "rrb");
	if (data->b->head->sort > data->b->head->next->sort)
		ps_comands(data, "sb");
	i = -1;
	while (++i < 3)
	{
		if (data->b->head && data->b->head->sort == data->sorted + 1)
			ps_comands(data, "pa");
		data->a->head->in_b = -1;
		ps_comands(data, "ra");
		data->sorted += 1;
		data->unsorted -= 1;
	}
}

void	ps_sort_all_first_a_to_b(t_stacks *data)
{
	int		i;

	i = -1;
	while (++i < data->size_list)
	{
		if (data->a->head->sort < data->size_list / 2 + 1)
		{
			ps_comands(data, "pb");
			if (data->b->head->sort <= data->sorted + 3)
				ps_comands(data, "rb");
		}
		else
			ps_comands(data, "ra");
	}
	ps_sort_all_first_last_three(data);
}
