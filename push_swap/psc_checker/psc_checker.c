/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:45:16 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/02 16:46:00 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/psc_checker.h"

static int	ps_check_sort(t_dl_list *lst)
{
	t_node	*tmp;

	tmp = lst->head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_dl_list	*psc_init_stack(char str)
{
	t_dl_list	*tmp_stack;

	tmp_stack = (t_dl_list *)malloc(sizeof(t_dl_list));
	if (!tmp_stack)
	{
		if (str == 'a')
			psc_error("Error: no malloc stack A");
		else
			psc_error("Error: no malloc stack B");
	}
	tmp_stack->size = 0;
	tmp_stack->head = NULL;
	tmp_stack->tail = NULL;
	return (tmp_stack);
}

static void	enter_command(t_dl_list	*a, t_dl_list *b)
{
	char	*cmd;
	int		r;

	while (1)
	{
		cmd = ((void *)0);
		r = gnl(0, &cmd);
		if ((r == 0 && !cmd) || r == -1)
			break ;
		psc_commands(a, b, ft_strtrim(cmd, " "));
		free(cmd);
	}
}

void	free_stack(t_node **lst)
{
	t_node	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_dl_list	*a;
	t_dl_list	*b;

	if (argc > 1)
	{
		a = psc_init_stack('a');
		b = psc_init_stack('b');
		psc_parsing_stack_a(a, argc - 1, ++argv);
		if (!ps_check_sort(a))
			enter_command(a, b);
		if (!ps_check_sort(a) || b->size != 0)
			ft_putstr("KO\n");
		else
			ft_putstr("OK\n");
		free_stack(&a->head);
		free_stack(&b->head);
		free(a);
		free(b);
	}
	return (0);
}
