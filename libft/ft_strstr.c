/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:06:26 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/07 16:02:28 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int i2;
	int i3;

	i2 = 0;
	i = 0;
	if (big[0] == '\0' && little[0] == '\0')
		return ((char *)&big[i]);
	while (big[i])
	{
		i3 = i;
		i2 = 0;
		while (big[i3] == little[i2] && big[i3] && little[i2])
		{
			i2++;
			i3++;
		}
		if (!little[i2])
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
