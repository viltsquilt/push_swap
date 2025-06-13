/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:56:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/13 11:32:06 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_stack
{
	int			*list_a;
	int			*list_b;
	int			smallest_a;
	int			biggest_a;
	int			biggest_b;
	int			cheapest;
	int			target;
	int			index_a;
	int			index_b;
	int			cost_a;
	int			cost_b;
	int			*top_cost;
	size_t		size_a;
	size_t		size_b;
}	t_stack;

int		main(int argc, char **argv);
int     ps_atol(char *nptr);
int		calculate_cost(t_stack stacks, int type);
int		find_smallest(t_stack stacks);
int		find_biggest(t_stack stacks, int type);
int		find_index(t_stack stacks, int num, int type);
int		find_target(t_stack stacks, int num);
int		size(t_stack stacks, int type);
void	small_sort(t_stack stacks);
void	push_swap(t_stack stacks);
void	push(t_stack stacks, char c);
void	swap(t_stack stacks, char c);
void	rotate(t_stack stacks, char c);
void	reverse_rotate(t_stack stacks, char c);
void	push_operation(t_stack stacks, int type);
void	swap_operation(t_stack stacks, int type);
void	rotate_operation(t_stack stacks, int type);
void	reverse_rotate_operation(t_stack stacks, int type);

#endif
