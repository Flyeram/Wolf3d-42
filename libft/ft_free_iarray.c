/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_iarray.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:25:24 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 15:54:00 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_iarray(void ***array, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
