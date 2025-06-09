/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/09 18:41:20 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// write the algorithm

void	push_swap(t_stack *stacks)
{
	int	i;
	int	j;
	int	k;
	int	temp;
	int	*pairs_b;

	i = 0;
	k = 0;
	temp = 0;
//	push every variable to stack b until there are ony 3 variables left in stack a
	while(stack.size_a > 3)
		push(stacks, 'b');

//	sort the three numbers in stack a
	small_sort(stacks);

/*	find the "smallest bigger" in stack a for each number in stack b
	if the number in stack b is bigger than all numbers in stack a, we push it on
	top of the smallest number in stack a*/
	while(stack.list_b[i])
	{
		j = 0;
		while(stack.list_a[j])
		{
			if(stack.list_a[i] < stack.list_b[j])
				j++;
			else
			{
				pairs_b[k] = stack.list_a[j];
				j++;
				if (stack.list_a[j] > pairs_b[k])
					j++;
				else if ((stack.list_a[j] < pairs_b[k]) && (stack.list_a[j] > stack.list_b[i]))
					pairs_b[k] = stack.list_b[j];
			}
			j++;

		}
		k++;
		i++;
	}
//	Calculate "bring to top cost" for every node in stack a and b

//	To use rotate or reverse rotate to bring to top: number of nodes / 2
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
