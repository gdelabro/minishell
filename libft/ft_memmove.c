/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:06:09 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/11 12:06:11 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!len || dest == src)
		return (dest);
	if (dest <= src)
		ft_memcpy(dest, src, len);
	else
	{
		while ((long long)--len >= 0)
			*((char *)dest + len) = *((char *)src + len);
	}
	return (dest);
}
