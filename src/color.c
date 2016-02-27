/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 12:35:34 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/08 12:50:59 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rt_v.h>
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
