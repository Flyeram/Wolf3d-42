/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:28:18 by tbalu             #+#    #+#             */
/*   Updated: 2016/01/07 12:42:36 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	pos_search(char c)
{
	char	*comp;
	int		i;

	comp = "0123456789ABCDEF";
	i = 0;
	while (comp[i])
	{
		if (c == comp[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_hextodec(char *nb_hex)
{
	int		nb;
	int		i;
	int		pos;

	i = 0;
	nb = 0;
	while (nb_hex[i])
	{
		pos = pos_search(nb_hex[i]);
		if (pos == -1)
			return (nb);
		nb = nb * 16 + pos;
		i++;
	}
	return (nb);
}
