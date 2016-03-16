/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:57:09 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/16 14:03:33 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <wolf3d.h>
#include <stdio.h>

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
			image_put_pixel(*env, x + pos->x, y + pos->y, color);
			y++;
		}
		x++;
	}
}

void	draw_map(t_env *env)
{
	t_vector	pos;
	t_vector	dimension;
	int			x;
	int			y;

	pos.x = 10;
	pos.y = 10;
	dimension.x = 5 * env->map_data->sizex_ar;
	dimension.y = 5 * env->map_data->sizey_ar;
	draw_rectangle(env, &pos, &dimension, 0);
	dimension.x = 5;
	dimension.y = 5;
	x = 0;
	while (x < env->map_data->sizex_ar)
	{
		y = 0;
		while (y < env->map_data->sizey_ar)
		{
			printf("%d, %d\n", x, y);
			if ((env->map_data->map)[y][x] > 0)
			{
				pos.x = 10 + 5 * x;
				pos.y = 10 + 5 * y;
				draw_rectangle(env, &pos, &dimension, 0xFF0000);
			}
			y++;
		}
		x++;
	}
	pos.x = env->camera->origin.x * 5 + 10;
	pos.y = env->camera->origin.y * 5 + 10;
	draw_rectangle(env, &pos, &dimension, 0xFFFF00);
}
