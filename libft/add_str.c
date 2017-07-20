/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:28:19 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 16:09:25 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_ancien(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
	tab = NULL;
}

char		**add_str(char **tab, char *str)
{
	int		i;
	int		len;
	char	**n;

	len = 0;
	if (tab)
		while (tab[len])
			++len;
	!(n = (char**)malloc(sizeof(char*) * ++len + 1)) ? exit(EXIT_FAILURE) : 0;
	n[len] = NULL;
	i = 0;
	if (tab)
	{
		while (i < len - 1)
		{
			n[i] = ft_strdup(tab[i]);
			i++;
		}
	}
	n[i] = ft_strdup(str);
	free_ancien(tab);
	return (n);
}

char		**rem_str(char **tab, int r)
{
	int		i;
	int		len;
	char	**n;

	len = 0;
	if (tab)
		while (tab[len])
			++len;
	!(n = (char**)malloc(sizeof(char*) * len)) ? exit(EXIT_FAILURE) : 0;
	n[--len] = NULL;
	i = -1;
	if (tab)
		while (++i < len)
			*(n + i) = (i < r ? ft_strdup(*(tab + i))
					: ft_strdup(*(tab + i + 1)));
	free_ancien(tab);
	return (n);
}

char		**cpy_tab(char **tab)
{
	int		i;
	int		len;
	char	**n;

	len = 0;
	if (tab)
		while (tab[len])
			++len;
	!(n = (char**)malloc(sizeof(char*) * len + 1)) ? exit(EXIT_FAILURE) : 0;
	n[len] = NULL;
	i = 0;
	if (tab)
		while (i < len)
		{
			n[i] = ft_strdup(tab[i]);
			i++;
		}
	return (n);
}
