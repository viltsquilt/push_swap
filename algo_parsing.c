/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/23 18:04:12 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm_parsing(t_stack *stacks, int num, int len_a, int len_b)
{
	stacks->smallest_a = find_smallest(*stacks, len_a);
	stacks->biggest_a = find_biggest(*stacks, len_a);
	stacks->top_cost = move_to_top_costs(*stacks, len_a, len_b);
	stacks->cheapest = find_cheapest(*stacks, len_b);
	stacks->target = find_target(*stacks, num, len_a);
	stacks->index_a = find_index(*stacks, stacks->target, 1, len_a);
	stacks->index_b = find_index(*stacks, num, 2, len_b);
	stacks->cost_a = calculate_cost(*stacks, 1, len_a);
	stacks->cost_b = calculate_cost(*stacks, 2, len_b);
	stacks->total = (stacks->cost_a + stacks->cost_b);
}

void	determine_moves(t_stack *stacks, int len_a, int len_b)
{
	if (((stacks->cost_a  == stacks->index_a) &&
		(stacks->cost_b == stacks->index_b)) &&
		(stacks->index_a == stacks->index_b))
		double_move(*stacks, 1, len_a, len_b);
	else if (((stacks->cost_a != stacks->index_a) &&
		(stacks->cost_b != stacks->index_b)) &&
		(stacks->cost_b == stacks->cost_a))
		double_move(*stacks, 2, len_a, len_b);
	else if ((stacks->cost_a == stacks->index_a) &&
		(stacks->cost_b == stacks->index_b) &&
		(stacks->index_a != stacks->index_b))
		move_same_direction(*stacks, 1, len_a, len_b);	
	else if ((stacks->cost_a != stacks->index_a) &&
		(stacks->cost_b != stacks->index_b) &&
		(stacks->cost_a != stacks->cost_b))
		move_same_direction(*stacks, 2, len_a, len_b);
	else if ((stacks->cost_a == stacks->index_a) &&
		(stacks->cost_b != stacks->index_b))
		move_different_direction(*stacks, 1, len_a, len_b);
	else
		move_different_direction(*stacks, 2, len_a, len_b);
}

void	double_move(t_stack stacks, int type, int len_a, int len_b)
{
	if (type == 1)
	{
		while (stacks.index_a > 0)
		{
			rotate(stacks, 'x', len_a, len_b);
			stacks.index_a--;
		}
	}
	else
	{
		while (stacks.cost_a > 0)
		{
			reverse_rotate(stacks, 'x', len_a, len_b);
			stacks.cost_a--;
		}
	}
}

void	move_same_direction(t_stack stacks, int type, int len_a, int len_b)
{
	if (type == 1)
	{
		while (stacks.index_a > 0)
		{
			rotate(stacks, 'a', len_a, 0);
			stacks.index_a--;
		}
		while (stacks.index_b > 0)
		{
			rotate(stacks, 'b', 0, len_b);
			stacks.index_b--;
		}
	}
	else
	{
		while (stacks.cost_a > 0)
		{
			reverse_rotate(stacks, 'a', len_a, 0);
			stacks.cost_a--;
		}
		while (stacks.cost_b > 0)
		{
			reverse_rotate(stacks, 'b', 0, len_b);
			stacks.cost_b--;
		}
	}
}

void	move_different_direction(t_stack stacks, int type, int len_a, int len_b)
{
	if (type == 1)
	{
		while (stacks.index_a > 0)
		{
			rotate(stacks, 'a', len_a, 0);
			stacks.index_a--;
		}
		while (stacks.cost_b > 0)
		{
			reverse_rotate(stacks, 'b', 0, len_b);
			stacks.cost_b--;
		}
	}
	else
	{
		while (stacks.cost_a > 0)
		{
			reverse_rotate(stacks, 'a', len_a, 0);
			stacks.cost_a--;
		}
		while (stacks.index_b > 0)
		{
			rotate(stacks, 'b', 0, len_b);
			stacks.index_b--;
		}
	}
}
/*	
		len_a++;
		push(stacks, 'a', len_a, len_b);
		len_b--;
		j = 0;
	}
	else
		j++;
}
	free(stacks.top_cost);
	stacks.smallest_a = find_smallest(stacks, len_a);
	stacks.index_a = find_index(stacks, stacks.smallest_a, 1, len_a);
	stacks.cost_a = calculate_cost(stacks, 1, len_a);
	if (stacks.cost_a == stacks.index_a)
	{
		while (stacks.index_a > 0)
		{
			rotate(stacks, 'a', len_a, 0);
			stacks.index_a--;
		}
	}
	else
	{
		while (stacks.cost_a > 0)
		{
			reverse_rotate(stacks, 'a', len_a, 0);
			stacks.cost_a--;
		}
	}
}*/
