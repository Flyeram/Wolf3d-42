/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:22:22 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/08 14:38:35 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (ft_isblank(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(ft_isdigit((int)str[i])))
			return (nb * sign);
		else
			nb += str[i] - '0';
		if (ft_isdigit((int)str[i + 1]))
			nb *= 10;
		else
			break ;
		i++;
	}
	return (nb * sign);
}
