/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:23:03 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 17:56:31 by amarie-c         ###   ########.fr       */
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
	while (i < n)
	{
		if (list[i] || list[i] != NULL)
		{
			free(list[i]);
		}
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
		if (argc > 1001)
		{
			write(2, "too many arguments (1000 max)\n", 30 * sizeof(char));
			return (ERROR);
		}
		a = create_initiate_taba(1000 + 1);
		if (parsing(argc, argv, a) == ERROR)
		{
			ft_free(a, 1000 + 1);
			return (ERROR);
		}
		if (is_sorted(a) == ERROR)
		{
			a = ft_ranked(a);
			b = create_initiate_tabb(1000 + 1);
			ft_sort(a, b);
			ft_free(b, 1000 + 1);
		}
		ft_free(a, 1000 + 1);
	}
	return (SUCCESS);
}
