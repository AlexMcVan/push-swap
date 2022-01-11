/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:00:47 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/10 15:10:29 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i++] = 0;
	}
}

void	*ft_calloc(size_t nbofelements, size_t sizeofelement)
{
	void	*space;
	size_t	size;

	size = nbofelements * sizeofelement;
	space = (void *)malloc((nbofelements) * sizeofelement);
	if (space == NULL)
		return (NULL);
	ft_bzero(space, size);
	return (space);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*uc_s1;
	unsigned char	*uc_s2;

	uc_s1 = (unsigned char *)s1;
	uc_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((uc_s1[i] != '\0') && (i < n - 1) && (uc_s2[i] != '\0')
		&& (uc_s1[i] == uc_s2[i]))
	{
		i++;
	}
	return (uc_s1[i] - uc_s2[i]);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[i])
	{
		(dest)[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
