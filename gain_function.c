/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gain_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 16:43:46 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 17:16:53 by amarie-c         ###   ########.fr       */
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

char	**create_initiate_taba( int size)
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

char	**create_initiate_tabb( int size)
{
	char	**tab;
	int		i;

	i = 1;
	tab = (char **) ft_calloc(size, sizeof(char *));
	while (i < size)
	{
		tab[i] = (char *) ft_calloc(11 + 1, sizeof(char));
		i++;
	}
	return (tab);
}

int	search_min(char **tab)
{
	int	indice;
	int	i;

	i = 0;
	indice = 0;
	while (i < list_size(tab))
	{
		if (fap(tab[i]) < fap(tab[indice]))
			indice = i;
		i++;
	}
	return (indice);
}

void	sort_five(char **a, char **b)
{
	int	min;

	min = search_min(a);
	if (min == 1 || min == 2)
	{
		rotate(a, 1);
		if (min == 2)
			rotate(a, 1);
	}
	if (min == 3 || min == 4)
	{
		reverse_rotate(a, 1);
		if (min == 3)
			reverse_rotate(a, 1);
	}
	push(b, a, 2);
}
