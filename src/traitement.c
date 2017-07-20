/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traitement.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:32:04 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/17 16:41:34 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	instruction(char *line, char ***g_env)
{
	char	**tab;
	int		i;

	tab = pars_space(line);
	tab && tab[0] ? lunch_builtins(tab, g_env) : 0;
	i = -1;
	while (tab && tab[++i])
		ft_strdel(&tab[i]);
	tab ? free(tab) : 0;
}

void	pre_instruction(char *line, char ***g_env)
{
	int		i;
	char	**instr;
	int		nb;
	int		i2;

	nb = 0;
	i = -1;
	while (line && line[++i])
	{
		line[i] == '"' ? ++nb : 0;
		line[i] == ';' && (nb % 2) ? line[i] = -3 : 0;
	}
	instr = ft_strsplit(line, ';');
	i = -1;
	while (instr && instr[++i] && (i2 = -1))
		while (instr[i][++i2])
			instr[i][i2] == -3 ? instr[i][i2] = ';' : 0;
	i = -1;
	while (instr && instr[++i])
		instruction(instr[i], g_env);
	instr ? free_ancien(instr) : 0;
}
