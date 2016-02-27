/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:45:02 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/27 12:08:33 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	tab_ind[3];

	tab_ind[0] = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[tab_ind[0]] != '\0' && tab_ind[0] < n)
	{
		if (s1[tab_ind[0]] == s2[0])
		{
			tab_ind[1] = 0;
			tab_ind[2] = 0;
			while (tab_ind[2] == 0 && tab_ind[1] < (n - tab_ind[0]))
			{
				if (s1[tab_ind[0] + tab_ind[1]] != s2[tab_ind[1]])
					tab_ind[2] = 1;
				else if (s2[tab_ind[1] + 1] == '\0')
					return ((char *)&s1[tab_ind[0]]);
				tab_ind[1]++;
			}
		}
		tab_ind[0]++;
	}
	return (NULL);
}
