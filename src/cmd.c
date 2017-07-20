/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:15:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/16 18:12:10 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		taille_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

void	cmd_env(char **tab)
{
	int i;

	i = -1;
	while (*(tab + ++i))
		ft_putendl(*(tab + i));
}
