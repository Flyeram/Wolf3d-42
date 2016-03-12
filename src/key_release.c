/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:49:14 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/12 18:27:17 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <wolf3d.h>

int			key_release(int key_code, t_env *env)
{
	if (key_code == 126)
		env->event->key_up = 0;
	else if (key_code == 125)
		env->event->key_down = 0;
	else if (key_code == 123)
		env->event->key_left = 0;
	else if (key_code == 124)
		env->event->key_right = 0;
	else if (key_code == 257)
		env->event->shift = 0;
	else if (key_code == 53)
		env->event->escape = 0;
	return (1);
}
