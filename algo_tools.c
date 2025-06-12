/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:10:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/12 16:37:51 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calculate_cost(t_stack stacks, int type) // Use flags for r and rr?
{
	if (type == 1)
	{
		if (stacks.index_a <= size(stacks, 1) / 2) //Rotate
			return (stacks.index_a);
		else
			return (size(stacks, 1) - stacks.index_a); //Reverse rotate
	}
	else
	{
		if (stacks.index_b <= size(stacks, 2) / 2) //Rotate
			return (stacks.index_b);
		else
			return (size(stacks, 2) - stacks.index_b); //Reverse rotate
	}
}

int find_smallest(t_stack stacks)
{
	int smallest;
	int i;

	i = 0;
	smallest = stacks.list_a[i];
	while (stacks.list_a[i])
	{
		i++;
		if (smallest > stacks.list_a[i])
			smallest = stacks.list_a[i];
	}
	return (smallest);
}

int find_biggest(t_stack stacks)
{
	int biggest;
	int i;

	i = 0;
	if (type == 1)
	{
		biggest = stacks.list_a[i];
		while (stacks.list_a[i])
		{
			i++;
			if (biggest < stacks.list_a[i])
				biggest = stacks.list_a[i];
		}
	}
	else
	{
		biggest = stacks.list_b[i];
		while (stacks.list_b[i])
		{
			i++;
			if (biggest < stacks.list_b[i])
				biggest = stacks.list_b[i];
		}
	}
	return (biggest);
}

int find_index(t_stack stacks, int num, int type)
{
	int i;

	i = 0;
	if (type == 1)
		while (stacks.list_a[i])
		{
			if (stacks.list_a[i] == num)
				return (i);
			i++;
		}
	else
		while (stacks.list_b[i])
		{
			if (stacks.list_b[i] == num)
				return (i);
			i++;
		}
	return (i);
}

int find_target(t_stack stacks, int num)
{
	int i;

	i = 0;
	while(stacks.list_a[i]) // We want to loop through stack a to find the target for the node in stack b
	{
		if ((stacks.smallest_a == stacks.list_a[i]) &&
			(stacks.biggest_a < stacks.biggest_b)) // If biggest node is in stack b, we want to save it to push it on top of smallest a later
			return (stacks.target = stacks.smallest_a); // Target for smallest node in a is biggest node if in stack b
		if (stacks.list_a[i] > num)
			stacks.target = stacks.list_a[i]; // We save the first bigger element to temp
		i++;
		if ((stacks.list_a[i] < stacks.target) && (stacks.list_a[i] > num)) // Check for smaller bigger and replace if found
			stacks.target = stacks.list_a[i];
		i++;
	}
	return (stacks.target);
}
