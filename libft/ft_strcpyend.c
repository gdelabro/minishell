/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 13:29:00 by gdelabro          #+#    #+#             */
/*   Updated: 2017/03/21 19:22:28 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyend(char *str, char c)
{
	int		i;
	int		i2;
	char	*new;

	i = ft_strlen(str);
	i2 = -1;
	while (--i >= 0 && str[i] != c)
		;
	new = ft_strnew(ft_strlen(str) - i + 1);
	while (str[++i])
		new[++i2] = str[i];
	new[++i2] = 0;
	return (new);
}
