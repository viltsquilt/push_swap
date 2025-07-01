/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:07:00 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/01 13:02:10 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ps_atol(t_stack stacks, char *nptr)
{
	int	i;

	i = 0;
	stacks.minuscount = 0;
	stacks.pluscount = 0;
	stacks.minusflag = 1;
	stacks.nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			stacks.minuscount++;
		if (nptr[i] == '+')
			stacks.pluscount++;
		i++;
	}
	if ((stacks.minuscount % 2 != 0) && (stacks.minuscount > stacks.pluscount))
		stacks.minusflag = -1;
//	stacks.errorflag = i;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		stacks.nb = stacks.nb * 10 + (nptr[i++] - '0');
//	if ((i - stacks.errorflag) > 12)
//	{
//		error_handling(stacks, 1);
//		exit (1);
//	}
	stacks.nb *= stacks.minusflag;
//	if (stacks.nb > INT_MAX || stacks.nb < INT_MIN)
//		exit (1);
	if (nptr[i] == '\0')
		return (stacks.nb);
	return (stacks.nb);
}

int	error_handling(t_stack stacks, int type)
{
	if (type == 1)
	{
		write(2, "Error\n", 6);
		ps_free(stacks.split);
	}
	else if (type == 2)
	{
		write(2, "Error\n", 6);
		free(stacks.list_a);
		free(stacks.list_b);
		ps_free(stacks.split);
	}
	else if (type == 3)
	{
		write(2, "Error\n", 6);
		free(stacks.list_a);
		free(stacks.list_b);
	}
	else
	{
		free(stacks.list_a);
		free(stacks.list_b);
		exit (1);
	}
	return (1);
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
		return (error_handling(*stacks, 1));
	return (0);
}
