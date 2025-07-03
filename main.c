/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/03 16:41:29 by vahdekiv         ###   ########.fr       */
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
/*	if (multi_input_isspace(av) == 1)
		return (write(2, "Error\n", 6), 1);
	stacks.list_a = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_a)
		return (write(2, "Error\n", 6), 1);
	stacks.list_b = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_b)
		return (write(2, "Error\n", 6), 1);
	while (stacks.i < stacks.size_a)
	{
		stacks.temp = ps_atoi(stacks, av[stacks.i]);
		if (stacks.temp > INT_MAX || stacks.temp < INT_MIN)
			return (error_handling(stacks, 3));
		stacks.list_a[stacks.i] = (int)stacks.temp;
		stacks.i++;
	}
	if (check_isduplicate(stacks) == 1)
		return (error_handling(stacks, 3));
	return (send_it (stacks));
	return (0);*/
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
	{
		return (check_input(stacks, argv));
		/*if (argv[1][0] == '\0' || ft_isspace(argv[1]) == 1)
			return (write(2, "Error\n", 6), 1);
		stacks.split = ft_split(argv[1], ' ');
		if (!stacks.split)
			return (write(2, "Error\n", 6), 1);
		split_and_allocate(&stacks);
		while (stacks.split[stacks.i] != 0)
		{
			stacks.temp = ps_atoi(stacks, stacks.split[stacks.i]);
			if (stacks.temp > INT_MAX || stacks.temp < INT_MIN)
				return (error_handling(stacks, 2));
			stacks.list_a[stacks.i++] = (int)stacks.temp;
		}
		if (check_isduplicate(stacks) == 1)
			return (error_handling(stacks, 2));
		ps_free(stacks.split);
		return (send_it(stacks));*/
	}
	return (0);
}
