/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:57:44 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/16 15:06:17 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack stacks, char c, int len_a, int len_b)
{
	if (c == 'a')
	{
		push_operation(stacks, 1, len_a, len_b);
		ft_printf("%s\n", "pa");
	}
	else if (c == 'b')
	{
		push_operation(stacks, 2, len_a, len_b);
		ft_printf("%s\n", "pb");
	}
}

void	swap(t_stack stacks, char c)
{
	if (c == 'a')
	{
		swap_operation(stacks, 1);
		ft_printf("%s\n", "sa");
	}
	else if (c == 'b')
	{
		swap_operation(stacks, 2);
		ft_printf("%s\n", "sb");
	}
	else if (c == 'x')
	{
		swap_operation(stacks, 1);
		swap_operation(stacks, 2);
		ft_printf("%s\n", "ss");
	}
}

void	rotate(t_stack stacks, char c, int len_a, int len_b)
{
	if (c == 'a' && len_b == 0)
	{
		rotate_operation(stacks, 1, len_a);
		ft_printf("%s\n", "ra");
	}
	else if (c == 'b' && len_a == 0)
	{
		rotate_operation(stacks, 2, len_b);
		ft_printf("%s\n", "rb");
	}
	else if (c == 'x')
	{
		rotate_operation(stacks, 1, len_a);
		rotate_operation(stacks, 2, len_b);
		ft_printf("%s\n", "rr");
	}
}

void	reverse_rotate(t_stack stacks, char c, int len_a, int len_b)
{
	if (c == 'a' && len_b == 0)
	{
		reverse_rotate_operation(stacks, 1, len_a);
		ft_printf("%s\n", "rra");
	}
	else if (c == 'b' && len_a == 0)
	{
		reverse_rotate_operation(stacks, 2, len_b);
		ft_printf("%s\n", "rrb");
	}
	else if (c == 'x')
	{
		reverse_rotate_operation(stacks, 1, len_a);
		reverse_rotate_operation(stacks, 2, len_b);
		ft_printf("%s\n", "rrr");
	}
}
