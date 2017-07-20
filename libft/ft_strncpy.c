/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:37:40 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/07 11:28:39 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	int i;
	int i2;

	i2 = 0;
	i = 0;
	while (len)
	{
		dest[i] = src[i];
		if (src[i])
			i++;
		else
			dest[i2] = 0;
		i2++;
		len--;
	}
	return (dest);
}
