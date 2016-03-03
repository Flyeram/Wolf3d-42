/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:15:33 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/03 16:34:21 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include <math.h>

int			expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->image->img, 0, 0);
	return (1);
}

void		rotate_left(t_env *env)
{
	double	old_dir;
	double	old_plane;

	old_dir = env->camera->dir.x;
	env->camera->dir.x = old_dir * cos(env->camera->speed.y) -
		env->camera->dir.y * sin(env->camera->speed.y);
	env->camera->dir.y = old_dir * sin(env->camera->speed.y) +
		env->camera->dir.y * cos(env->camera->speed.y);
	old_plane = env->camera->plane.x;
	env->camera->plane.x = old_plane * cos(env->camera->speed.y) -
		env->camera->plane.y * sin(env->camera->speed.y);
	env->camera->plane.y = old_plane * sin(env->camera->speed.y) +
		env->camera->plane.y * cos(env->camera->speed.y);
}

void		rotate_right(t_env *env)
{
	double	old_dir;
	double	old_plane;

	old_dir = env->camera->dir.x;
	env->camera->dir.x = old_dir * cos(-env->camera->speed.y) -
		env->camera->dir.y * sin(-env->camera->speed.y);
	env->camera->dir.y = old_dir * sin(-env->camera->speed.y) +
		env->camera->dir.y * cos(-env->camera->speed.y);
	old_plane = env->camera->plane.x;
	env->camera->plane.x = old_plane * cos(-env->camera->speed.y) -
		env->camera->plane.y * sin(-env->camera->speed.y);
	env->camera->plane.y = old_plane * sin(-env->camera->speed.y) +
		env->camera->plane.y * cos(-env->camera->speed.y);
}

int			press_key_rotate(int key_code, t_env *env)
{
	if (key_code == 123)
		rotate_left(env);
	if (key_code == 124)
		rotate_right(env);
	draw_loop(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image->img, 0, 0);
	return (0);
}

int			press_key(int key_code, t_env *env)
{
	if (key_code == 53)
		exit(3);
	if (key_code == 126)
	{
		if (env->map_data->map[(int)(env->camera->origin.x + env->camera->dir.x
		* env->camera->speed.x)][(int)(env->camera->origin.y)] == 0)
			env->camera->origin.x += env->camera->dir.x * env->camera->speed.x;
		if (env->map_data->map[(int)(env->camera->origin.x)][
		(int)(env->camera->origin.y + env->camera->dir.y *
		env->camera->speed.x)] == 0)
			env->camera->origin.y += env->camera->dir.y * env->camera->speed.x;
	}
	if (key_code == 125)
	{
		if (env->map_data->map[(int)(env->camera->origin.x - env->camera->dir.x
		* env->camera->speed.x)][(int)env->camera->origin.y] == 0)
			env->camera->origin.x -= env->camera->dir.x * env->camera->speed.x;
		if (env->map_data->map[(int)(env->camera->origin.x)][
		(int)(env->camera->origin.y - env->camera->dir.y *
		env->camera->speed.x)] == 0)
			env->camera->origin.y -= env->camera->dir.y * env->camera->speed.x;
	}
	return (press_key_rotate(key_code, env));
}
