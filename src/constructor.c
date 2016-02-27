/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 13:01:05 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/27 12:44:26 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt_v.h>
#include <libft.h>
#include <mlx.h>
#include <stdlib.h>
#include <fcntl.h>

t_env		*constructor_env(int win_x, int win_y)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	if (!((*env).mlx = mlx_init()))
		return (NULL);
	(*env).win = mlx_new_window((*env).mlx, win_x, win_y, "WOLF3D");
	(*env).image = create_image((*env).mlx, win_x, win_y);
	(*env).win_size.x = win_x;
	(*env).win_size.y = win_y;
	if (!((*env).camera = (t_camera *)malloc(sizeof(t_camera))))
		return (0);
	return (env);
}
