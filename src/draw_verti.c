/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_verti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 14:21:05 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/03 14:53:01 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <libft.h>

void	draw_vertical(t_env *env, t_vector *limit, int x, int color)
{
	float	min;
	float	max;

	min = ft_min(limit->x, limit->y);
	max = ft_max(limit->x, limit->y);
	while (min <= max)
	{
		image_put_pixel(*env, x, min, color);
		min++;
	}
}
