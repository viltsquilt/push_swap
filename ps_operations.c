/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:02:30 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/18 11:32:00 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_operation(t_stack stacks, int type, int len_a, int len_b)
{
	int	i;
	int	temp;

	i = 0;
	if (type == 2)
	{
		temp = stacks.list_a[i];
		reverse_rotate_operation(stacks, 2, len_b);
		stacks.list_b[i] = temp;
		rotate_operation(stacks, 1, len_a);
//		len_a--;
	}
	else
	{
		temp = stacks.list_b[i];
		reverse_rotate_operation(stacks, 1, len_a);
		stacks.list_a[i] = temp;
		rotate_operation(stacks, 2, len_b);
//		len_b--;
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

void	rotate_operation(t_stack stacks, int type, int len)
{
	int	temp;
	int	i;

	i = 0;
	if (type == 1)
	{
		temp = stacks.list_a[i];
//		while (stacks.list_a[i + 1] < len)
		while ((i + 1) < len)
		{
			stacks.list_a[i] = stacks.list_a[i + 1];
			i++;
		}
		stacks.list_a[i] = temp;
	}
	else
	{
		temp = stacks.list_b[i];
//		while (stacks.list_b[i + 1] < len)
		while ((i + 1) < len)
		{
			stacks.list_b[i] = stacks.list_b[i + 1];
			i++;
		}
		stacks.list_b[i] = temp;
	}
}

void	reverse_rotate_operation(t_stack stacks, int type, int len)
{
	int	temp;
	int	i;

	i = len - 1;
	if (type == 1)
	{
		temp = stacks.list_a[i];
//		while (stacks.list_a[len - 1] > 0)
		while ((i - 1) >= 0)
		{
			stacks.list_a[i] = stacks.list_a[i - 1];
			i--;
		}
		stacks.list_a[i] = temp;
	}
	else
	{
		temp = stacks.list_b[i];
//		while (stacks.list_b[len - 1] > 0)
		while ((i - 1) >= 0)
		{
			stacks.list_b[i] = stacks.list_b[i - 1];
			i--;
		}
		stacks.list_b[i] = temp;
	}
}
