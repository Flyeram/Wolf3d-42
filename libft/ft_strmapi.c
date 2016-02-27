/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:16:30 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/28 15:56:59 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*s2;
	int		i;

	if (!(s && f))
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s2 = ft_strnew(len + 1);
	if (s2 != NULL)
	{
		while (s[i])
		{
			s2[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (s2);
}
