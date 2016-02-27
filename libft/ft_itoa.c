/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:59:14 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/27 12:23:39 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

static	int		size_nb(long long n)
{
	int		len;

	len = 1;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*strnb;
	int			sign;
	int			len;
	long long	nb;

	nb = (long long)n;
	len = size_nb(nb);
	sign = (nb < 0) ? 1 : 0;
	if (nb < 0)
		nb = -nb;
	if (!(strnb = ft_strnew(len + sign)))
		return (NULL);
	while (nb > 9)
	{
		strnb[len + sign - 1] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	strnb[len + sign - 1] = (nb % 10) + 48;
	if (sign == 1)
		strnb[0] = '-';
	return (strnb);
}
