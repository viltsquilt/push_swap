/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:02:30 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/13 13:28:06 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_operation(t_stack stacks, int type)
{
	int	i;
	int	*src;
	int	*dest;

	i = 0;
	if (type == 2)
	{
		src = &stacks.list_a[i];
		dest = &stacks.list_b[i];
		reverse_rotate_operation(stacks, 2);
		*dest = *src;
		rotate_operation(stacks, 1);
	}
	else
	{
		src = &stacks.list_b[i];
		dest = &stacks.list_a[i];
		reverse_rotate_operation(stacks, 1);
		*dest = *src;
		reverse_rotate_operation(stacks, 2);
	}
}

void	swap_operation(t_stack stacks, int type)
{
	int	temp;
	int	*src;
	int	*dest;
	int	i;

	i = 0;
	if (type == 1)
	{
		src = &stacks.list_a[i];
		dest = &stacks.list_a[i + 1];
	}
	else
	{
		src = &stacks.list_b[i];
		dest = &stacks.list_b[i + 1];
	}
	temp = *src;
	*src = *dest;
	*dest = temp;
}

void	rotate_operation(t_stack stacks, int type)
{
	int	temp;
	int	i;
	int	*array;

	i = 0;
	if (type == 1)
		array = stacks.list_a;
	else
		array = stacks.list_b;
	temp = array[i];
	while (array[i + 1])
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = temp;
}

void	reverse_rotate_operation(t_stack stacks, int type)
{
	int	temp;
	size_t	len;
	int	*array;

	if (type == 1)
	{
		len = size(stacks, 1);
		array = stacks.list_a;
	}
	else
	{
		len = size(stacks, 2);
		array = stacks.list_b;
	}
	temp = array[len];
	while (array[len - 1] > 0)
	{
		array[len] = array[len - 1];
		len--;
	}
	array[len] = temp;
}
