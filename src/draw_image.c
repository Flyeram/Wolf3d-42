/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:51:46 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/10 17:04:47 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>
#include <libft.h>
#include <math.h>

void			initialize_draw(t_env *env, int x)
{
	double		camera_x;

	camera_x = 2 * x / (double)env->win_size.x - 1;
	env->camera->ray_dir = vector_scale(&env->camera->plane, camera_x);
	env->camera->ray_dir = add_vector(&env->camera->dir, &env->camera->ray_dir);
	env->value->delta_dist.x = sqrt(1 + (pow(env->camera->ray_dir.y, 2) /
		(pow(env->camera->ray_dir.x, 2))));
	env->value->delta_dist.y = sqrt(1 + (pow(env->camera->ray_dir.x, 2) /
		(pow(env->camera->ray_dir.y, 2))));
}

void			calculate_step(t_env *env, int square_x, int square_y)
{
	if (env->camera->ray_dir.x < 0)
	{
		env->value->step.x = -1;
		env->value->side_dist.x = (env->camera->origin.x - square_x) *
			env->value->delta_dist.x;
	}
	else
	{
		env->value->step.x = 1;
		env->value->side_dist.x = (square_x + 1.0 - env->camera->origin.x) *
			env->value->delta_dist.x;
	}
	if (env->camera->ray_dir.y < 0)
	{
		env->value->step.y = -1;
		env->value->side_dist.y = (env->camera->origin.y - square_y) *
			env->value->delta_dist.y;
	}
	else
	{
		env->value->step.y = 1;
		env->value->side_dist.y = (square_y + 1.0 - env->camera->origin.y) *
			env->value->delta_dist.y;
	}
}

int				dda_check(t_env *env, int *square_x, int *square_y)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (env->value->side_dist.x < env->value->side_dist.y)
		{
			env->value->side_dist.x += env->value->delta_dist.x;
			*square_x += env->value->step.x;
			side = 0;
		}
		else
		{
			env->value->side_dist.y += env->value->delta_dist.y;
			*square_y += env->value->step.y;
			side = 1;
		}
		if (env->map_data->map[*square_x][*square_y] > 0)
			hit = 1;
	}
	return (side);
}

void			draw_line(t_env *env, int side, int x)
{
	int			h_line;
	t_vector	wall_limit;
	t_vector	ground_limit;
	t_vector	sky_limit;

	h_line = (int)(env->win_size.y / env->value->perp_wall_dist);
	wall_limit.z = h_line;
	wall_limit.x = -h_line / 2 + env->win_size.y / 2;
	if (wall_limit.x < 0)
		wall_limit.x = 0;
	wall_limit.y = h_line / 2 + env->win_size.y / 2;
	if (wall_limit.y >= env->win_size.y)
		wall_limit.y = env->win_size.y - 1;
	ground_limit.x = 0;
	ground_limit.y = wall_limit.x - 1;
	sky_limit.x = wall_limit.y - 1;
	sky_limit.y = env->win_size.y - 1;
	draw_vertical(env, &ground_limit, x, create_color(0, 123, 123, 255));
	draw_vertical(env, &sky_limit, x, create_color(0, 0, 0, 123));
	calc_texture(env, &wall_limit, side, x);
}

void			draw_loop(t_env *env)
{
	int		x;
	int		square_x;
	int		square_y;
	int		side;

	x = 0;
	while (x < env->win_size.x)
	{
		square_x = (int)env->camera->origin.x;
		square_y = (int)env->camera->origin.y;
		initialize_draw(env, x);
		calculate_step(env, square_x, square_y);
		side = dda_check(env, &square_x, &square_y);
		env->value->perp_wall_dist = (side == 0 ?
			(square_x - env->camera->origin.x + (1 - env->value->step.x) / 2) /
			env->camera->ray_dir.x : (square_y - env->camera->origin.y +
			(1 - env->value->step.y) / 2) / env->camera->ray_dir.y);
		draw_line(env, side, x);
		x++;
	}
}
