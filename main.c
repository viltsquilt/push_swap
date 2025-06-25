/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/25 15:36:49 by vahdekiv         ###   ########.fr       */
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
	while(array[j])
	{
		free(array[j]);
		j++;
	}
	free(array);
}

int	check_isduplicate(int *array, int num)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack			stacks;

	stacks.i = 0;
	if (argc < 2)
		return (write(2, "Error\n", 6), 1);
	if (argc > 2)
		multi_input(argc, argv);
	else
	{
		stacks.split = ft_split(argv[1], ' ');
		if (!stacks.split)
			return (write(2, "Error\n", 6), 1);
		split_and_allocate(&stacks);
		while (stacks.split[stacks.i] != 0)
		{
			stacks.temp  = ps_atol(stacks, stacks.split[stacks.i]);
			if ((!stacks.list_a) || 
				(check_isduplicate(stacks.list_a, stacks.temp) == 1))
				return (error_handling(stacks, 2));
			stacks.list_a[stacks.i] = stacks.temp;
			stacks.i++;
		}
		ps_free(stacks.split);
		return (send_it(stacks));
	}
}
