/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:59:20 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/26 15:24:30 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;
	unsigned char *temp;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	temp = (unsigned char *)ft_strdup((char *)s);
	dst = ft_memcpy(d, temp, len);
	ft_memdel((void **)&temp);
	return (dst);
}
