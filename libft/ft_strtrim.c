/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 10:47:43 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/28 16:15:40 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	len;

	if (!(s))
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	len = ft_strlen((char *)&s[start]);
	if (len != 0)
	{
		while (s[start + len - 1] == ' ' || s[start + len - 1] == '\n'
			|| s[start + len - 1] == '\t')
		{
			len--;
			if (len == 1)
				break ;
		}
	}
	return (ft_strsub(s, (unsigned int)start, len));
}
