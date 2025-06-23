/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:53:37 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/23 13:21:32 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_cheapest(t_stack stacks, int len)
{
	int	cheapest;
	int	i;

	i = 0;
	cheapest = stacks.top_cost[i];
	while (i < (len - 1))
	{
		i++;
		if (cheapest > stacks.top_cost[i])
			cheapest = stacks.top_cost[i];
	}
	return (cheapest);
}

int	*move_to_top_costs(t_stack stacks, int len_a, int len_b)
{
	int	i;

	i = 0;
	while (i < len_b)
	{
		stacks.target = find_target(stacks, stacks.list_b[i], len_a, len_b);
		stacks.index_a = find_index(stacks, stacks.target, 1, len_a);
		stacks.index_b = find_index(stacks, stacks.list_b[i], 2, len_b);
		stacks.cost_a = calculate_cost(stacks, 1, len_a);
		stacks.cost_b = calculate_cost(stacks, 2, len_b);
		stacks.top_cost[i] = (stacks.cost_a + stacks.cost_b);
		i++;
	}
	return (stacks.top_cost);
}
