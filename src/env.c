/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:07:18 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 19:58:14 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		is_alpha(char *str)
{
	int i;

	i = -1;
	if ((str[0] >= 'a' && str[0] <= 'z')
			|| (str[0] >= 'A' && str[0] <= 'Z') || str[0] == '_')
	{
		while (str[++i])
			if (((str[i] < 'a' || str[i] > 'z')
			&& (str[i] < 'A' || str[i] > 'Z') && str[i] != '_'
			&& (str[i] < '0' || str[i] > '9')))
			{
				ft_putendl_fd("setenv: Variable name must \
contain alphanumeric characters.", 2);
				return (0);
			}
		return (1);
	}
	ft_putendl_fd("setenv: Variable name must begin with a letter.", 2);
	return (0);
}

char	*ft_getcontent(char *elem, char **g_env)
{
	int		ret;

	if ((ret = ft_getelem(elem, g_env)) == -1)
		return (NULL);
	return (ft_strcpyend(g_env[ret], '='));
}

int		ft_getelem(char *elem, char **g_env)
{
	int		i;
	char	*tmp;

	i = -1;
	while (g_env[++i])
	{
		tmp = ft_strccpy(g_env[i], '=');
		if (!ft_strcmp(tmp, elem))
		{
			ft_strdel(&tmp);
			return (i);
		}
		ft_strdel(&tmp);
	}
	return (-1);
}

void	cmd_unsetenv(char **tab, char ***g_env)
{
	int i;

	i = 0;
	while (tab[++i])
	{
		ft_getelem(tab[i], *g_env) != -1 ?
			*g_env = rem_str(*g_env, ft_getelem(tab[i], *g_env)) : 0;
	}
}
