/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:23:03 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 05:29:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min(int nb, char **list)
{
	int	i;
	int	min;

	i = 0;
	min = 1;
	while (i < list_size(list))
	{
		if (fap(list[i]) < nb)
			min = 0;
		i++;
	}
	return (min);
}

int	is_max(int nb, char **list)
{
	int	i;
	int	max;

	i = 0;
	max = 1;
	while (i < list_size(list))
	{
		if (fap(list[i]) > nb)
			max = 0;
		i++;
	}
	return (max);
}

int	list_size(char **list)
{
	int	i;

	i = 0;
	while (list[i] != NULL)
		i++;
	return (i);
}

void	ft_free(char **list, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		//printf("free list[%d]\n", i);
		if (list[i] != NULL)
			free(list[i]);
		i++;
	}
	free(list);
}

int	main(int argc, char **argv)
{
	char	**a;
	char	**b;

	if (argc > 1)
	{	
		if (argc > 1000)
		{
			write(2, "too many arguments (1000 max)\n", 30 * sizeof(char));
			return (ERROR);
		}
		a = create_initiate_tab(1000 + 1);
		b = create_initiate_tab(1000 + 1);
		/*		int i = 0;
		while ( i < 10)
		{
			printf("a[%d] = %s\n", i , a[i]);
			i++;
		}*/
		if (parsing(argc, argv, a) == ERROR)
		{
			ft_free(a, 1000);
			ft_free(b, 1000);
			return (ERROR);
		}

		if (is_sorted(a) == ERROR)
		{
			a = ft_ranked(a);
			ft_sort(a, b);
		}
		int i = 0;
		while ( i < 10)
		{
			printf("a[%d] = %s\n", i , a[i]);
			i++;
		}
		ft_free(a, 1000);
		ft_free(b, 1000);
	}
	return (SUCCESS);
}
