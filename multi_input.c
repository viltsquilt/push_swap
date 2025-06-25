/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:19:48 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/25 19:42:20 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multi_input(int ac, char **av)
{
	t_stack	stacks;

	stacks.i = 1;
	stacks.size_a = ac - 1;
	stacks.list_a = malloc((stacks.size_a) * (sizeof(int)));
	stacks.list_a[0] = 0;
	if (!stacks.list_a)
		return (write(2, "Error\n", 6), 1);
	stacks.list_b = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_b)
		return (write(2, "Error\n", 6), 1);
	while (av[stacks.i])
	{
		stacks.temp = ps_atol(stacks, av[stacks.i]);
		if ((!stacks.list_a)
			|| (check_isduplicate(stacks.list_a, stacks.temp) == 1))
			return (error_handling(stacks, 3));
		stacks.list_a[stacks.i - 1] = stacks.temp;
		stacks.i++;
	}
	return (send_it (stacks));
}
