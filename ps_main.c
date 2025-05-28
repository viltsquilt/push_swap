/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 10:58:35 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/05/28 16:20:59 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arraylen(char **split)
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

int	ps_isduplicate(int *array, int num)
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
	int			*list;
	int				i;
	int			temp;
	char	**split;
	int		arraylen;

	i = 0;
	if (argc < 2 || argc > 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	split = ft_split(&argv[1], " ");
	arraylen = ps_arraylen(split);
	list = malloc(arraylen + 1) * (sizeof(int));
	if (!list)
		return (ps_free(split), NULL);
	while (split++)
	{
		temp = ps_atol(*split);
		if ((!temp) || (ps_isduplicate(list, temp) == 1))
			{
				write(1, "Error\n", 6);
				free(list);
				free(split);
				return (1);
			}
		else
			list[i] = temp;
		free(*split);
		i++;
	}
	push_swap(list);
	free(list);
	return (0);
}
