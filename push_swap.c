/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/11 15:41:26 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack stacks)
{
	int	a_index;
	int	b_index;
	int	i;

	i = 0;
	
	while(stacks.size_a > 3) // push b until only 3 nodes left in stack a
		push(stacks, 'b');
	small_sort(stacks); // sort the three numbers left in stack a
	while (stacks.list_b[b_index])
	{
		target = find_targets(stacks, stacks.list_b[b_index]); // We want to find smallest bigger in stack a for stack b
		// find index for target in stack a
		index_a = find_index(stacks, target, 1);
		index_b = find_index(stacks, stacks.list_b, 2);
		// calculate and store costs for moving pairs to top
	}
	smallest_a = find_smallest(stacks); // We want to find the smallest node in stack a
	biggest_a = find_biggest(stacks, 1);
	biggest_b = find_biggest(stacks, 2);
	if (biggest_a < biggest_b) // If biggest node is in stack b, we want to save it to push it on top of smallest a later
	{
		while (targets[i])
			i++;
		targets[i] = smallest_a; // Targets now has all of our "target nodes"
	}

//	Calculate "bring to top cost" for every node in stack a and b
	
//	if the index is in the first half (index <= nodes / 2) we use rotate,
//	otherwise we use reverse rotate

	if (node index number <= number of nodes / 2)
		bring to top cost = node index number;
	else
		bring to top cost = total number of nodes - node index number;
	
//	find the "cheapest node" ie. the operation with the lowest total cost to push to stack a
//	using rotate,reverse rotate, or rotate both

//	repeat

//	Find smallest number in stack a and rotate (or reverse rotate) until it is at the top

//	Sorted
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
