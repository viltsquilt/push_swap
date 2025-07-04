/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/04 10:57:26 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_arraylen(char **split)
{
	int	i;

	i = 0;
	while (*split++)
		i++;
	return (i);
}

void	ps_free(char **array)
{
	int	j;

	j = 0;
	while (array[j])
	{
		free(array[j]);
		j++;
	}
	free(array);
}

int	check_isduplicate(t_stack stacks)
{
	size_t	i;
	size_t	j;
	int		temp;

	i = 0;
	j = 1;
	while (i < stacks.size_a - 1)
	{
		temp = stacks.list_a[i];
		while (j < stacks.size_a)
		{
			if (j == i)
				j++;
			if (stacks.list_a[j] == temp)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	multi_input(int ac, char **av)
{
	t_stack	stacks;

	stacks.i = 0;
	stacks.size_a = ac - 1;
	return (check_multi_input(stacks, av));
}

int	main(int argc, char **argv)
{
	t_stack			stacks;

	stacks.i = 0;
	if (argc < 2)
		return (0);
	if (argc > 2)
		multi_input(argc, &argv[1]);
	else
		return (check_input(stacks, argv));
	return (0);
}
