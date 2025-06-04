/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:56:13 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/06/04 15:42:43 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_stack
{
	int		*list_a;
	int		*list_b;
	size_t	size_a;
	size_t	size_b;
}	t_stack;

#endif
