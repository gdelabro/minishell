/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:19:45 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/14 15:02:44 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *litl, size_t len)
{
	int i;
	int i2;
	int i3;
	int i4;

	i2 = 0;
	i = 0;
	if (!big && !litl)
		return ((char *)&big[i]);
	while (big[i] && len && i > -1)
	{
		i4 = len;
		i3 = i;
		i2 = 0;
		while (big[i3] == litl[i2] && big[i3] && litl[i2] && i4--)
		{
			i2++;
			i3++;
		}
		if (!litl[i2])
			return ((char *)&big[i]);
		i++;
		len--;
	}
	return (0);
}
