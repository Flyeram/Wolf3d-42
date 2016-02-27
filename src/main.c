/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 12:46:20 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/27 12:47:37 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft.h>
#include <unistd.h>
#include <rt_v.h>
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
	env = constructor_env(1080, 720);
	env->camera->origin = create_vector(500, -100.0f, -1000.0f);
	env->scene = constructor_scene(av[1]);
	env->win_ratio = (double)env->win_size.x / (double)env->win_size.y;
	if (env->scene == NULL)
		return (0);
	executor(env);
	return (0);
}
