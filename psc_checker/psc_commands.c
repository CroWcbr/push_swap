/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:40:53 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/02 15:27:06 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psc_checker.h"

void	psc_error(char *str)
{
	write(2, str, 5);
	ft_putstr_fd("\n", 2);
	exit (0);
}

static void	psc_commands_sa_sb(t_dl_list *a, t_dl_list *b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		psc_swap_sa_sb(&a);
	else if (!ft_strcmp(cmd, "sb"))
		psc_swap_sa_sb(&b);
	else
	{
		psc_swap_sa_sb(&a);
		psc_swap_sa_sb(&b);
	}
}

static void	psc_commands_ra_rb(t_dl_list *a, t_dl_list *b, char *cmd)
{
	if (!ft_strcmp(cmd, "ra"))
		psc_swap_ra_rb(&a);
	else if (!ft_strcmp(cmd, "rb"))
		psc_swap_ra_rb(&b);
	else
	{
		psc_swap_ra_rb(&a);
		psc_swap_ra_rb(&b);
	}
}

static void	psc_commands_rra_rrb(t_dl_list *a, t_dl_list *b, char *cmd)
{
	if (!ft_strcmp(cmd, "rra"))
		psc_swap_rra_rrb(&a);
	else if (!ft_strcmp(cmd, "rrb"))
		psc_swap_rra_rrb(&b);
	else
	{
		psc_swap_rra_rrb(&a);
		psc_swap_rra_rrb(&b);
	}
}

void	psc_commands(t_dl_list *a, t_dl_list *b, char *cmd)
{
	if (!cmd)
		psc_error("Error: wrong cmd");
	if (!ft_strcmp(cmd, "sa") || !ft_strcmp(cmd, "sb") || \
		!ft_strcmp(cmd, "ss"))
		psc_commands_sa_sb(a, b, cmd);
	else if (!ft_strcmp(cmd, "ra") || !ft_strcmp(cmd, "rb") || \
		!ft_strcmp(cmd, "rr"))
		psc_commands_ra_rb(a, b, cmd);
	else if (!ft_strcmp(cmd, "rra") || !ft_strcmp(cmd, "rrb") || \
		!ft_strcmp(cmd, "rrr"))
		psc_commands_rra_rrb(a, b, cmd);
	else if (!ft_strcmp(cmd, "pa"))
		psc_swap_pa_pb(&b, &a);
	else if (!ft_strcmp(cmd, "pb"))
		psc_swap_pa_pb(&a, &b);
	else
		psc_error("Error: wrong cmd");
	free(cmd);
}
