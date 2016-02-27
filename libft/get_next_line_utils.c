/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:59:33 by tbalu             #+#    #+#             */
/*   Updated: 2015/12/14 17:03:51 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			lentonewline(char *str)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

t_buffer	*list_new(int fd, char *buff)
{
	t_buffer	*new_elem;

	if (!(new_elem = (t_buffer *)malloc(sizeof(t_buffer))))
		return (NULL);
	new_elem->fd = fd;
	new_elem->buff = buff;
	new_elem->next = NULL;
	return (new_elem);
}
