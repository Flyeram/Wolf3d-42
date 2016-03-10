/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:57:32 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/10 17:03:53 by tbalu            ###   ########.fr       */
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
	t_vector	dir;
	t_vector	ray_dir;
	t_vector	plane;
	t_vector	speed;
};

struct			s_map_data
{
	int		**map;
	int		sizex_ar;
	int		sizey_ar;
};

struct			s_value
{
	t_vector	side_dist;
	t_vector	step;
	t_vector	delta_dist;
	double		perp_wall_dist;
};

struct			s_texture
{
	int				weapon_number;
	int				wall_number;
	unsigned int	weapon_pos;
	t_image			*weapon[3];
	t_image			*wall[4];
};

struct			s_env
{
	t_image			*image;
	void			*mlx;
	void			*win;
	t_vector		win_size;
	t_camera		*camera;
	t_map_data		*map_data;
	t_value			*value;
	t_texture		*texture;
	double			win_ratio;
};

/*
** color
*/

unsigned int	create_color(int a, int r, int g, int b);
t_color			color_percent(double r, double g, double b);

/*
** image
*/

t_image			*create_image(void *mlx, int width, int height);
void			image_put_pixel(t_env env, int x, int y,
				unsigned int color);
void			clear_image(t_image *image);
t_image			*create_xpm(void *mlx, char *file_name);

/*
** constructor
*/

int				constructor(t_env *env, char *fname);
t_env			*constructor_env(int win_x, int win_y, char *file_name);

/*
** draw_image
*/

void			draw_loop(t_env *env);

/*
** events
*/

int				press_key(int key_code, t_env *env);
int				expose(t_env *env);
int				change_weapon(int key_code, t_env *env);

/*
** vector
*/

t_vector		create_vector(double x, double y, double z);
double			dot_product(t_vector *a, t_vector *b);
t_vector		substract_vector(t_vector *a, t_vector *b);
t_vector		add_vector(t_vector *a, t_vector *b);
t_vector		vector_scale(t_vector *a, double k);

/*
** draw_verti
*/

void			draw_vertical(t_env *env, t_vector *limit, int x, int color);

/*
** loader
*/

int				loader_texture(t_env *env);

/*
** texture
*/

void			calc_texture(t_env *env, t_vector *wall_limit, int side, int x);

#endif
