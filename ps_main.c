/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/29 17:03:33 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arraylen(char **split)
{
	int	i;

	i = 0;
	while (split++)
		i++;
	return (i);
}

void	ps_free(char **array)
{
	int	i;

	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	array[i] = NULL;
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
	t_stack			a;
	t_stack			b;
	int				i;
	int			*temp;
	char	**split;

	i = 0;
	if (argc < 2 || argc > 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	split = ft_split(&argv[1], " ");
	temp = malloc(ps_arraylen(split) + 1) * (sizeof(int));
	if (!temp)
	{
		write(1, "Error\n", 6);
		ps_free(split);
		return (1);
	}
	while (split++)
	{
		temp[i] = ps_atol(*split);
		free(*split);
		if ((!temp) || (ps_isduplicate(temp, temp[i]) == 1))
			{
				write(1, "Error\n", 6);
				free(temp);
				free(split);
				return (1);
			}
		i++;
	}
	a->size = ps_listlen(list);
	a->list = malloc(size) * (sizeof(int));
	if (!list)
	{
		write(1, "Error\n", 6);
		free(temp);
		return (1);
	}
	i = 0;
	while (temp[i])
		a->list[i] = temp[i];
	free(temp)
	array_type(&a);
	free(list);
	return (0);
}
