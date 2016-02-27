/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:02:13 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/28 16:01:15 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	i;

	if (!(s))
		return (NULL);
	i = 0;
	if (!(cpy = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		cpy[i] = s[start + i];
		i++;
	}
	return (cpy);
}
