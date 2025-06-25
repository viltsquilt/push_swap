/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targeting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:10:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/25 19:52:30 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest(t_stack stacks, int len)
{
	int	smallest;
	int	i;

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

int	find_biggest(t_stack stacks, int len)
{
	int	biggest;
	int	i;

	i = 0;
	biggest = stacks.list_a[i];
	while (i < (len - 1))
	{
		i++;
		if (biggest < stacks.list_a[i])
			biggest = stacks.list_a[i];
	}
	return (biggest);
}

int	find_index(t_stack stacks, int num, int type, int len)
{
	int	i;

	i = 0;
	if (type == 1)
	{
		while (i < len)
		{
			if (stacks.list_a[i] == num)
				return (i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			if (stacks.list_b[i] == num)
				return (i);
			i++;
		}
	}
	return (i);
}

int	find_target(t_stack stacks, int num, int len_a)
{
	int	i;

	i = 0;
	stacks.smallest_a = find_smallest(stacks, len_a);
	stacks.biggest_a = find_biggest(stacks, len_a);
	stacks.target = stacks.list_a[i];
	while (i < (len_a - 1))
	{
		i++;
		if (stacks.biggest_a < num)
			return (stacks.smallest_a);
		if (((stacks.list_a[i] > num)
				&& (stacks.list_a[i] < stacks.target)
				&& (stacks.target > num))
			|| (stacks.target < num))
		{
			stacks.target = stacks.list_a[i];
		}
	}
	return (stacks.target);
}
