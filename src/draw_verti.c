/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_verti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:21:05 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/12 14:20:28 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <libft.h>

void	draw_vertical(t_env *env, t_vector *limit, int x, int color)
{
	while (limit->y >= limit->x)
	{
		image_put_pixel(*env, x, limit->y, color);
		limit->y--;
	}
}
