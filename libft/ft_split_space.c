/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 13:54:06 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/23 17:43:50 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbmot(char const *s)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	while (s[i])
	{
		if (((s[i] == ' ' || s[i] == '\t') &&
			(s[i + 1] != ' ' && s[i + 1] != '\t')
			&& s[i + 1]) || (i == 0 && (s[i] != ' ' && s[i] != '\t')))
			nb++;
		i++;
	}
	return (nb);
}

static char	*ft_remplir(char const *s, int i)
{
	char	*str;
	int		i2;
	int		i3;
	int		i4;

	i2 = 0;
	if (s[i] == ' ' || s[i] == '\t')
		i++;
	i3 = i;
	while ((s[i] != ' ' && s[i] != '\t') && s[i])
	{
		i2++;
		i++;
	}
	!(str = (char*)malloc(sizeof(*str) * i2 + 1)) ? exit(EXIT_FAILURE) : 0;
	if (!str)
		return (0);
	i4 = 0;
	while (s[i3] && (s[i3] != ' ' && s[i3] != '\t'))
		str[i4++] = s[i3++];
	str[i4] = '\0';
	return (str);
}

char		**ft_split_space(char const *s)
{
	int		i;
	int		i2;
	char	**tab;

	if ((i2 = 0) || !s || ft_nbmot(s) == 0)
		return (NULL);
	!(tab = (char**)malloc(sizeof(*tab) * ft_nbmot(s) + 1))
		? exit(EXIT_FAILURE) : 0;
	if (!(i = 0) && !tab)
		return (NULL);
	while (s[i])
	{
		if (i == 0 && (s[i] != ' ' && s[i] != '\t'))
			i2 = 1;
		else if (((s[i] == ' ' || s[i] == '\t') &&
					(s[i + 1] != ' ' && s[i + 1] != '\t')) && (s[i + 1]))
			tab[i2++] = ft_remplir(s, i);
		i++;
	}
	if (s[0] != ' ' && s[0] != '\t' && s[0])
		tab[0] = ft_remplir(s, 0);
	tab[i2] = 0;
	if (!tab)
		return (NULL);
	return (tab);
}
