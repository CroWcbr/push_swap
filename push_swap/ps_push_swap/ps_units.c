/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_units.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:10:24 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 20:15:24 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

void	ps_error(char *str)
{
	write(2, str, 5);
	ft_putstr_fd("\n", 2);
	exit (0);
}

int	ps_check_sort(t_dl_list *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	while (tmp->next)
	{
		if (tmp->sort > tmp->next->sort)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ps_find_same_in_b_into_a(const t_node *tmp)
{
	int	i;
	int	tmp_b;

	i = 0;
	tmp_b = tmp->in_b;
	if (tmp_b != -1)
	{
		while (tmp && tmp->in_b == tmp_b)
		{
			tmp = tmp->next;
			i++;
		}
	}
	return (i);
}

void	ps_sort_three_min_max_b(t_stacks *data)
{
	while (!ps_check_sort(data->b))
	{
		if (data->b->head->sort > data->b->head->next->sort && \
			data->b->head->sort > data->b->tail->sort)
			ps_comands(data, "rb");
		else if (data->b->tail->sort < data->b->head->next->sort && \
			data->b->tail->sort < data->b->head->sort)
			ps_comands(data, "rrb");
		else
			ps_comands(data, "sb");
	}
}

void	ps_sort_a_head_to_a_tail(t_stacks *data)
{
	data->a->head->in_b = -1;
	ps_comands(data, "ra");
	data->sorted += 1;
	data->unsorted -= 1;
}
