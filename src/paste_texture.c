/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:53:27 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/10 13:10:43 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <math.h>

void	paste_texture(t_env *env, t_vector *wall_limit, int x, int side)
{
	double		wall_hit;
	int			text_point;

	wall_hit = (side == 0 ? env->camera->origin.y + env->value->perp_wall_dist
		* env->camera->ray_dir.y : env->camera->origin.x
		+ env->value->perp_wall_dist * env->camera->ray_dir.x);
	wall_hit -= floor(wall_hit);
	text_point = (int)(wall_hit * (double);
}
