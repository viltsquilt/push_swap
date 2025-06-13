/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/13 13:37:14 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack stacks)
{
	int	i;
	int	j;

	i = 0;
	while(stacks.size_a > 3) // push b until only 3 nodes left in stack a
	{
		push(stacks, 'b');
		stacks.size_a = size(stacks, 1);
	}
	small_sort(stacks); // sort the three numbers left in stack a
	stacks.smallest_a = find_smallest(stacks); // We want to find the smallest node in stack a
	stacks.biggest_a = find_biggest(stacks, 1);
	stacks.biggest_b = find_biggest(stacks, 2);
	while (stacks.list_b[i])
	{
		stacks.target = find_target(stacks, stacks.list_b[i]); // We want to find smallest bigger in stack a for stack b
		stacks.index_a = find_index(stacks, stacks.target, 1);
		stacks.index_b = find_index(stacks, stacks.list_b[i], 2);
		stacks.cost_a = calculate_cost(stacks, 1);
		stacks.cost_b = calculate_cost(stacks, 2);
		stacks.top_cost[i] = (stacks.cost_a + stacks.cost_b); // calculate and store costs for moving pairs to top
		j = 0;
		stacks.cheapest = stacks.top_cost[j]; // We reset cheapest every time because we want to compare it to all costs as we calculate them
		while (stacks.top_cost[j])
		{
			j++;
			if (stacks.cheapest >= stacks.top_cost[j])
				stacks.cheapest = stacks.top_cost[j]; // We have now found the cheapest pair to move to top
		}
		i++;
	}
	j = 0;
	if (size(stacks, 2) != 0) //RECURSION?
	{
		while (stacks.top_cost[j])
		{
			if (stacks.top_cost[j] == stacks.cheapest)
				break;
			else
				j++;
		}
		stacks.target = find_target(stacks, stacks.list_b[j]);
		stacks.index_a = find_index(stacks, stacks.target, 1);
		stacks.index_b = find_index(stacks, stacks.list_b[j], 2);
		stacks.cost_a = calculate_cost(stacks, 1);
		stacks.cost_b = calculate_cost(stacks, 2);
		if (((stacks.cost_a  == stacks.index_a) &&
			(stacks.cost_b == stacks.index_b)) &&
			(stacks.index_a == stacks.index_b))
		{
			while (stacks.cost_a)
			{
				rotate(stacks, 'x'); //rotate both
				stacks.index_a--;
			}
		}
		else if (((stacks.cost_a != stacks.index_a) &&
			(stacks.cost_b != stacks.index_b)) &&
			(stacks.cost_b == stacks.cost_a))
		{
			while (stacks.cost_a)
			{
				reverse_rotate(stacks, 'x'); //reverse rotate both
				stacks.cost_b--;
			}
		}
		else if (stacks.cost_a == stacks.index_a)
		{
			while (stacks.cost_a)
			{
				rotate(stacks, 'a'); //rotate
				stacks.cost_a--;
			}
		}
		else if (stacks.cost_b == stacks.index_b)
		{
			while (stacks.cost_b)
			{
				rotate(stacks, 'b'); //rotate
				stacks.cost_b--;
			}
		}
		else if (stacks.cost_a != stacks.index_a)
		{
			while (stacks.cost_a)
			{
				reverse_rotate(stacks, 'a'); //reverse rotate
				stacks.cost_a--;
			}
		}
		else
		{
			while (stacks.cost_b)
			{
				reverse_rotate(stacks, 'b'); //reverse rotate
				stacks.cost_b--;
			}
		}
		push(stacks, 'a');
		push_swap(stacks);
	}
	stacks.smallest_a = find_smallest(stacks); // Find smallest number in stack a and rorate or reverse rotate to top
	stacks.index_a = find_index(stacks, stacks.smallest_a, 1);
	stacks.cost_a = calculate_cost(stacks, 1);
	if (stacks.cost_a == stacks.index_a)
	{
		while (stacks.cost_a)
		{
			rotate(stacks, 'a'); //rotate
			stacks.cost_a--;
		}
	}
	else
	{
		while (stacks.cost_a)
		{
			reverse_rotate(stacks, 'a'); //reverse rotate
			stacks.cost_a--;
		}
	}
}

void	small_sort(t_stack stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks.list_a[0];
	second = stacks.list_a[1];
	third = stacks.list_a[2];
	if ((first > second) && (second > third))
	{
		swap(stacks, 'a');
		reverse_rotate(stacks, 'a');
	}
	else if ((first > second) && (second < third) && (first > third))
		rotate(stacks, 'a');
	else if ((first > second) && (second < third) && (first < third))
		swap(stacks, 'a');
	else if ((first < second) && (second > third))
	{
		push(stacks, 'b');
		swap(stacks, 'a');
		push(stacks, 'a');
	}
	else if ((first > second) && (second < third))
		swap(stacks, 'a');
}
