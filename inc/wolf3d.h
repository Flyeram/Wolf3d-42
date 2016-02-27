/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:57:32 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/27 12:46:01 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <typedef_wolf3d.h>

struct			s_vector
{
	double		x;
	double		y;
	double		z;
};

struct			s_ray
{
	t_vector	start;
	t_vector	dir;
};

struct			s_image
{
	char		*cimg;
	void		*img;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
};

struct			s_color
{
	double		r;
	double		g;
	double		b;
};

struct			s_camera
{
	t_vector	origin;
	double		pitch;
	double		yaw;
	double		roll;
};

struct			s_env
{
	t_image			*image;
	void			*mlx;
	void			*win;
	t_vector		win_size;
	t_camera		*camera;
	double			win_ratio;
};

/*
**color
*/

unsigned int	create_color(int a, int r, int g, int b);
t_color			color_percent(double r, double g, double b);

/*
**image
*/

t_image			*create_image(void *mlx, int width, int height);
void			image_put_pixel(t_env env, int x, int y,
				unsigned int color);
void			clear_image(t_image *image);

/*
**constructor
*/

int				constructor(t_env *env, char *fname);
t_env			*constructor_env(int win_x, int win_y);

/*
**draw_image
*/

void			draw_loop(t_env *env);

/*
**events
*/

int				press_key(int key_code, t_env *env);
int				mouse(int button, int x, int y, t_env *env);
int				mouse_motion(int x, int y, t_env *env);
int				expose(t_env *env);

/*
**vector
*/

t_vector		create_vector(double x, double y, double z);
double			dot_product(t_vector *a, t_vector *b);
t_vector		substract_vector(t_vector *a, t_vector *b);
t_vector		add_vector(t_vector *a, t_vector *b);
t_vector		vector_scale(t_vector *a, double k);

#endif
