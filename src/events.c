/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:15:33 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/27 12:46:40 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt_v.h>
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>

int			expose(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->image->img, 0, 0);
	return (1);
}

int			press_key_2(int key_code, t_env *env)
{
	if (key_code == 27)
		env->camera->origin.x += 50;
	if (key_code == 24)
		env->camera->origin.x -= 50;
	if (key_code == 116)
		env->camera->origin.y -= 50;
	if (key_code == 121)
		env->camera->origin.y += 50;
	if (key_code == 69)
		env->camera->origin.z += 50;
	if (key_code == 78)
		env->camera->origin.z -= 50;
	draw_loop(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image->img, 0, 0);
	return (0);
}

int			press_key(int key_code, t_env *env)
{
	if (key_code == 53)
		exit(3);
	if (key_code == 123)
		env->camera->pitch -= 0.05;
	if (key_code == 124)
		env->camera->pitch += 0.05;
	if (key_code == 125)
		env->camera->roll += 0.05;
	if (key_code == 126)
		env->camera->roll -= 0.05;
	if (key_code == 115)
		env->camera->yaw += 0.05;
	if (key_code == 119)
		env->camera->yaw -= 0.05;
	return (press_key_2(key_code, env));
}
