/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/26 14:02:48 by vahdekiv         ###   ########.fr       */
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

	i = 0;
	while (i < stacks.size_a - 1)
	{
		if (stacks.list_a[i] == stacks.list_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

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

int	main(int argc, char **argv)
{
	t_stack			stacks;

	stacks.i = 0;
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	if (argc > 2)
		multi_input(argc, &argv[1]);
	else
	{
		stacks.split = ft_split(argv[1], ' ');
		if (!stacks.split)
			return (write(2, "Error\n", 6), 1);
		split_and_allocate(&stacks);
		while (stacks.split[stacks.i] != 0)
		{
			stacks.temp = ps_atol(stacks, stacks.split[stacks.i]);
			stacks.list_a[stacks.i++] = stacks.temp;
		}
		if (check_isduplicate(stacks) == 1)
			return (error_handling(stacks, 2));
		ps_free(stacks.split);
		return (send_it(stacks));
	}
}
