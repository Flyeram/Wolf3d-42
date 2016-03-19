/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 17:06:35 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 12:09:46 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>
#include <stdlib.h>

void		normalize(t_vector *vector)
{
	double		norma;

	if ((norma = sqrt(dot_product(vector, vector))) != 0)
	{
		vector->x /= norma;
		vector->y /= norma;
		vector->z /= norma;
	}
}

t_vector	cross_product(t_vector *a, t_vector *b)
{
	t_vector	new;

	new.x = a->y * b->z - a->z * b->y;
	new.y = a->z * b->x - a->x * b->z;
	new.z = a->x * b->y - a->y * b->x;
	return (new);
}

double		dist_vector(t_vector *a, t_vector *b)
{
	return (sqrt(pow((b->x - a->x), 2) + pow((b->y - a->y), 2)
		+ pow((b->z - a->z), 2)));
}

int			resolv_quadratic(double discr, double *t, double b, double a)
{
	double		sqr;
	double		t_array[2];
	int			ret_value;

	ret_value = -1;
	sqr = sqrt(discr);
	t_array[0] = (-b - sqr) / (2 * a);
	t_array[1] = (-b + sqr) / (2 * a);
	if (t_array[0] > 0.0001f && (t_array[0] < *t))
	{
		*t = t_array[0];
		ret_value = 0;
	}
	if ((t_array[1] > 0.0001f) && (t_array[1] < *t))
	{
		*t = t_array[1];
		ret_value = 0;
	}
	return (ret_value);
}
