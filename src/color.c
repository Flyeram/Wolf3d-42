/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:35:34 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 11:31:37 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <stdlib.h>

/*
**function which take alpha, (red, green, blue) values between 0-255 and return
**a color which corrspond to the mix of rgb;
*/

unsigned int	create_color(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

t_color			color_percent(double r, double g, double b)
{
	t_color		new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

/*
** give the color of the pixel (x, y) of the texture given.
*/

unsigned int	get_color(t_image *texture, int x, int y)
{
	unsigned int	color;

	color = 0;
	if (y >= 0 && y < texture->height &&
		x >= 0 && x < texture->width)
	{
		color = *((unsigned int *)(texture->cimg + ((texture->sizeline *
			y) + (x * (texture->bpp / 8)))));
	}
	return (color);
}
