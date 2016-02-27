/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:57:40 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/28 15:24:52 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	char	*s2;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	s2 = ft_strnew(len + 1);
	if (s2 != NULL)
	{
		while (s[i])
		{
			s2[i] = (*f)(s[i]);
			i++;
		}
	}
	return (s2);
}
