/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 14:54:12 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/23 15:03:09 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <mlx.h>
#include <libft.h>
#include <stdlib.h>

void	load_gif(t_env *env)
{
	int		i;
	char	*fname;

	i = 1;
	fname = ft_strnew(150);
	while (i < 18)
	{
		ft_strcpy(fname, "texture/wall/dragon_gif/frame");
		ft_strcat(fname, ft_itoa(i));
		ft_strcat(fname, ".xpm");
		env->texture->wall[9 + i] = create_xpm(env->mlx, fname);
		i++;
	}
	free(fname);
}

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
		"texture/wall/signe.xpm");
	env->texture->wall[2] = create_xpm(env->mlx,
		"texture/wall/cocatrice.xpm");
	env->texture->wall[3] = create_xpm(env->mlx,
		"texture/wall/painting.xpm");
	env->texture->wall[4] = create_xpm(env->mlx,
		"texture/wall/flagend.xpm");
	env->texture->ceiling[0] = create_xpm(env->mlx,
		"texture/ceiling/castleceiling.xpm");
	env->texture->tfloor[0] = create_xpm(env->mlx,
		"texture/floor/castlecarpet.xpm");
	load_gif(env);
	return (1);
}
