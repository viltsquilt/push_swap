/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command_call.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:57:44 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/06 10:31:21 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack stacks, char c)
{
	if (c == 'a')
	{
		push_operation(stacks, 1);
		ft_printf("%s", "pa");
	}
	else if (c == 'b')
	{
		push_operation(stacks, 2);
		ft_printf("%s", "pb");
	}
}

void	swap(t_stack stacks, char c)
{
	if (c == 'a')
	{
		swap_operation(stacks, 1);
		ft_printf("%s", "sa");
	}
	else if (c == 'b')
	{
		swap_operation(stacks, 2);
		ft_printf("%s", "sb");
	}
	else if (c == 'x')
	{
		swap_operation(stacks, 1);
		swap_operation(stacks, 2);
		ft_printf("%s", "ss");
	}
}

void	rotate(t_stack stacks, char c)
{
	if (c == 'a')
	{
		rotate_operation(stacks, 1);
		ft_printf("%s", "ra");
	}
	else if (c == 'b')
	{
		rotate_operation(stacks, 2);
		ft_printf("%s", "rb");
	}
	else if (c == 'x')
	{
		rotate_operation(stacks, 1);
		rotate_operation(stacks, 2);
		ft_printf("%s", "rr");
	}
}

void	reverse_rotate(t_stack stacks, char c)
{
	if (c == 'a')
	{
		reverse_rotate_operation(stacks, 1);
		ft_printf("%s", "rra");
	}
	else if (c == 'b')
	{
		reverse_rotate_operation(stacks, 2);
		ft_printf("%s", "rrb");
	}
	else if (c == 'x')
	{
		reverse_rotate_operation(stacks, 1);
		reverse_rotate_operation(stacks, 2);
		ft_printf("%s", "rrr");
	}
}
