/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:09:48 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/09 15:36:36 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_echo(char **tab)
{
	int		i;

	i = 1;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		tab[++i] ? ft_putstr(" ") : 0;
	}
	ft_putendl("");
}
