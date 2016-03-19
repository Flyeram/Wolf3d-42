/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:00:10 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 16:21:22 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>
#include <unistd.h>

int		change_weapon(int key_code, t_env *env)
{
	if (key_code >= 18 && key_code <= 23)
		env->texture->weapon_number = key_code - 18;
	if (key_code == 53)
		exit(3);
	draw_loop(env);
	return (expose(env));
}

int		frame_expose(t_env *env)
{
	t_event		key;

	key = *(env->event);
	if (key.key_up == 1)
		move_forward(env);
	if (key.key_down == 1)
		move_backward(env);
	if (key.key_right == 1)
		rotate_right(env);
	if (key.key_left == 1)
		rotate_left(env);
	if (key.escape == 1)
		exit(3);
	draw_loop(env);
	return (expose(env));
}

void	case_event(t_env *env)
{
	if ((int)env->camera->origin.x == 17 && (int)env->camera->origin.y == 21)
	{
		env->camera->origin = create_vector(1, 1.5, 0);
		env->camera->dir = create_vector(1.0, 0, 0);
		env->camera->plane = create_vector(0.0, -0.66, 0);
		ft_free_iarray((void ***)&env->map_data->map, env->map_data->sizey_ar);
		ft_free_iarray((void ***)&env->map_data->hide_map,
			env->map_data->sizey_ar);
		ft_bzero(env->event, sizeof(t_event));
		constructor_map(env, "maps/map_3.map");
	}
}
