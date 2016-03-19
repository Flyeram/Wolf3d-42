/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 14:25:24 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 15:11:27 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_free_array(void ***array, int size)
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
