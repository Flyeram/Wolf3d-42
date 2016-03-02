/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:51:46 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/02 17:25:09 by tbalu            ###   ########.fr       */
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

}

void			draw_loop(t_env *env)
{
	int		x;

	x = 0;
	while (x < env->win_size.x)
	{
		initialize_draw(env, x);
	}
}
