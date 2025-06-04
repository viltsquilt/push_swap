/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/04 16:18:39 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// write the algorithm

void	push_swap(t_stack *a, t_stack *b)
{

}

void	small_sort(t_stack *stacks)
{
	int	i;
	int	*first;
	int	*second;
	int	*third;

	i = 0;
	first = stacks->list_a[i];
	second = stacks->list_a[i + 1];
	third = stacks->list_a[i + 2];
	if ((first > second) && (second > third))
	{
		swap(&first, &second);
		reverse_rotate(stacks->list_a);
	}
	else if ((first > second) && (second < third))
		rotate(stacks->list_a);
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
