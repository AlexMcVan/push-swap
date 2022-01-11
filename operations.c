/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarie-c <amarie-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:48:45 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 12:15:10 by amarie-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char	**list, int name)
{
	char	*buff;

	buff = (char *) ft_calloc(11 + 1, sizeof(char));
	if (list[0] && *list[1])
	{
		ft_memcpy(buff, list[0]);
		ft_memcpy(list[0], list[1]);
		ft_memcpy(list[1], buff);
		if (name == 1)
			write(1, &"sa\n", 3 * sizeof(char));
		if (name == 2)
			write(1, &"sb\n", 3 * sizeof(char));
		if (name == 3)
			write(1, &"ss\n", 3 * sizeof(char));
	}
	free(buff);
}

void	rotate(char	**list, int name)
{
	char	*buff;
	int		i;
	int		nb;

	i = 0;
	buff = (char *) ft_calloc(11 + 1, sizeof(char));
	nb = list_size(list);
	ft_memcpy(buff, list[0]);
	while (i < nb - 1)
	{
		ft_memcpy(list[i], list[i + 1]);
		i++;
	}
	ft_memcpy(list[nb - 1], buff);
	if (name == 1)
		write(1, &"ra\n", 3 * sizeof(char));
	if (name == 2)
		write(1, &"rb\n", 3 * sizeof(char));
	if (name == 3)
		write(1, &"rr\n", 3 * sizeof(char));
	free(buff);
}

void	reverse_rotate(char	**list, int name)
{
	char	*buff;
	int		i;
	int		nb;

	nb = list_size(list);
	if (nb < 2)
		return ;
	buff = (char *) ft_calloc(11 + 1, sizeof(char));
	i = nb - 1;
	ft_memcpy(buff, list[nb - 1]);
	while (i > 0)
	{
		ft_memcpy(list[i], list[i - 1]);
		i--;
	}
	ft_memcpy(list[0], buff);
	if (name == 1)
		write(1, &"rra\n", 4 * sizeof(char));
	if (name == 2)
		write(1, &"rrb\n", 4 * sizeof(char));
	if (name == 3)
		write(1, &"rrs\n", 4 * sizeof(char));
	free(buff);
}

int	is_sorted(char	**list)
{
	int	i;
	int	nb;

	i = 0;
	nb = list_size (list);
	while (i < nb - 1)
	{
		if (fap(list[i]) > fap(list[i + 1]))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
