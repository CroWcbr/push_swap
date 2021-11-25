/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_optimization.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:42:21 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 20:05:19 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static void	optimization1(t_list **cmd)
{
	t_list	*tmp_cmd;
	t_list	*tmp;
	t_list	*tmp_next;

	tmp_cmd = *cmd;
	while (tmp_cmd && tmp_cmd->next && tmp_cmd->next->next)
	{
		tmp = tmp_cmd->next;
		tmp_next = tmp_cmd->next->next;
		if ((!ft_strcmp(tmp->content, "ra") && \
			!ft_strcmp(tmp_next->content, "rra")) || \
			(!ft_strcmp(tmp->content, "rra") && \
			!ft_strcmp(tmp_next->content, "ra")) || \
			(!ft_strcmp(tmp->content, "rb") && \
			!ft_strcmp(tmp_next->content, "rrb")) || \
			(!ft_strcmp(tmp->content, "rrb") && \
			!ft_strcmp(tmp_next->content, "rb")))
		{
			tmp_cmd->next = tmp_next->next;
			ft_lstdelone (tmp, free);
			ft_lstdelone (tmp_next, free);
		}
		else
			tmp_cmd = tmp_cmd->next;
	}
}

static void	optimization2(t_list **cmd)
{
	t_list	*tmp;
	t_list	*tmp_cmd;

	tmp_cmd = *cmd;
	while (tmp_cmd && tmp_cmd->next)
	{
		tmp = tmp_cmd->next;
		if (!ft_strcmp(tmp_cmd->content, "ra") && \
				!ft_strcmp(tmp->content, "rb"))
			tmp_cmd->content = ft_strdup("rr");
		else if (!ft_strcmp(tmp_cmd->content, "rra") && \
				!ft_strcmp(tmp->content, "rrb"))
			tmp_cmd->content = ft_strdup("rrr");
		else if (!ft_strcmp(tmp_cmd->content, "sa") && \
				!ft_strcmp(tmp->content, "sb"))
			tmp_cmd->content = ft_strdup("ss");
		else
		{
			tmp_cmd = tmp_cmd->next;
			return ;
		}
		tmp_cmd->next = tmp->next;
		ft_lstdelone(tmp, free);
	}
}

void	optimization(t_list **cmd)
{
	optimization1(cmd);
	optimization2(cmd);
}
