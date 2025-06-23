/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/23 13:19:34 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack stacks, int len_a, int len_b)
{
	int	j;


	while(len_a > 3) // push b until only 3 nodes left in stack a
	{
		len_b++;
		push(stacks, 'b', len_a, len_b);
		len_a--;
	}
	small_sort(stacks, len_a); // sort the three numbers left in stack a
	stacks.top_cost = malloc((len_b) * sizeof(int));
	if (!stacks.top_cost)
	{
		free(stacks.list_a);
		free(stacks.list_b);
		return ;
	}
	j = 0;
	while (len_b != 0)
	{
		stacks.smallest_a = find_smallest(stacks, len_a); // We want to find the smallest node in stack a
		stacks.biggest_a = find_biggest(stacks, 1, len_a);
		stacks.biggest_b = find_biggest(stacks, 2, len_b); 
		stacks.top_cost = move_to_top_costs(stacks, len_a, len_b);
		stacks.cheapest = find_cheapest(stacks, len_b);
		stacks.target = find_target(stacks, stacks.list_b[j], len_a, len_b);
		stacks.index_a = find_index(stacks, stacks.target, 1, len_a);
		stacks.index_b = find_index(stacks, stacks.list_b[j], 2, len_b);
		stacks.cost_a = calculate_cost(stacks, 1, len_a);
		stacks.cost_b = calculate_cost(stacks, 2, len_b);
		stacks.total = (stacks.cost_a + stacks.cost_b);
		if (stacks.total == stacks.cheapest)
		{
			if (((stacks.cost_a  == stacks.index_a) &&
				(stacks.cost_b == stacks.index_b)) &&
				(stacks.index_a == stacks.index_b))
			{
				while (stacks.index_a > 0)
				{
					rotate(stacks, 'x', len_a, len_b); //rotate both
					stacks.index_a--;
				}
			}
			else if (((stacks.cost_a != stacks.index_a) &&
				(stacks.cost_b != stacks.index_b)) &&
				(stacks.cost_b == stacks.cost_a))
			{
				while (stacks.cost_a > 0)
				{
					reverse_rotate(stacks, 'x', len_a, len_b); //reverse rotate both
					stacks.cost_a--;
				}
			}
			else if ((stacks.cost_a == stacks.index_a) &&
				(stacks.cost_b == stacks.index_b) &&
				(stacks.index_a != stacks.index_b))
			{
				while (stacks.index_a > 0)
				{
					rotate(stacks, 'a', len_a, 0); //rotate
					stacks.index_a--;
				}
				while (stacks.index_b > 0)
				{
					rotate(stacks, 'b', 0, len_b);
					stacks.index_b--;
				}
			}
			else if ((stacks.cost_a != stacks.index_a) &&
				(stacks.cost_b != stacks.index_b) &&
				(stacks.cost_a != stacks.cost_b))
			{
				while (stacks.cost_a > 0)
				{
					reverse_rotate(stacks, 'a', len_a, 0); //reverse rotate
					stacks.cost_a--;
				}
				while (stacks.cost_b > 0)
				{
					reverse_rotate(stacks, 'b', 0, len_b);
					stacks.cost_b--;
				}
			}
			else if ((stacks.cost_a == stacks.index_a) &&
				(stacks.cost_b != stacks.index_b))
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
			len_a++;
			push(stacks, 'a', len_a, len_b);
			len_b--;
			j = 0;
		}
		else
			j++;
	}
	free(stacks.top_cost);
	stacks.smallest_a = find_smallest(stacks, len_a); // Find smallest number in stack a and rorate or reverse rotate to top
	stacks.index_a = find_index(stacks, stacks.smallest_a, 1, len_a);
	stacks.cost_a = calculate_cost(stacks, 1, len_a);
	if (stacks.cost_a == stacks.index_a)
	{
		while (stacks.index_a > 0)
		{
			rotate(stacks, 'a', len_a, 0); //rotate
			stacks.index_a--;
		}
	}
	else
	{
		while (stacks.cost_a > 0)
		{
			reverse_rotate(stacks, 'a', len_a, 0); //reverse rotate
			stacks.cost_a--;
		}
	}
}
void	small_sort(t_stack stacks, int len_a)
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
		reverse_rotate(stacks, 'a', len_a, 0);
	}
	else if ((first > second) && (second < third) && (first > third))
		rotate(stacks, 'a', len_a, 0);
	else if ((first > second) && (second < third) && (first < third))
		swap(stacks, 'a');
	else if ((first < second) && (second > third))
	{
		if (third > first)
		{
			reverse_rotate(stacks, 'a', len_a, 0);
			swap(stacks, 'a');
		}
		else
			reverse_rotate(stacks, 'a', len_a, 0);
	}
	else if ((first > second) && (second < third))
		swap(stacks, 'a');
}
