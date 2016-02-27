/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:51:46 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/27 12:45:18 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt_v.h>
#include <stdlib.h>
#include <libft.h>
#include <math.h>

/*
** function to initialize all the variable for each iteration
*/

void		initialize_draw(t_env *env, int x, int y)
{
	double		xx;
	double		yy;

	xx = (2 * ((double)x / (double)env->win_size.x) - 1) *
	env->win_ratio * ZOOM;
	yy = (1 - 2 * ((double)y / (double)env->win_size.y)) * ZOOM;
	env->data_scene->ray->dir.x = xx * cos(env->yaw) * cos(env->pitch) +
	yy * (cos(env->yaw) * sin(env->pitch) * sin(env->roll) - sin(env->yaw) *
	cos(env->roll)) + cos(env->yaw) * sin(env->pitch) * cos(env->roll) +
	sin(env->yaw) * sin(env->roll);
	env->data_scene->ray->dir.y = xx * sin(env->yaw) * cos(env->pitch) + yy *
	(sin(env->yaw) * sin(env->pitch) * sin(env->roll) + cos(env->yaw) *
	cos(env->roll)) + sin(env->yaw) * sin(env->pitch) * cos(env->roll) -
	cos(env->yaw) * sin(env->roll);
	env->data_scene->ray->dir.z = xx * -sin(env->pitch) + yy * cos(env->pitch)
	* sin(env->roll) + cos(env->pitch) * cos(env->roll);
	env->data_scene->ray->dir = normalize(&env->data_scene->ray->dir);
	env->data_scene->ray->start = env->camera->origin;
}
