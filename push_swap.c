/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/25 19:43:51 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack stacks, int len_a, int len_b)
{
	stacks.i = 0;
	len_b = push_to_a(&stacks, &len_a, &len_b);
	stacks.top_cost = malloc((len_b) * sizeof(int));
	if (!stacks.top_cost)
		return (free_stacks(stacks));
	while (len_b != 0)
	{
		algorithm_parsing(&stacks, stacks.list_b[stacks.i], len_a, len_b);
		if (stacks.total == stacks.cheapest)
		{
			determine_moves(&stacks, len_a, len_b);
			len_a++;
			push(stacks, 'a', len_a, len_b);
			len_b--;
			stacks.i = 0;
		}
		else
			stacks.i++;
	}
	free(stacks.top_cost);
	finish_sorting(stacks, len_a);
}

void	finish_sorting(t_stack stacks, int len_a)
{
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
	else if ((first < second) && (second > third) && (third > first))
	{
		reverse_rotate(stacks, 'a', len_a, 0);
		swap(stacks, 'a');
	}
	else if ((first < second) && (second > third) && (first > third))
		reverse_rotate(stacks, 'a', len_a, 0);
	else if ((first > second) && (second < third))
		swap(stacks, 'a');
}

void	free_stacks(t_stack stacks)
{
	free(stacks.list_a);
	free(stacks.list_a);
	return ;
}

int	push_to_a(t_stack *stacks, int *len_a, int *len_b)
{
	while (*len_a > 3)
	{
		(*len_b)++;
		push(*stacks, 'b', *len_a, *len_b);
		(*len_a)--;
	}
	small_sort(*stacks, *len_a);
	return (*len_b);
}
