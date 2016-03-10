/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:53:27 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/10 19:28:29 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <math.h>

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
		text_point_y = y * 256 - env->win_size.y * 128 + h_line * 128;
		text_point_y = ((text_point_y * texture.height) / h_line) / 256;
		if (text_point_y >= 0 && text_point_y < texture.height &&
			text_point_x >= 0 && text_point_x < texture.width)
		{
			color = *((unsigned int *)(texture.cimg + ((texture.width * 4 *
				text_point_y) + (text_point_x * 4))));
			image_put_pixel(*env, x, y, color);
		}
		y++;
	}
}

void			calc_texture(t_env *env, t_vector *wall_limit, int side, int x)
{
	double		wall_hit;
	int			text_point_x;
	t_image		texture;

	env->texture->wall_number = which_texture_wall(env, side);
	texture = *(env->texture->wall[env->texture->wall_number]);
	wall_hit = (side == 0 ? env->camera->origin.y + env->value->perp_wall_dist
		* env->camera->ray_dir.y : env->camera->origin.x
		+ env->value->perp_wall_dist * env->camera->ray_dir.x);
	wall_hit -= floor(wall_hit);
	text_point_x = (int)(wall_hit * (double)(texture.width));
	if (side == 0 && env->camera->ray_dir.x > 0)
		text_point_x = texture.width - text_point_x - 1;
	if (side == 1 && env->camera->ray_dir.y < 0)
		text_point_x = texture.width - text_point_x - 1;
	draw_texture(env, wall_limit, text_point_x, x);
}
