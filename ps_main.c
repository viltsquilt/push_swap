/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/04 16:58:27 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_arraylen(char **split)
{
	int	i;

	i = 0;
	while (split++)
		i++;
	return (i);
}

static void	ps_free(char **array)
{
	int	i;

	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static int	ps_isduplicate(int *array, int num)
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
	int				i;
	char	**split;

	i = 0;
	if (argc < 2 || argc > 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	split = ft_split(&argv[1], " ");
	if (!split)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stacks->size_a = ps_arraylen(split);
	stacks->list_a = malloc((stacks->size_a) * (sizeof(int)));
	if (!stacks->list_a)
	{
		write(1, "Error\n", 6);
		ps_free(split);
		return (1);
	}
	stacks->list_b = malloc((stacks->size_a) * (sizeof(int)));
	if (!stacks->list_b)
	{
		write(1, "Error\n", 6);
		ps_free(split);
		return (1);
	}
	while (split++)
	{
		stacks->list_a[i] = ps_atol(split);
		if ((!stacks->list_a) || 
			(ps_isduplicate(stacks->list_a, stacks->list_a[i]) == 1))
			{
				write(1, "Error\n", 6);
				ps_free(stacks->list_a);
				ps_free(split);
				return (1);
			}
		i++;
	}
	ps_free(split)
	if (stacks->size_a == 3)
		small_sort(stacks);
	else
		push_swap(stacks);
	free(stacks->list_a);
	free(stacks->list_b);
	return (0);
}
