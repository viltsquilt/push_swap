/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/29 16:26:56 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// write functions for all operations

// swap

// push

// rotate

// reverse rotate


// write the algorithm

// write a function that sorts a stack of 3
void	push_swap(t_stack *a, t_stack *b)
{

}

void	small_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	*first;
	int	*second;
	int	*third;

	i = 0;
	first = a->list[i];
	second = a->list[i + 1];
	third = a->list[i + 2];
	if ((first > second) && (second > third))
	{
		swap(&first, &second);
		reverse_rotate(&a, &b);
	}
	else if ((first > second) && (second < third))
		rotate(&a, &b);
	else if ((first < second) && (second > third))
		{
			// push b then swap a then push a
			push(&b, &a);
			swap(&first, &second);
			push(&a, &b);
		}
	else if ((first > second) && (second < third))
		swap(&first, &second);
	return;
}

void	array_type(t_stack *a)
{
	t_stack	*b;
	int	i;

	i = 0;
	while (a->list[i])
		i++;
	a->size = i;
//code for array for 2 also
	if (a->size == 3)
		small_sort(&a, &b);
	else
		push_swap(&a, &b);
}
