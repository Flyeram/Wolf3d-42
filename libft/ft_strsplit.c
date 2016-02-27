/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:22:02 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/03 14:26:10 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static	char	*ft_trim(char const *s, char c)
{
	size_t	start;
	size_t	len;

	if (!(s))
		return (NULL);
	start = 0;
	while (s[start] == c)
		start++;
	len = ft_strlen((char *)&s[start]);
	if (len != 0)
	{
		while (s[start + len - 1] == c)
		{
			len--;
			if (len == 1)
				break ;
		}
	}
	return (ft_strsub(s, (unsigned int)start, len));
}

static	size_t	len_array(char *str, char c)
{
	size_t	i;
	size_t	nb_case;

	i = 0;
	nb_case = 1;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			nb_case++;
			i--;
		}
		i++;
	}
	return (nb_case);
}

static	size_t	len_word(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	var[3];
	char	**array;
	size_t	len[2];
	char	*str;

	if (!(str = ft_trim(s, c)))
		return (NULL);
	len[0] = len_array(str, c);
	if (!(array = (char **)ft_memalloc(sizeof(char *) * (int)(len[0] + 1))))
		return (NULL);
	var[0] = 0;
	var[1] = 0;
	while (str[var[0]])
	{
		var[2] = 0;
		len[1] = len_word(&str[var[0]], c);
		if (!(array[var[1]] = ft_strnew(len[1])))
			return (ft_free_array(array));
		while (str[var[0]] != c && str[var[0]])
			array[var[1]][var[2]++] = str[var[0]++];
		while (str[var[0]] == c)
			var[0]++;
		var[1]++;
	}
	return (array);
}
