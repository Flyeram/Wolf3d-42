/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:00:10 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/12 15:23:34 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>

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
	draw_loop(env);
	return (expose(env));
}
