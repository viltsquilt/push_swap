/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:00:58 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/06 14:29:08 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// write the algorithm
/*
void	push_swap(t_stack *stacks)
{

}
*/
void	small_sort(t_stack stacks)
{
	int			i;
	int	*first;
	int	*second;
	int	*third;

	i = 0;
	first = &stacks.list_a[i];
	second = &stacks.list_a[i + 1];
	third = &stacks.list_a[i + 2];
	if ((first > second) && (second > third))
	{
		swap(stacks, 'a');
		reverse_rotate(stacks, 'a');
	}
	else if ((first > second) && (second < third))
		rotate(stacks, 'a');
	else if ((first < second) && (second > third))
		{
			push(stacks, 'b');
			swap(stacks, 'a');
			push(stacks, 'a');
		}
	else if ((first > second) && (second < third))
		swap(stacks, 'a');
	return;
}
