/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gain_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:43:46 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 05:09:58 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(char **a, char **b)
{
	if (list_size(a) <= 5)
		ft_sort_small(a, b);
	else
		ft_sort_big(a, b);
}

void	initial_tab(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = (char *) ft_calloc(11 + 1, sizeof(char));
		tab[i] = NULL;
		i++;
	}
}

char	**create_initiate_tab( int size)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **) ft_calloc(size, sizeof(char *));
	while (i < size)
	{
		tab[i] = (char *) ft_calloc(11 + 1, sizeof(char));
		i++;
	}
	return (tab);
}
