/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:09:24 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/28 16:10:49 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cpy;
	size_t	len1;
	size_t	len2;

	if (!(s1 && s2))
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(cpy = ft_strnew(len1 + len2 + 1)))
		return (NULL);
	cpy = ft_strncpy(cpy, s1, len1);
	cpy = ft_strncat(cpy, s2, len2);
	return (cpy);
}
