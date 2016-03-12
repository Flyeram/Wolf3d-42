/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:01:05 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/12 15:38:18 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>

int			constructor_get_data(t_list **list, char **array, t_env *env)
{
	int			len;
	int			x;
	int			*tab_coords;
	t_list		*new_elem;

	x = 0;
	len = ft_arraylen(array);
	env->map_data->sizex_ar =
	(env->map_data->sizex_ar == 0 || env->map_data->sizex_ar == len) ? len : 0;
	if (env->map_data->sizex_ar == 0)
		return (0);
	if (!(tab_coords = (int *)malloc(sizeof(int) * len + 1)))
		return (0);
	tab_coords[len] = 0;
	while (array[x])
	{
		tab_coords[x] = ft_atoi(array[x]);
		x++;
	}
	new_elem = ft_lstnew(tab_coords, sizeof(int) * len + 1);
	ft_lsteadd(list, new_elem);
	return (1);
}

int			**constructor_conv_list(t_list **list, int y)
{
	int			**array;
	int			i;
	t_list		*next_elem;

	i = 0;
	if (!(array = (int **)malloc(y * sizeof(int *) + 1)))
		return (NULL);
	array[y] = NULL;
	next_elem = (*list)->next;
	while (next_elem)
	{
		array[i] = (*(*list)).content;
		free(*list);
		*list = next_elem;
		next_elem = (*list)->next;
		i++;
	}
	array[i] = (*(*list)).content;
	*list = next_elem;
	free(*list);
	return (array);
}

int			constructor_map(t_env *env, char *fname)
{
	int		fd[2];
	char	*line;
	char	**array;
	t_list	*list;

	list = NULL;
	line = NULL;
	fd[0] = open(fname, O_RDONLY);
	while ((fd[1] = get_next_line(fd[0], &line)))
	{
		if (fd[1] == -1)
			return (0);
		array = ft_strsplit(line, ' ');
		if (!(constructor_get_data(&list, array, env)))
			return (0);
		env->map_data->sizey_ar++;
	}
	if (!(env->map_data->map =
	constructor_conv_list(&list, env->map_data->sizey_ar)))
		return (0);
	return (1);
}

t_env		*constructor_env(int win_x, int win_y, char *file_name)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	ft_bzero(env, sizeof(t_env));
	if (!((*env).mlx = mlx_init()))
		return (NULL);
	(*env).win = mlx_new_window((*env).mlx, win_x, win_y, "WOLF3D");
	(*env).image = create_image((*env).mlx, win_x, win_y);
	(*env).win_size.x = win_x;
	(*env).win_size.y = win_y;
	(*env).win_ratio = (double)win_x / (double)win_y;
	if (!((*env).texture = (t_texture *)malloc(sizeof(t_texture))))
		return (0);
	if (!((*env).camera = (t_camera *)malloc(sizeof(t_camera))))
		return (0);
	if (!((*env).map_data = (t_map_data *)malloc(sizeof(t_map_data))))
		return (0);
	ft_bzero(env->map_data, sizeof(t_map_data));
	if (constructor_map(env, file_name) == 0)
		return (0);
	if (!(env->value = (t_value *)malloc(sizeof(t_value))))
		return (0);
	ft_bzero(env->value, sizeof(t_value));
	return (env);
}
