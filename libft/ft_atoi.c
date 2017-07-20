/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:28:35 by gdelabro          #+#    #+#             */
/*   Updated: 2016/11/07 12:00:08 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	nb;
	int		i;
	int		i2;

	i = 0;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	i2 = i;
	if (str[i] != '-' && str[i] != '+' && (str[i] > '9' || str[i] < '0'))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		nb *= 10;
		nb += str[i] - 48;
		i++;
	}
	if (str[i2] == '-')
		return (-nb);
	return (nb);
}
