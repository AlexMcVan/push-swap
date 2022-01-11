/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:55:49 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 16:09:28 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_bis(char **list)
{
	char	**list_bis;
	int		i;

	i = 0;
	list_bis = create_initiate_taba(1000 + 1);
	while (i < list_size(list))
	{
		ft_memcpy(list_bis[i], list[i]);
		i++;
	}
	free (list_bis[i]);
	list_bis[i] = NULL;
	return (list_bis);
}

void	push(char	**more, char	**less, int name)
{
	char	*buff;

	buff = (char *) ft_calloc(11 + 1, sizeof(char));
	ft_memcpy(buff, less[0]);
	if (list_size(more) == 0)
	{
		if (!(more[0]))
			more[0] = (char *) ft_calloc(11 + 1, sizeof(char));
		ft_memcpy(more[0], buff);
		if (more[1])
			free(more[1]);
		more[1] = NULL;
	}
	else
	{
		if (more[list_size(more) + 1])
			free (more[list_size(more) + 1]);
		more[list_size(more) + 1] = NULL;
		if (!(more[list_size(more)]))
			more[list_size(more)] = (char *) ft_calloc(11 + 1, sizeof(char));
		reverse_rotate(more, 0);
		ft_memcpy(more[0], buff);
	}
	rotate(less, 0);
	free(less[list_size(less) - 1]);
	less[list_size(less) - 1] = NULL;
	if (name == 1)
		write(1, &"pa\n", 3 * sizeof(char));
	if (name == 2)
		write(1, &"pb\n", 3 * sizeof(char));
	free(buff);
}
