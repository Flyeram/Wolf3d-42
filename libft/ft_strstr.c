/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 12:12:38 by tbalu             #+#    #+#             */
/*   Updated: 2015/11/26 12:58:01 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int	tab_ind[3];

	tab_ind[0] = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[tab_ind[0]] != '\0')
	{
		if (s1[tab_ind[0]] == s2[0])
		{
			tab_ind[1] = 0;
			tab_ind[2] = 0;
			while (s2[tab_ind[1]] != '\0' && tab_ind[2] == 0)
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
