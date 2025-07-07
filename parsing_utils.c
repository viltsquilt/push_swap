/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:07:00 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/07 17:41:46 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ps_atoi(t_stack stacks, char *nptr)
{
	size_t	i;
	int		sign;

	i = 0;
	sign = 1;
	stacks.n = 0;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (nptr[i])
	{
		stacks.n = stacks.n * 10 + (nptr[i] - '0');
		i++;
	}
	stacks.n = stacks.n * sign;
	return (stacks.n);
}

int	check_input(t_stack stacks, char **av)
{
	if (av[1][0] == '\0' || ft_isspace(av[1]) == 1)
		return (write(2, "Error\n", 6), 1);
	stacks.split = ft_split(av[1], ' ');
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
	return (send_it(stacks));
}

int	check_multi_input(t_stack stacks, char **av)
{
	if (multi_input_isspace(av) == 1)
		return (write(2, "Error\n", 6), 1);
	stacks.list_a = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_a)
		return (write(2, "Error\n", 6), 1);
	stacks.list_b = malloc((stacks.size_a) * (sizeof(int)));
	if (!stacks.list_b)
	{
		free(stacks.list_a);
		return (write(2, "Error\n", 6), 1);
	}
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
}

int	send_it(t_stack stacks)
{
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

int	split_and_allocate(t_stack *stacks)
{
	stacks->size_a = ps_arraylen(stacks->split);
	stacks->list_a = malloc((stacks->size_a) * (sizeof(int)));
	if (!stacks->list_a)
		return (error_handling(*stacks, 1));
	stacks->list_b = malloc((stacks->size_a) * (sizeof(int)));
	if (!stacks->list_b)
	{
		free(stacks->list_a);
		return (error_handling(*stacks, 1));
	}
	return (0);
}
