/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:56:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/25 15:40:22 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_stack
{
	int			i;
	int			errorflag;
	int			minusflag;
	int			temp;
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
	int			total;
	size_t		size_a;
	size_t		size_b;
	int			len_a;
	int			len_b;
	long		nb;
	char		**split;
}	t_stack;

int		ps_arraylen(char **split);
int		main(int argc, char **argv);
int     ps_atol(t_stack stacks, char *nptr);
int		calculate_cost(t_stack stacks, int type, int len);
int		find_smallest(t_stack stacks, int len);
int		find_biggest(t_stack stacks, int len);
int		find_index(t_stack stacks, int num, int type, int len);
int		find_target(t_stack stacks, int num, int len_a);
int		size(t_stack stacks, int type);
int		*move_to_top_costs(t_stack stacks, int len_a, int len_b);
int		find_cheapest(t_stack stacks, int len);
int		error_handling(t_stack stacks, int type);
int		check_isduplicate(int *array, int num);
int		multi_input(int ac, char **av);
int		split_and_allocate(t_stack *stacks);
int		send_it(t_stack stacks);
void	finish_sorting(t_stack stacks, int len_a);
void	free_stacks(t_stack stacks);
void	ps_free(char **array);
void	determine_moves(t_stack *stacks, int len_a, int len_b);
void	double_move(t_stack stacks, int type, int len_a, int len_b);
void	move_same_direction(t_stack stacks, int type, int len_a, int len_b);
void	move_different_direction(t_stack stacks, int type, int len_a, int len_b);
void	algorithm_parsing(t_stack *stacks, int num, int len_a, int len_b);
void	small_sort(t_stack stacks, int len_a);
void	push_swap(t_stack stacks, int len_a, int len_b);
void	push(t_stack stacks, char c, int len_a, int len_b);
void	swap(t_stack stacks, char c);
void	rotate(t_stack stacks, char c, int len_a, int len_b);
void	reverse_rotate(t_stack stacks, char c, int len_a, int len_b);
void	push_operation(t_stack stacks, int type, int len_a, int len_b);
void	swap_operation(t_stack stacks, int type);
void	rotate_operation(t_stack stacks, int type, int len);
void	reverse_rotate_operation(t_stack stacks, int type, int len);
int		push_to_a(t_stack *stacks, int *len_a, int *len_b);

#endif
