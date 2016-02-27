/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 17:30:56 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/27 11:53:50 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	size_nb(long long n)
{
	int			len;

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

void		ft_putnbr_fd(int n, int fd)
{
	char		strnb[12];
	int			sign;
	int			len;
	long long	nb;

	nb = (long long)n;
	len = size_nb(nb);
	sign = (nb < 0) ? 1 : 0;
	if (nb < 0)
		nb = -nb;
	strnb[len + sign] = '\0';
	while (nb > 9)
	{
		strnb[len + sign - 1] = (nb % 10) + 48;
		nb /= 10;
		len--;
	}
	strnb[len + sign - 1] = (nb % 10) + 48;
	if (sign == 1)
		strnb[0] = '-';
	ft_putstr_fd(strnb, fd);
}
