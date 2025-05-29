/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:07:00 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/29 15:57:49 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	ps_atol(char *nptr)
{
	int	i;
	int	minusflag;
	int	nb;

	i = 0;
	minusflag = 1;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minusflag = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
	}
	nb *= minusflag;
	if (nptr[i] < '0' || nptr[i] > '9' || nb > INT_MAX || nb <= INT_MIN)
		return (0);
	return (nb);
}

int listlen(int *list)
{
    int i;

    i = 0;
    while (list[i])
        i++;
    return (i);
}

int	get_index(t_stack a)
{
	
}
