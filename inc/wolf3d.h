/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 12:57:32 by tbalu             #+#    #+#             */
/*   Updated: 2016/03/19 13:02:36 by tbalu            ###   ########.fr       */
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
	int		**hide_map;
	int		sizex_ar;
	int		sizey_ar;
};

struct			s_value
{
	t_vector	side_dist;
	t_vector	step;
	t_vector	delta_dist;
	double		wall_dist;
	double		wall_y;
	double		wall_x;
	int			square_x;
	int			square_y;
};

struct			s_texture
{
	int				weapon_number;
	int				wall_number;
	int				wall_time;
	unsigned int	weapon_pos;
	t_image			*weapon[3];
	t_image			*wall[4];
	t_image			*ceiling[1];
	t_image			*tfloor[1];
};

struct			s_event
{
	int		key_left;
	int		key_up;
	int		key_right;
	int		key_down;
	int		shift;
	int		escape;
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
	t_event			*event;
	double			win_ratio;
};

/*
** color
*/

unsigned int	create_color(int a, int r, int g, int b);
t_color			color_percent(double r, double g, double b);
unsigned int	get_color(t_image *texture, int x, int y);

/*
** image
*/

t_image			*create_image(void *mlx, int width, int height);
void			image_put_pixel(t_env *env, int x, int y,
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
int				frame_expose(t_env *env);
int				key_release(int key_code, t_env *env);
void			rotate_left(t_env *env);
void			rotate_right(t_env *env);
void			move_forward(t_env *env);
void			move_backward(t_env *env);
void			case_event(t_env *env);

/*
** vector
*/

t_vector		create_vector(double x, double y, double z);
double			dot_product(t_vector *a, t_vector *b);
t_vector		substract_vector(t_vector *a, t_vector *b);
t_vector		add_vector(t_vector *a, t_vector *b);
t_vector		vector_scale(t_vector *a, double k);
void			normalize(t_vector *vector);

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

/*
** draw_map
*/

void			draw_map(t_env *env);

#endif
