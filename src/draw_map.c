/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:57:09 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 11:39:47 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <wolf3d.h>
#include <math.h>
#include <libft.h>

void	draw_rectangle(t_env *env, t_vector *pos, t_vector *dimension,
	unsigned int color)
{
	int		x;
	int		y;

	x = 0;
	(void)pos;
	while (x < dimension->x)
	{
		y = 0;
		while (y < dimension->y)
		{
			image_put_pixel(env, x + pos->x, y + pos->y, color);
			y++;
		}
		x++;
	}
}

void	draw_map_wall(t_env *env)
{
	int			x;
	int			y;
	t_vector	pos;
	t_vector	dimension;

	dimension.x = 5;
	dimension.y = 5;
	x = 0;
	while (x < env->map_data->sizex_ar)
	{
		y = 0;
		while (y < env->map_data->sizey_ar)
		{
			pos.x = 10 + 5 * x;
			pos.y = 10 + 5 * y;
			if ((env->map_data->hide_map)[y][x] > 0)
				draw_rectangle(env, &pos, &dimension, 0xFF0000);
			y++;
		}
		x++;
	}
}

void	reveal_pos(t_env *env)
{
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;

	pos_x = (int)env->camera->origin.x + 1;
	pos_y = (int)env->camera->origin.y + 1;
	x = pos_y - 2;
	while (x <= pos_y)
	{
		y = pos_x - 2;
		while (y <= pos_x)
		{
			env->map_data->hide_map[y][x] = env->map_data->map[y][x];
			y++;
		}
		x++;
	}
}

void	draw_pos_player(t_env *env)
{
	t_vector	pos;
	t_vector	dimension;
	t_vector	cam_pos;

	cam_pos = env->camera->origin;
	dimension.x = 5;
	dimension.y = 5;
	pos.y = (int)cam_pos.x * 5 + 10;
	pos.x = (int)cam_pos.y * 5 + 10;
	draw_rectangle(env, &pos, &dimension, 0xFFFF00);
}

void	draw_map(t_env *env)
{
	reveal_pos(env);
	draw_map_wall(env);
	draw_pos_player(env);
}
