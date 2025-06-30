/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:56:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/30 14:02:13 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

/*
./push_swap ""
./push_swap " "
./push_swap "1 s"
./push_swap 1 --------------5 4;
./push_swap 1 +-5 4
./push_swap 2147483648
./push_swap -2147483649
./push_swap 1 2 1
./push_swap <-- should not print Error
./push_swap "7 0 1" 2 
stacks.list_b = NULL; //malloc((stacks.size_a) * (sizeof(int))); leaking,
./push_swap 6 2 3 5 stacks->list_a = NULL; //malloc((stacks->size_a) * (sizeof(int))); segfault,
./push_swap "6 2 3 5" stacks->list_b = NULL; //malloc((stacks->size_a) * (sizeof(int))); segfault,
./push_swap "6 2 3 5" stacks.top_cost = NULL; //malloc((len_b) * sizeof(int)); invalid free
*/

typedef struct s_stack
{
	size_t		i;
	size_t		size_a;
	size_t		size_b;
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
	int			len_a;
	int			len_b;
	long		nb;
	char		**split;
}	t_stack;

// push swap

int		push_to_a(t_stack *stacks, int *len_a, int *len_b);
void	finish_sorting(t_stack stacks, int len_a);
void	free_stacks(t_stack stacks);
void	small_sort(t_stack stacks, int len_a);
void	push_swap(t_stack stacks, int len_a, int len_b);

// algorithm logic

void	determine_moves(t_stack *stacks, int len_a, int len_b);
void	double_move(t_stack stacks, int type, int len_a, int len_b);
void	move_same_direction(t_stack stacks, int type, int len_a, int len_b);
void	move_diff_direction(t_stack stacks, int type, int len_a, int len_b);
void	algorithm_parsing(t_stack *stacks, int num, int len_a, int len_b);

// targeting

int		find_smallest(t_stack stacks, int len);
int		find_biggest(t_stack stacks, int len);
int		find_index(t_stack stacks, int num, int type, int len);
int		find_target(t_stack stacks, int num, int len_a);

// cost sorting

int		*move_to_top_costs(t_stack stacks, int len_a, int len_b);
int		find_cheapest(t_stack stacks, int len);
int		calculate_cost(t_stack stacks, int type, int len);
int		issorted(t_stack stacks, int len_a);

// main and input parsing

int		ps_atol(t_stack stacks, char *nptr);
int		error_handling(t_stack stacks, int type);
int		split_and_allocate(t_stack *stacks);
int		send_it(t_stack stacks);
int		check_isduplicate(t_stack stacks);
int		multi_input(int ac, char **av);
int		ps_arraylen(char **split);
int		main(int argc, char **argv);
void	ps_free(char **array);

// calls to operations and operations

void	push(t_stack stacks, char c, int len_a, int len_b);
void	swap(t_stack stacks, char c);
void	rotate(t_stack stacks, char c, int len_a, int len_b);
void	reverse_rotate(t_stack stacks, char c, int len_a, int len_b);
void	push_operation(t_stack stacks, int type, int len_a, int len_b);
void	swap_operation(t_stack stacks, int type);
void	rotate_operation(t_stack stacks, int type, int len);
void	reverse_rotate_operation(t_stack stacks, int type, int len);

#endif
