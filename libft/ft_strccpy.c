/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:35:56 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 19:22:03 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	if (!s)
		return (NULL);
	while (s[++i] && s[i] != c)
		;
	!(str = (char*)malloc(sizeof(char) * i + 1)) ? exit(EXIT_FAILURE) : 0;
	str[i] = 0;
	while (i--)
		str[i] = s[i];
	return (str);
}
