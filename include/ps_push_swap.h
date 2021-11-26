/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:17:19 by cdarrell          #+#    #+#             */
/*   Updated: 2021/11/01 20:04:26 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_PUSH_SWAP_H
# define PS_PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <math.h>
# include <stdlib.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
	unsigned int	num;
	int				sort;
	int				value;
	int				in_b;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_dl_list
{
	int		size;
	t_node	*head;
	t_node	*tail;
}t_dl_list;

typedef struct s_stacks
{
	t_dl_list	*a;
	t_dl_list	*b;
	t_list		*cmd;
	int			sorted;
	int			unsorted;
	int			size_list;
}t_stacks;

//parsing
void	ps_parsing_list(t_dl_list *a, int size, char **num_arr);
int		*ps_parsing_array(int size, char **num_arr);

//operations
void	ps_comands(t_stacks *data, char *str_cmd);
int		ps_swap_sa_sb(t_dl_list **lst);
int		ps_swap_ra_rb(t_dl_list **lst);
int		ps_swap_rra_rrb(t_dl_list **lst);
int		ps_swap_pa_pb(t_dl_list **from, t_dl_list **to);
void	optimization(t_list **cmd);

//sort
void	ps_sort_six(t_stacks *data);
void	ps_sort_all_first_a_to_b(t_stacks *data);
void	ps_sort_all_b_five(t_stacks *data);
void	ps_sort_all_a_five(t_stacks *data);
void	ps_sort_all_a_to_b(t_stacks *data);
void	ps_sort_all_b_to_a(t_stacks *data);

//units
void	ps_error(char *str);
int		ps_check_sort(t_dl_list *lst);
int		ps_find_same_in_b_into_a(const t_node *tmp);
void	ps_sort_three_min_max_b(t_stacks *data);
void	ps_sort_a_head_to_a_tail(t_stacks *data);

#endif
