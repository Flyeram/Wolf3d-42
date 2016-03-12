/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:50:08 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/12 17:12:28 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <wolf3d.h>

int			press_key(int key_code, t_env *env)
{
	if (key_code == 126)
		env->event->key_up = 1;
	else if (key_code == 125)
		env->event->key_down = 1;
	else if (key_code == 123)
		env->event->key_left = 1;
	else if (key_code == 124)
		env->event->key_right = 1;
	else if (key_code == 18)
		env->event->key_1 = 1;
	else if (key_code == 19)
		env->event->key_2 = 1;
	else if (key_code == 20)
		env->event->key_3 = 1;
	else if (key_code == 21)
		env->event->key_4 = 1;
	else if (key_code == 53)
		env->event->escape = 1;
	return (change_weapon(key_code, env));
}
