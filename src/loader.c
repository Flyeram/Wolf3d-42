/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:54:12 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/14 13:22:12 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>

int		loader_texture(t_env *env)
{
	env->texture->weapon_number = 0;
	env->texture->weapon_pos = 0;
	env->texture->weapon[0] = create_xpm(env->mlx,
		"texture/weapons/thon.xpm");
	env->texture->weapon[1] = create_xpm(env->mlx,
		"texture/weapons/wlongswordflame.xpm");
	env->texture->weapon[2] = create_xpm(env->mlx,
		"texture/weapons/firebladeoftai.xpm");
	env->texture->wall[0] = create_xpm(env->mlx,
		"texture/wall/greendragon.xpm");
	env->texture->wall[1] = create_xpm(env->mlx,
		"texture/wall/iron.xpm");
	env->texture->wall[2] = create_xpm(env->mlx,
		"texture/wall/marble.xpm");
	env->texture->wall[3] = create_xpm(env->mlx,
		"texture/wall/painting.xpm");
	env->texture->ceiling = create_xpm(env->mlx,
		"texture/ceiling/castleceiling.xpm");
	env->texture->tfloor = create_xpm(env->mlx,
		"texture/floor/castlecarpet.xpm");
	return (1);
}
