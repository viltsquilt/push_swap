/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:19:48 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/26 13:05:09 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multi_input(int ac, char **av)
{
	t_stack	stacks;

	stacks.i = 0;
	stacks.size_a = ac - 1;
	stacks.list_a = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_a)
		return (write(2, "Error\n", 6), 1);
	stacks.list_b = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_b)
		return (write(2, "Error\n", 6), 1);
	while (stacks.i < stacks.size_a)
	{
		stacks.temp = ps_atol(stacks, av[stacks.i]);
		stacks.list_a[stacks.i] = stacks.temp;
		stacks.i++;
	}
	if (check_isduplicate(stacks) == 1)
		return (error_handling(stacks, 3));
	return (send_it (stacks));
}
