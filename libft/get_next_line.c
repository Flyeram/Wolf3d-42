/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:47:03 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/23 16:45:32 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int		gnl_realloc(char **line, char *buff, int len_buff)
{
	char	*tmp;
	int		i;
	int		len_line;

	i = 0;
	len_line = (*line == NULL) ? 0 : ft_strlen(*line);
	if (len_line != 0)
	{
		if (!(tmp = ft_strdup(*line)))
			return (-1);
		if (!(*line = ft_strnew(len_line + len_buff)))
			return (-1);
		*line = ft_strcpy(*line, tmp);
		free(tmp);
	}
	else if (!(*line = ft_strnew(len_line + len_buff)))
		return (-1);
	while (i < len_buff)
	{
		if (buff[i] == '\n')
			return (i + 1);
		(*line)[len_line + i] = buff[i];
		i++;
	}
	return (0);
}

int		gnl_addlist(t_buffer **list_buff, int fd, char *buff)
{
	t_buffer	*tmp;
	t_buffer	*last_next;
	t_buffer	*new_elem;

	if (!(new_elem = list_new(fd, buff)))
		return (-1);
	tmp = *list_buff;
	if (*list_buff == NULL)
	{
		*list_buff = new_elem;
		return (1);
	}
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			tmp->buff = ft_strdup(buff);
			free(new_elem);
			return (1);
		}
		last_next = tmp;
		tmp = tmp->next;
	}
	last_next->next = new_elem;
	return (1);
}

int		gnl_buff(char **line, int fd, t_buffer *list)
{
	int		len;

	while (list)
	{
		if ((*list).fd == fd)
		{
			if ((*list).buff == NULL)
				return (1);
			len = lentonewline((*list).buff);
			if (!(*line = ft_strnew(len)))
				return (-1);
			len = -1;
			while ((*list).buff[++len])
			{
				if (list->buff[len] == '\n')
					return (!(list->buff = &list->buff[len + 1]));
				(*line)[len] = list->buff[len];
			}
			(*list).buff = NULL;
			return (1);
		}
		list = list->next;
	}
	return (1);
}

int		gnl_read(char **line, int fd, t_buffer **list_buff)
{
	int			int_tab[2];
	char		*buff;
	int			return_value;

	if (!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((int_tab[1] = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[int_tab[1]] = '\0';
		if ((int_tab[0] = gnl_realloc(line, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (int_tab[0] > 0 && BUFF_SIZE == 1)
			return (1);
		if (int_tab[0] > 0 && BUFF_SIZE != 1)
		{
			return_value = gnl_addlist(list_buff, fd, &buff[int_tab[0]]);
			free(buff);
			return (return_value);
		}
	}
	return (int_tab[1]);
}

int		get_next_line(int const fd, char **line)
{
	static t_buffer	*list_buff = NULL;
	static int		end = -1;
	int				test;

	if (line == NULL)
		return (-1);
	*line = NULL;
	test = 1;
	if (list_buff != NULL)
		test = gnl_buff(line, fd, list_buff);
	if (test == 0)
		return (1);
	if (test == 1)
		test = gnl_read(line, fd, &list_buff);
	if (test == 0 && end == -1)
		return (0);
	else if (test == 1 && end == -1)
		end = 0;
	else if (test == 0 && *line && (*line)[0] == '\0')
		*line = NULL;
	else if (test == 0 && end == 0)
		return ((end = 1) ? 1 : 1);
	return (test);
}
