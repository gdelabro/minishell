/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:35:11 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 17:58:42 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**modif_tab(char **env, int ret, char *str)
{
	int		i;
	int		taille;
	char	**tab;

	taille = taille_tab(env);
	!(tab = (char**)malloc(sizeof(char*) * taille + 1))
		? exit(EXIT_FAILURE) : 0;
	tab[taille] = 0;
	i = -1;
	while (env[++i])
	{
		i != ret ? tab[i] = ft_strdup(env[i])
			: (tab[i] = ft_strdup(str));
	}
	return (tab);
}

void	replace(char ***g_env, int ret, char *str)
{
	char	**tmp;
	char	**tmp2;

	tmp2 = *g_env;
	tmp = modif_tab(*g_env, ret, str);
	free_ancien(tmp2);
	*g_env = tmp;
}

void	cmd_setenv(char **tab, char ***g_env)
{
	int		taille;
	char	*tmp;
	int		ret;
	char	*tmp2;

	taille = taille_tab(tab);
	if (taille > 3 || taille == 1)
	{
		taille != 1 ? ft_putendl_fd("setenv: too many argument.", 2) :
			cmd_env(*g_env);
		return ;
	}
	ret = ft_getelem(tab[1], *g_env);
	tmp = ft_strjoin(tab[1], "=");
	tmp2 = ft_strjoin(tmp, tab[2]);
	if (ret == -1)
		is_alpha(tab[1]) ? *g_env = add_str(*g_env, tmp2) : 0;
	else
		replace(g_env, ret, tmp2);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
}
