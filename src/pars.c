/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:50:23 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/11 16:06:07 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**pars_space(char *line)
{
	char	**tab;
	int		i;
	int		nb;
	int		i2;

	nb = 0;
	i = -1;
	while (line[++i])
	{
		line[i] == '"' ? ++nb : 0;
		nb % 2 == 1 && line[i] == ' ' ? line[i] = -1 : 0;
		nb % 2 == 1 && line[i] == '\t' ? line[i] = -2 : 0;
		line[i] == '"' ? line[i] = ' ' : 0;
	}
	tab = ft_split_space(line);
	i = -1;
	while (tab && tab[++i] && (i2 = -1))
		while (tab[i][++i2])
		{
			tab[i][i2] == -1 ? tab[i][i2] = ' ' : 0;
			tab[i][i2] == -2 ? tab[i][i2] = '\t' : 0;
		}
	return (tab);
}
