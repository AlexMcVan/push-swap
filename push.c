/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:55:49 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 04:13:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_bis(char **list)
{
	char	**list_bis;
	int		i;

	i = 0;
	list_bis = (char **) ft_calloc(1000 + 1, sizeof(char));
	initial_tab(list_bis, 1001);
	while (i < list_size(list))
	{
		ft_memcpy(list_bis[i], list[i]);
		i++;
	}
	list_bis[i] = NULL;
	return (list_bis);
}

void	push(char	**more, char	**less, int name)
{
	char	*buff;

	buff = (char *) ft_calloc(11 + 1, sizeof(char));
	buff = NULL;
	ft_memcpy(buff, less[0]);
	rotate(less, 0);
	less[list_size(less) - 1] = NULL;
	ft_memcpy(more[list_size(more)], buff);
	reverse_rotate(more, 0);
	if (name == 1)
		write(1, &"pa\n", 3 * sizeof(char));
	if (name == 2)
		write(1, &"pb\n", 3 * sizeof(char));
	free(buff);
}
