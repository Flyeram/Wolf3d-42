/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:02:21 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 11:39:03 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <wolf3d.h>
#include <stdlib.h>
#include <libft.h>

/*
**function which fill the image passing in with black pixel (color = 0x000000)
*/

void		clear_image(t_image *image)
{
	int		off_y;

	off_y = (*image).width * (*image).height * 4 - 1;
	(*image).cimg = ft_memset((*image).cimg, 0, off_y);
}

/*
**function which create a new image with a choosing width and height and return
**a new image with the data.
*/

t_image		*create_image(void *mlx, int width, int height)
{
	t_image		*image;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!((*image).img = mlx_new_image(mlx, width, height)))
		return (NULL);
	(*image).width = width;
	(*image).height = height;
	(*image).bpp = 0;
	(*image).sizeline = 0;
	(*image).endian = 0;
	(*image).cimg = mlx_get_data_addr((*image).img, &((*image).bpp),
					&((*image).sizeline), &((*image).endian));
	return (image);
}

/*
**function which put a color at the pos (x,y) on the image in the env struct
*/

void		image_put_pixel(t_env *env, int x, int y, unsigned int color)
{
	int		off_x;
	int		off_y;

	if (x >= 0 && x < env->win_size.x && y >= 0 && y < env->win_size.y)
	{
		off_x = x * (env->image->bpp / 8);
		off_y = (y * env->image->sizeline);
		*((unsigned int *)(env->image->cimg + off_y + off_x)) = color;
	}
}

/*
** function wich take a file_name and return a t_image with the xpm image
** specified.
*/

t_image		*create_xpm(void *mlx, char *file_name)
{
	t_image		*image;
	int			width;
	int			height;

	if (!(image = (t_image *)malloc(sizeof(t_image))))
		return (NULL);
	if (!((*image).img =
		mlx_xpm_file_to_image(mlx, file_name, &width, &height)))
		return (NULL);
	(*image).width = width;
	(*image).height = height;
	(*image).bpp = 0;
	(*image).sizeline = 0;
	(*image).endian = 0;
	(*image).cimg = mlx_get_data_addr((*image).img, &((*image).bpp),
					&((*image).sizeline), &((*image).endian));
	return (image);
}
