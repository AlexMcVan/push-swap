/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:04:34 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/10 16:19:04 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_ranked(char **list)
{
	int		i;
	int		j;
	int		rank;
	char	*buff;
	char	**list_bis;

	list_bis = create_bis(list);
	j = 0;
	while (list[j] != NULL)
	{
		rank = 0;
		i = 0;
		while (list[i] != NULL)
		{
			if (fap(list[i]) < fap(list[j]))
				rank++;
			i++;
		}
		buff = ft_itoa(rank);
		ft_memcpy(list_bis[j], buff);
		j++;
		free(buff);
	}
	return (list_bis);
}

void	ft_sort_big(char **a, char **b)
{
	int	j;
	int	buff;

	j = 0;
	while (j <= 31)
	{
		buff = fap(a[list_size(a) - 1]);
		while (list_size(a) > 0 && fap(a[0]) != buff)
		{
			if (!((fap(a[0]) >> j) & 1))
				push(&b, &a, 2);
			else
				rotate(a, 1);
		}
		if (!((fap(a[0]) >> j) & 1))
			push(&b, &a, 2);
		else
			rotate(a, 1);
		while (list_size(b) > 0)
			push(&a, &b, 1);
		if (is_sorted(a) == SUCCESS)
			return ;
		j++;
	}
}

void	ft_sort_small(char **a, char **b)
{
	if (list_size(a) == 2)
		swap(a, 1);
	else if (list_size(a) == 3)
		ft_sort_three(a);
	else if (list_size(a) == 4)
	{
		push(&b, &a, 2);
		ft_sort_three(a);
		ft_add_element(a, b, 1);
	}
	else if (list_size(a) == 5)
	{
		push(&b, &a, 2);
		push(&b, &a, 2);
		ft_sort_three(a);
		ft_add_element(a, b, 2);
	}	
}

void	ft_add_element(char	**a, char	**b, int nb)
{
	int	top_b;
	int	boucle;

	boucle = 0;
	while (boucle < nb)
	{
		top_b = fap(b[0]);
		if (is_min(top_b, a) == 1)
			push(&a, &b, 1);
		else if (is_max(top_b, a) == 1)
		{
			push(&a, &b, 1);
			rotate(a, 1);
		}
		else
		{
			while (top_b > fap(a[0]) || top_b < fap(a[list_size(a) - 1]))
				rotate(a, 1);
			push(&a, &b, 1);
		}
		while (is_sorted(a) != SUCCESS)
			rotate(a, 1);
		boucle++;
	}
}

void	ft_sort_three(char **a)
{
	if (is_sorted(a) == SUCCESS)
		return ;
	if (fap(a[1]) < fap(a[0]) && fap(a[1]) < fap(a[2])
		&& fap(a[0]) < fap(a[2]))
		swap(a, 1);
	else if (fap(a[1]) < fap(a[0]) && fap(a[1]) < fap(a[2])
		&& fap(a[0]) > fap(a[2]))
		rotate(a, 1);
	else if (fap(a[1]) > fap(a[0]) && fap(a[1]) > fap(a[2])
		&& fap(a[0]) > fap(a[2]))
		reverse_rotate(a, 1);
	else if (fap(a[1]) < fap(a[0]) && fap(a[1]) > fap(a[2])
		&& fap(a[0]) > fap(a[2]))
	{
		swap(a, 1);
		reverse_rotate(a, 1);
	}
	else if (fap(a[1]) > fap(a[0])
		&& fap(a[1]) > fap(a[2]) && fap(a[0]) < fap(a[2]))
	{
		swap(a, 1);
		rotate(a, 1);
	}
}
