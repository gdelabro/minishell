/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:20:40 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 16:20:54 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		i2;
	int		n;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	i2 = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (s[i2] == ' ' || s[i2] == '\t' || s[i2] == '\n')
		i2--;
	if (i2 < 0)
	{
		!(str = (char*)malloc(sizeof(*str) * 1)) ? exit(EXIT_FAILURE) : 0;
		*str = 0;
		return (str);
	}
	n = i2 - i + 1;
	str = ft_strsub(s, i, n);
	if (!str)
		return (NULL);
	return (str);
}
