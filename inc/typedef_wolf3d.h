/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef_wolf3d.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbalu <tbalu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:15:00 by tbalu             #+#    #+#             */
/*   Updated: 2016/02/27 12:41:05 by tbalu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_WOLF3D_H
# define TYPEDEF_WOLF3D_H

typedef struct s_env		t_env;
typedef struct s_image		t_image;
typedef struct s_vector		t_vector;
typedef struct s_ray		t_ray;
typedef struct s_obj		t_obj;
typedef struct s_data		t_data;
typedef	struct s_color		t_color;
typedef	struct s_light		t_light;
typedef	struct s_material	t_material;
typedef	struct s_scene		t_scene;
typedef struct s_tmp		t_tmp;
typedef struct s_camera		t_camera;
typedef	int					(*t_intersect)(t_obj *, t_ray *, double *);
typedef	int					(*t_normale)(t_env *env, int current);
#endif
