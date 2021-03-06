/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:14:59 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/26 10:50:55 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	int		i;
	int		len;

	len = ft_strlen(src);
	i = 0;
	while (i <= len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
