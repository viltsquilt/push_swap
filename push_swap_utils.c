/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:07:00 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/11 15:41:23 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ps_atol(char *nptr)
{
	int	i;
	int	minusflag;
	long	nb;

	i = 0;
	minusflag = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minusflag = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	nb *= minusflag;
	if (nptr[i] == '\0')
		return (nb);
//	if (nb > INT_MAX || nb <= INT_MIN)
//		exit (1);
	return (nb);
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

int	*find_targets(t_stack stacks, int num) // NEEDS TO BE CHANGED
{
	int	a_index;
	int	b_index;
	int	i;

	i = 0;
	b_index = 0;
	while(stacks.list_b[b_index]) // We  loop through stack b
	{                                                                            
		a_index = 0; // We want to reset stack a every time because multiple numbers in stack b can have the same smallest bigger
		while(stacks.list_a[a_index]) // Inside stack b loop, we loop through stack a for every element of stack b
		{
			if(stacks.list_a[a_index] > stacks.list_b[b_index])
				targets[i] = stacks.list_a[a_index]; // We save the first bigger element to a temp array
			a_index++;
			if ((stacks.list_a[a_index] < targets[i]) &&
				(stacks.list_a[a_index] > stacks.list_b[b_index])) // Check for smaller bigger and replace if found
					targets[i] = stacks.list_a[a_index];
			a_index++;
		}
		i++;
		b_index++;
	}
	return (targets);
}
