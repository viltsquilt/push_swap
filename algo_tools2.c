/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:53:37 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/18 14:28:37 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_cheapest(t_stack stacks, int len_b)
{
	int	j;
	int	i;
	int	temp;

	j = 0;
	i = 0;
	temp = 0;
	while (i < len_b)
	{
		j = 0;
		while (j < (len_b - i))
		{
			if (stacks.top_cost[j] < stacks.top_cost[j + 1])
			{
				temp = stacks.top_cost[j];
				stacks.top_cost[j] = stacks.top_cost[j + 1];
				stacks.top_cost[j + 1] = temp;
			}
			j++;
		}
		stacks.cheapest[i] = stacks.top_cost[j];
		i++;
	}
	return (stacks.cheapest);
}
