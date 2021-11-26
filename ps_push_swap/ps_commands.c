/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:40:53 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/31 21:44:50 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps_push_swap.h"

static void	ps_commands_add_list(t_stacks *data, t_list **cmd, char *str_cmd)
{
	t_list	*tmp_cmd;
	char	*cmd_dup;

	cmd_dup = ft_strdup(str_cmd);
	if (!cmd_dup)
		ps_error("Error: command - no malloc");
	tmp_cmd = ft_lstnew(cmd_dup);
	if (!tmp_cmd)
		ps_error("Error: command - no malloc");
	ft_lstadd_back(cmd, tmp_cmd);
	if (!ft_strcmp(str_cmd, "pa") && data->a->head->in_b != -2)
		data->a->head->in_b += 1;
	if (!ft_strcmp(str_cmd, "pb") && data->b->head->in_b != -2)
		data->b->head->in_b += 1;
	if (!ft_strcmp(str_cmd, "rb") && data->b->tail->in_b != -2)
		data->b->tail->in_b += 1;
}

void	ps_comands(t_stacks *data, char *str_cmd)
{
	int		i;

	i = 0;
	if (!ft_strcmp(str_cmd, "sa"))
		i = ps_swap_sa_sb(&data->a);
	else if (!ft_strcmp(str_cmd, "sb"))
		i = ps_swap_sa_sb(&data->b);
	else if (!ft_strcmp(str_cmd, "ra"))
		i = ps_swap_ra_rb(&data->a);
	else if (!ft_strcmp(str_cmd, "rb"))
		i = ps_swap_ra_rb(&data->b);
	else if (!ft_strcmp(str_cmd, "rra"))
		i = ps_swap_rra_rrb(&data->a);
	else if (!ft_strcmp(str_cmd, "rrb"))
		i = ps_swap_rra_rrb(&data->b);
	else if (!ft_strcmp(str_cmd, "pa"))
		i = ps_swap_pa_pb(&data->b, &data->a);
	else if (!ft_strcmp(str_cmd, "pb"))
		i = ps_swap_pa_pb(&data->a, &data->b);
	if (i == 1)
		ps_commands_add_list(data, &data->cmd, str_cmd);
}
