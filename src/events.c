/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 11:15:33 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/02 13:31:50 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
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
	draw_loop(env);
	mlx_put_image_to_window(env->mlx, env->win, env->image->img, 0, 0);
	return (0);
}

int			press_key(int key_code, t_env *env)
{
	if (key_code == 53)
		exit(3);
	return (press_key_2(key_code, env));
}
