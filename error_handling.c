/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 13:07:44 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/04 13:31:33 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char	*s)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while ((s[i] >= 9 && s[i] <= 13) || (s[i] == 32))
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (!(((ft_isdigit(s[i])) || (s[i] >= 9 && s[i] <= 13)
					|| (s[i] == 32)) || ((s[i] == '-' || s[i] == '+')
					&& ((ft_isdigit(s[i + 1])) && ((s[i - 1] == 32)
							|| (s[i - 1] >= 9 && s[i - 1] <= 13))))))
			return (1);
		i++;
	}
	return (0);
}

int	error_handling(t_stack stacks, int type)
{
	if (type == 1)
	{
		write(2, "Error\n", 6);
		ps_free(stacks.split);
		exit (1);
	}
	else if (type == 2)
	{
		write(2, "Error\n", 6);
		free(stacks.list_a);
		free(stacks.list_b);
		ps_free(stacks.split);
	}
	else
	{
		write(2, "Error\n", 6);
		free(stacks.list_a);
		free(stacks.list_b);
		exit (1);
	}
	return (1);
}

int	multi_input_isspace(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] >= 9 && s[i][j] <= 13) || (s[i][j] == 32)
				|| (!((ft_isdigit(s[i][j])) || (((s[i][j] == '-')
				|| (s[i][j] == '+')) && ((ft_isdigit(s[i][j + 1]))
				&& !ft_isdigit(s[i][j - 1]))))))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	sorted(t_stack stacks)
{
	free(stacks.list_a);
	free(stacks.list_b);
	exit(1);
}
