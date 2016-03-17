/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_iarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 12:19:28 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/17 12:28:33 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		**ft_create_iarray(int y, int x)
{
	int		**iarray;
	int		i;

	i = 0;
	if (!(iarray = (int **)malloc(y * sizeof(int *))))
		return (NULL);
	while (i < y)
	{
		if (!(iarray[i] = (int *)malloc(sizeof(int) * x)))
			return (NULL);
		i++;
	}
	return (iarray);
}
