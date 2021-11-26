/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:41:56 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/29 19:47:52 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

int	ps_swap_sa_sb(t_dl_list **lst)
{
	t_node	*tmp;

	if (!(*lst)->head || !(*lst)->head->next)
		return (0);
	tmp = (*lst)->head->next;
	if (tmp->next)
		tmp->next->prev = (*lst)->head;
	(*lst)->head->prev = tmp;
	(*lst)->head->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = (*lst)->head;
	(*lst)->head = tmp;
	return (1);
}

int	ps_swap_ra_rb(t_dl_list **lst)
{
	t_node	*tmp;

	if (!(*lst)->head || !(*lst)->head->next)
		return (0);
	tmp = (*lst)->head;
	(*lst)->head = (*lst)->head->next;
	(*lst)->head->prev = NULL;
	tmp->prev = (*lst)->tail;
	tmp->next = NULL;
	(*lst)->tail->next = tmp;
	(*lst)->tail = tmp;
	return (1);
}

int	ps_swap_rra_rrb(t_dl_list **lst)
{
	t_node	*tmp;

	if (!(*lst)->head || !(*lst)->head->next)
		return (0);
	tmp = (*lst)->tail;
	(*lst)->tail = (*lst)->tail->prev;
	(*lst)->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = (*lst)->head;
	(*lst)->head->prev = tmp;
	(*lst)->head = tmp;
	return (1);
}

static void	ps_dl_lstadd_front(t_dl_list **lst, t_node *new)
{
	if (!(*lst)->size)
	{
		(*lst)->head = new;
		(*lst)->tail = new;
	}
	else
	{
		new->next = (*lst)->head;
		(*lst)->head->prev = new;
		(*lst)->head = new;
	}
	(*lst)->size++;
}

int	ps_swap_pa_pb(t_dl_list **from, t_dl_list **to)
{
	t_node	*tmp;

	if (!(*from)->head)
		return (0);
	tmp = (*from)->head;
	if (!(*from)->head->next)
	{
		(*from)->head = NULL;
		(*from)->tail = NULL;
	}
	else
	{
		(*from)->head = (*from)->head->next;
		(*from)->head->prev = NULL;
	}
	(*from)->size--;
	tmp->next = NULL;
	ps_dl_lstadd_front(to, tmp);
	return (1);
}
