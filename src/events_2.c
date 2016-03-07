/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:00:10 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/07 14:10:11 by tbalu            ###   ########.fr       */
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
	return (expose(env));
}
