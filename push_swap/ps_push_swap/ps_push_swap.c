/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:22:38 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 20:14:22 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static t_stacks	*ps_init(void)
{
	t_stacks	*data;

	data = (t_stacks *)malloc(sizeof(t_stacks));
	if (!data)
		ps_error("Error: no malloc struct of stacks");
	data->a = (t_dl_list *)malloc(sizeof(t_dl_list));
	data->b = (t_dl_list *)malloc(sizeof(t_dl_list));
	if (!data->a || !data->b)
		ps_error("Error: no malloc stack a || b");
	data->a->size = 0;
	data->a->head = NULL;
	data->a->tail = NULL;
	data->b->size = 0;
	data->b->head = NULL;
	data->b->tail = NULL;
	data->cmd = NULL;
	data->sorted = 0;
	data->unsorted = 0;
	data->size_list = 0;
	return (data);
}

static void	ps_sort(t_stacks *data)
{
	if (data->size_list <= 6)
		ps_sort_six(data);
	else
	{
		ps_sort_all_first_a_to_b(data);
		while ((!(ps_check_sort(data->a)) || \
				!(data->size_list == data->sorted)))
		{
			if (data->b->size > 0 && data->b->size <= 5)
				ps_sort_all_b_five(data);
			else if (data->b->size > 5)
				ps_sort_all_b_to_a(data);
			else if (ps_find_same_in_b_into_a(data->a->head) > 0 && \
					ps_find_same_in_b_into_a(data->a->head) <= 5)
				ps_sort_all_a_five(data);
			else if (ps_find_same_in_b_into_a(data->a->head) > 5)
				ps_sort_all_a_to_b(data);
		}
	}
}

void	free_stack(t_stacks **data)
{
	t_node	*tmp;
	t_list	*lst;

	while ((*data)->a->head)
	{
		tmp = (*data)->a->head->next;
		free((*data)->a->head);
		(*data)->a->head = tmp;
	}
	free((*data)->a);
	while ((*data)->b->head)
	{
		tmp = (*data)->b->head->next;
		free((*data)->b->head);
		(*data)->b->head = tmp;
	}
	free((*data)->b);
	while ((*data)->cmd)
	{
		lst = (*data)->cmd->next;
		free((*data)->cmd->content);
		free((*data)->cmd);
		(*data)->cmd = lst;
	}
	free((*data)->cmd);
}

int	main(int argc, char **argv)
{
	t_stacks	*data;
	t_list		*tmp;

	if (argc > 1)
	{
		data = ps_init();
		ps_parsing_list(data->a, argc - 1, ++argv);
		data->unsorted = data->a->size;
		data->size_list = data->a->size;
		if (!ps_check_sort(data->a))
			ps_sort(data);
		optimization(&data->cmd);
		tmp = data->cmd;
		while (tmp)
		{
			ft_putstr(tmp->content);
			ft_putstr("\n");
			tmp = tmp->next;
		}
		free_stack(&data);
		free(data);
	}
	return (0);
}
