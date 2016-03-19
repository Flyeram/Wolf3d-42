/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:46:20 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 15:33:00 by tbalu            ###   ########.fr       */
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
	mlx_do_key_autorepeatoff(env->mlx);
	mlx_loop_hook((*env).mlx, frame_expose, env);
	mlx_expose_hook((*env).win, expose, env);
	mlx_hook((*env).win, 2, (1L << 0), press_key, env);
	mlx_hook((*env).win, 3, (1L << 1), key_release, env);
	mlx_loop((*env).mlx);
}

int			main(int ac, char **av)
{
	t_env	*env;

	if (ac != 2)
		return (0);
	if (!(env = constructor_env(1080, 720, av[1])))
		return (0);
	env->camera->origin = create_vector(18, 22.5, 0);
	env->camera->dir = create_vector(-1.0, 0, 0);
	env->camera->plane = create_vector(0.0, 0.66, 0);
	env->camera->speed = create_vector(0.05, 0.040, 0);
	if (!(env->event = (t_event *)malloc(sizeof(t_event))))
		return (0);
	ft_bzero(env->event, sizeof(t_event));
	loader_texture(env);
	executor(env);
	return (0);
}
