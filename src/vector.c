/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:24:34 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/02 15:54:24 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>
#include <math.h>
#include <stdlib.h>

/*
**function which create a new vector with his coordinates
**return the new vector
*/

t_vector	create_vector(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

/*
**function wich return the dot product of the two vectors
*/

double		dot_product(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

/*
**function which substract vector B from vector A and return a new vector
*/

t_vector	substract_vector(t_vector *a, t_vector *b)
{
	t_vector	new;

	new.x = a->x - b->x;
	new.y = a->y - b->y;
	new.z = a->z - b->z;
	return (new);
}

/*
**function which create a new vector which is the result of the addition of the
**two vector given to the function
*/

t_vector	add_vector(t_vector *a, t_vector *b)
{
	t_vector	new;

	new.x = a->x + b->x;
	new.y = a->y + b->y;
	new.z = a->z + b->z;
	return (new);
}

/*
**function which take a vector and a scalar and return a new vector which is the
**result of the multiplication of the vector by the scalar
*/

t_vector	vector_scale(t_vector *a, double k)
{
	t_vector	new;

	new.x = a->x * k;
	new.y = a->y * k;
	new.z = a->z * k;
	return (new);
}
