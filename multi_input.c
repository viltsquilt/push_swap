/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:19:48 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/23 13:12:44 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multi_input(int ac, char **av)
{
	t_stack	stacks;
	int		i;
	int		temp;

	i = 1;
	stacks.size_a = ac - 1;
	stacks.list_a = malloc((stacks.size_a) * (sizeof(int)));
	stacks.list_a[0] = 0;
	if (!stacks.list_a)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stacks.list_b = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_b)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	while (av[i])
	{
		temp = ps_atol(av[i]);
		if ((!stacks.list_a) || (check_isduplicate(stacks.list_a, temp) == 1))
		{
			write(2, "Error\n", 6);
			free(stacks.list_a);
			free(stacks.list_b);
			return (1);
		}
		stacks.list_a[i - 1] = temp;
		i++;
	}
	stacks.len_a = stacks.size_a;
	stacks.len_b = 0;
	if (stacks.len_a == 3)
		small_sort(stacks, stacks.len_a);
	else
		push_swap(stacks, stacks.len_a, stacks.len_b);
	free(stacks.list_a);
	free(stacks.list_b);
	return (0);
}
