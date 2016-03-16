/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:53:27 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/16 14:07:03 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <math.h>
#include <stdio.h>
void			check_wall_dir(t_env *env, double wall_hit, int side)
{
	if (side == 0 && env->camera->ray_dir.x > 0)
	{
		env->value->wall_x = env->value->square_x;
		env->value->wall_y = (double)env->value->square_y + wall_hit;
	}
	else if (side == 0 && env->camera->ray_dir.x < 0)
	{
		env->value->wall_x = env->value->square_x + 1.0;
		env->value->wall_y = (double)env->value->square_y + wall_hit;
	}
	else if (side == 1 && env->camera->ray_dir.y > 0)
	{
		env->value->wall_x = (double)env->value->square_x + wall_hit;
		env->value->wall_y = env->value->square_y;
	}
	else
	{
		env->value->wall_x = (double)env->value->square_x + wall_hit;
		env->value->wall_y = env->value->square_y + 1.0;
	}
}

unsigned int	get_color(t_image *texture, int x, int y)
{
	unsigned int	color;

	color = 0;
	if (y >= 0 && y < texture->height &&
		x >= 0 && x < texture->width)
	{
		color = *((unsigned int *)(texture->cimg + ((texture->sizeline *
			y) + (x * (texture->bpp / 8)))));
	}
	return (color);
}

void			draw_sky_ceiling(t_env *env, t_vector *limit, int x)
{
	double	weight;
	double	floor_point[2];
	double	current_dist;
	int		text_point[2];

	while (limit->y < env->win_size.y)
	{
		current_dist = env->win_size.y / (2.0 * limit->y - env->win_size.y);
		weight = current_dist / env->value->wall_dist;
		floor_point[0] = weight * env->value->wall_x + (1.0 - weight) *
			env->camera->origin.x;
		floor_point[1] = weight * env->value->wall_y + (1.0 - weight) *
			env->camera->origin.y;
		text_point[0] = (int)(floor_point[0] * env->texture->ceiling[0]->width)
			% env->texture->ceiling[0]->width;
		text_point[1] = (int)(floor_point[1] * env->texture->ceiling[0]->height)
			% env->texture->ceiling[0]->height;
		image_put_pixel(*env, x, limit->y, (get_color(env->texture->tfloor[0],
			text_point[0], text_point[1]) >> 1) & 8355711);
		image_put_pixel(*env, x, env->win_size.y - limit->y,
			get_color(env->texture->ceiling[0], text_point[0], text_point[1]));
		limit->y++;
	}
}

unsigned int	which_texture_wall(t_env *env, int side)
{
	if (side == 0)
	{
		if (env->value->step.x == 1)
			return (0);
		else
			return (1);
	}
	else
	{
		if (env->value->step.y == 1)
			return (2);
		else
			return (3);
	}
}

void			draw_texture(t_env *env, t_vector *wall_limit, int text_point_x,
	int x)
{
	int				y;
	int				h_line;
	int				text_point_y;
	unsigned int	color;
	t_image			texture;

	texture = *(env->texture->wall[env->texture->wall_number]);
	y = wall_limit->x;
	h_line = wall_limit->z;
	while (y < wall_limit->y)
	{
		text_point_y = y * 2 - env->win_size.y + h_line;
		text_point_y = ((text_point_y * (texture.height / 2)) / h_line);
		color = get_color(&texture, text_point_x, text_point_y);
		image_put_pixel(*env, x, y, color);
		y++;
	}
}

void			calc_texture(t_env *env, t_vector *wall_limit, int side, int x)
{
	double		wall_hit;
	double		text_point_x;
	t_image		texture;

	env->texture->wall_number = which_texture_wall(env, side);
	texture = *(env->texture->wall[env->texture->wall_number]);
	wall_hit = (side == 0 ? env->camera->origin.y + env->value->wall_dist
		* env->camera->ray_dir.y : env->camera->origin.x
		+ env->value->wall_dist * env->camera->ray_dir.x);
	wall_hit -= floor(wall_hit);
	text_point_x = (int)(wall_hit * (double)(texture.width));
	if (side == 0 && env->camera->ray_dir.x > 0)
		text_point_x = texture.width - text_point_x - 1;
	if (side == 1 && env->camera->ray_dir.y < 0)
		text_point_x = texture.width - text_point_x - 1;
	draw_texture(env, wall_limit, text_point_x, x);
	check_wall_dir(env, wall_hit, side);
	draw_sky_ceiling(env, wall_limit, x);
}
