/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:10:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/20 16:57:42 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(t_stack stacks, int type, int len) // Use flags for r and rr?
{
	if (type == 1)
	{
		if (stacks.index_a <= (len / 2)) //Rotate
			return (stacks.index_a);
		else
			return (len - stacks.index_a); //Reverse rotate
	}
	else
	{
		if (stacks.index_b <= (len / 2)) //Rotate
			return (stacks.index_b);
		else
			return (len - stacks.index_b); //Reverse rotate
	}
}

int find_smallest(t_stack stacks, int len)
{
	int smallest;
	int i;

	i = 0;
	smallest = stacks.list_a[i];
	while (i < (len - 1))
	{
		i++;
		if (smallest > stacks.list_a[i])
			smallest = stacks.list_a[i];
	}
	return (smallest);
}

int find_biggest(t_stack stacks, int type, int len)
{
	int biggest;
	int i;

	i = 0;
	if (type == 1)
	{
		biggest = stacks.list_a[i];
//		while (stacks.list_a[i] < len)
		while (i < (len - 1))
		{
			i++;
			if (biggest < stacks.list_a[i])
				biggest = stacks.list_a[i];
		}
	}
	else
	{
		biggest = stacks.list_b[i];
//		while (stacks.list_b[i] < len)
		while (i < (len - 1))
		{
			i++;
			if (biggest < stacks.list_b[i])
				biggest = stacks.list_b[i];
		}
	}
	return (biggest);
}

int find_index(t_stack stacks, int num, int type, int len)
{
	int i;

	i = 0;
	if (type == 1)
		while (i < len)
		{
			if (stacks.list_a[i] == num)
				return (i);
			i++;
		}
	else
		while (i < len)
		{
			if (stacks.list_b[i] == num)
				return (i);
			i++;
		}
	return (i);
}

int find_target(t_stack stacks, int num, int len_a, int len_b)
{
	int i;

	i = 0;
	stacks.smallest_a = find_smallest(stacks, len_a);
	stacks.biggest_a = find_biggest(stacks, 1, len_a);
	stacks.biggest_b = find_biggest(stacks, 2, len_b);
	stacks.target = stacks.list_a[i];
	while(i < (len_a - 1)) // We want to loop through stack a to find the target for the node in stack b
	{
		i++;
//		if ((stacks.smallest_a == stacks.target) &&
//			(stacks.biggest_a < stacks.biggest_b)) // If biggest node is in stack b, we want to save it to push it on top of smallest a later
//			return (stacks.target); // Target for smallest node in a is biggest node if in stack b
		if ((stacks.biggest_a < stacks.biggest_b) && (stacks.biggest_b == num))
			return (stacks.smallest_a);
		if (((stacks.list_a[i] > num) && 
			(stacks.list_a[i] < stacks.target) && (stacks.target > num))
			|| (stacks.target < num))
		{
			stacks.target = stacks.list_a[i];
//			stacks.target = stacks.list_a[i]; // We save the first bigger element to temp
//			if ((stacks.list_a[i++]) && (stacks.list_a[i++] < stacks.target) &&
//				(stacks.list_a[i++] > num)) // Check for smaller bigger and replace if found
//				stacks.target = stacks.list_a[i++];
		}
	}
	return (stacks.target);
}
