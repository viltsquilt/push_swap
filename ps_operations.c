/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:02:30 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/04 16:45:24 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	int	i;

	i = 0;

}

void	swap(t_stack *src, t_stack *dest)
{
	int	temp;

	temp = *src;
	*src = *dest;
	*dest = temp;
}

void	rotate(t_stack *stacks, int type)
{
	int	temp;
	int	i;
	int	*array;

	i = 0;
	if (type == 1)
		array = stacks->list_a;
	else if (type == 2)
		array = stacks->list_b;
	temp = array[i];
	while (array[i + 1])
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = temp;
}

void	reverse_rotate(t_stack *stacks, int type)
{
	int	temp;
	size_t	len;
	int	*array;

	if (type == 1)
	{
		len = stacks->size_a;
		array = stacks->list_a;
	}
	else if (type == 2)
	{
		len = stacks->size_b;
		array = stacks->list_b;
	}
	temp = array[len];
	while (array[len - 1] >= 0)
	{
		array[len] = array[len - 1];
		len--;
	}
	array[len] = temp;
}
