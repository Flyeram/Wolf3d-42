/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:15:33 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/16 12:33:31 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include <math.h>

int			expose(t_env *env)
{
	int		modulo;

	modulo = (env->texture->weapon_pos / (8 - (3 * env->event->shift))) % 2;
	mlx_put_image_to_window(env->mlx, env->win, env->image->img, 0, 0);
	mlx_put_image_to_window(env->mlx, env->win,
		env->texture->weapon[env->texture->weapon_number]->img, 500,
		550 - (20 * modulo));
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

void		move_forward(t_env *env)
{
	double		speed;

	speed = env->camera->speed.x * (env->event->shift + 1);
	env->texture->weapon_pos++;
	if (env->map_data->map[(int)(env->camera->origin.x + 2
		* env->camera->dir.x
		* speed)][(int)(env->camera->origin.y)] <= 1)
		env->camera->origin.x += env->camera->dir.x * speed;
	if (env->map_data->map[(int)(env->camera->origin.x)][
	(int)(env->camera->origin.y + 2 * env->camera->dir.y *
	speed)] <= 1)
		env->camera->origin.y += env->camera->dir.y * speed;
}

void		move_backward(t_env *env)
{
	double		speed;

	speed = env->camera->speed.x * (env->event->shift + 1);
	env->texture->weapon_pos++;
	if (env->map_data->map[(int)(env->camera->origin.x - 2
		* env->camera->dir.x
		* speed)][(int)env->camera->origin.y] <= 1)
		env->camera->origin.x -= env->camera->dir.x * speed;
	if (env->map_data->map[(int)(env->camera->origin.x)][
	(int)(env->camera->origin.y - 2 * env->camera->dir.y *
	speed)] <= 1)
		env->camera->origin.y -= env->camera->dir.y * speed;
}
