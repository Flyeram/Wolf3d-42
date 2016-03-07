/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:46:20 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/07 12:35:28 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <unistd.h>
#include <wolf3d.h>
#include <stdlib.h>

/*
**function which initialize the events and start the loop
*/

void		executor(t_env *env)
{
	draw_loop(env);
	mlx_expose_hook((*env).win, expose, env);
	mlx_hook((*env).win, 2, (1L << 0), press_key, env);
	mlx_loop((*env).mlx);
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		return (0);
	if (!(env = constructor_env(1080, 720, av[1])))
		return (0);
	env->camera->origin = create_vector(22, 12, 0);
	env->camera->dir = create_vector(-1.1, 0, 0);
	env->camera->plane = create_vector(0, 0.66, 0);
	env->camera->speed = create_vector(0.25, 0.05, 0);
	env->texture->weapon = create_xpm(env->mlx, "texture/thon.xpm");
	executor(env);
	return (0);
}
