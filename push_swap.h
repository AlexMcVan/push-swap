/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:22:40 by amarie-c          #+#    #+#             */
/*   Updated: 2022/01/11 04:22:41 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SUCCESS 0
# define ERROR 1

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int		fap(const char *str);
int		ft_no_double(char **list);
int		parsing(int argc, char **argv, char **dest);
int		is_sorted(char	**list);
void	reverse_rotate(char	**list, int name);
void	rotate(char	**list, int name);
void	swap(char	**list, int name);
void	push(char	**more, char **less, int name);
char	**create_bis(char **list);
void	*ft_calloc(size_t nbofelements, size_t sizeofelement);
int		ft_strncmp(char *s1, char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
char	**ft_ranked(char **list);
int		ft_strlen(const char *s);
void	*ft_memcpy(char *dest, char *src);
void	ft_free(char **list, int n);
void	ft_free_ad(char ***list, int n);
int		list_size(char **list);
char	*ft_itoa(int n);
void	fill_bis(char	**m, char	**m_bis, char	**l, char	**l_bis);
void	ft_sort_big(char **a, char **b);
void	ft_sort_small(char **a, char **b);
void	ft_sort_three(char **a);
void	ft_add_element(char	**a, char	**b, int nb);
int		is_min(int nb, char **list);
int		is_max(int nb, char **list);
void	free_all(char ***a, char ***b);
void	ft_sort(char **a, char **b);
void	error_parsing(char	**list, int nb);
void	initial_tab(char **tab, int size);
char	**create_tab(int size);
char	**create_initiate_tab( int size);
#endif