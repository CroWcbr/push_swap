/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psc_checker.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:47:18 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 16:18:53 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSC_CHECKER_H
# define PSC_CHECKER_H

# include "../libft/include/libft.h"
# include <math.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_dl_list
{
	int		size;
	t_node	*head;
	t_node	*tail;
}t_dl_list;

//cheker
void	psc_parsing_stack_a(t_dl_list *a, int size, char **num_arr);

//operations
void	psc_commands(t_dl_list *a, t_dl_list *b, char *cmd);
void	psc_swap_sa_sb(t_dl_list **lst);
void	psc_swap_ra_rb(t_dl_list **lst);
void	psc_swap_rra_rrb(t_dl_list **lst);
void	psc_swap_pa_pb(t_dl_list **from, t_dl_list **to);

//help
void	psc_error(char *str);

#endif
