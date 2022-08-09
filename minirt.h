/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:21:25 by lcorinna          #+#    #+#             */
/*   Updated: 2022/08/09 19:13:06 by lcorinna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "mlx/mlx.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/* shapes */
# define SPHERE 1
# define PLANE 2
# define CYLINDER 3

/*  window */
# define WIDTH 800
# define HEIGHT 600

/* color */
# define BLACK 0
# define WHITE 16777215
# define RED 16711680
# define GREEN 65280
# define BLUE 255

/* coefficients */
# define DIFF 2
# define SPEC 4
# define SHADOW -30

/* steps */
# define FOV 10
# define MOVE 10
# define ROTATE 0.2617994 // пи / 12

/* buttons */
# define LMB 1
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define R_UP 13
# define R_DOWN 1
# define R_LEFT 0
# define R_RIGHT 2
# define ESC 53
# define PLUS 69
# define MINUS 78
# define SH_UP 91
# define SH_LEFT 86
# define SH_RIGHT 88
# define SH_DOWN 84
# define SH_PLUS 92
# define SH_MINUS 89

typedef struct s_vec3
{
	float				x;
	float				y;
	float				z;
}	t_vec3;

typedef struct s_discrmn
{
	float				a;
	float				b;
	float				c;
	float				discr;
	float				res;

	t_vec3				tmp;
	t_vec3				ca;
}	t_discrmn;

typedef struct s_ambient
{
	float				bright;
	t_vec3				clr;
	int					flag;
}	t_ambient;

typedef struct s_camera
{
	t_vec3				origin;
	t_vec3				direction;
	float				fov;
	float				angle_y;
	float				angle_z;
	int					flag;
}	t_camera;

typedef struct s_light
{
	t_vec3				pos;
	float				bright;
	t_vec3				clr;
	int					flag;
}	t_light;

typedef struct s_shapes
{
	int					type;
	t_vec3				pos;
	t_vec3				clr;
	float				rad;
	t_vec3				direction;
	float				diameter;
	float				height;
	struct s_main		*data;
	struct s_shapes		*next;
}	t_shapes;

typedef struct s_scene
{
	t_ambient			amb;
	t_camera			cam;
	t_light				lght;
	t_shapes			*sh;
	float				width;
	float				height;
}	t_scene;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;

	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_mlx;

typedef struct s_main
{
	int				fd;
	char			*n_wndw;
	char			**maps;
	t_scene			scene;
	t_mlx			mlx;
}	t_main;

/* parser */
int			ft_parser(int argc, char **argv, t_main *data);
void		ft_clean_maps(t_main *data);
void		ft_writing_scene(t_main *data);
void		ft_which_element(t_main *data, char *str);
void		ft_type_selection(t_main *data, char *type, char *str);

/* parser_utils */
void		ft_check_file(t_main *data, char *f_name);
void		ft_read_file(t_main *data, char *f_name);
int			ft_count_lines(t_main *data);
void		ft_writing_array(t_main *data, int count, char *f_name);
void		ft_data_entry_error(char *str, t_shapes *shape, int flag);

/* skip_char */
int			ft_skip_invisible_char(char *str, int i);
int			ft_skip_visible_char(char *str, int i);
int			ft_skip_visible_char_munis(char *str, int i);
int			ft_search_next_value(char *str, int i, int flag);
int			ft_check_dir(t_vec3 dir);

/* pars_point */
t_vec3		ft_pars_clr(t_main *data, char *str, t_vec3	clr);

/* pars_color */
t_vec3		ft_point_in_space(t_main *data, char *str);

/* ambiant */
void		ft_check_repetitions(t_main *data, char *str, char *type);
void		ft_ambiant(t_main *data, char *type, char *str);
float		ft_ratio_ambiant(t_main *data, char *str, float bright);

/* scene */
t_scene		ft_new_scene(void);

/* camera */
void		ft_camera(t_main *data, char *type, char *str);

/* light */
void		ft_light(t_main *data, char *str);

/* scene_list */
void		ft_shape_add_front(t_shapes **lst, t_shapes *new);
t_shapes	*ft_shape_last(t_shapes *lst);
void		ft_shape_add_back(t_shapes **lst, t_shapes *new);

/* plane */
void		ft_plane(t_main *data, char *str);

/* sphere */
void		ft_sphere(t_main *data, char *str);
float		ft_found_diameter(char *str);

/* cylinder */
void		ft_cylinder(t_main *data, char *str, int i);

/* vec3_one */
t_vec3		ft_new_vec3(float x, float y, float z);
t_vec3		ft_add(t_vec3 *a, t_vec3 *b);
t_vec3		ft_add3(t_vec3 *a, t_vec3 *b, t_vec3 *c);
t_vec3		ft_sub(t_vec3 *a, t_vec3 *b);
t_vec3		ft_norm(t_vec3 *a);

/* vec3_two */
float		ft_length(t_vec3 a);
t_vec3		ft_mul(t_vec3 *a, t_vec3 *b);
t_vec3		ft_s_mul(t_vec3 *a, float value);
float		ft_dot(t_vec3 *a, t_vec3 *b);
t_vec3		ft_cross(t_vec3 *a, t_vec3 *b);

/* vec3_three */
float		ft_dist(t_vec3 a, t_vec3 b);
t_vec3		ft_reflect(t_vec3 *rd, t_vec3 *n);

/* draw */
void		ft_draw_loop(t_main *data, t_scene *scene, t_mlx *mlx);
t_vec3		ft_find_dir(float dst, int x, int y, t_vec3	cam_dir);
t_vec3		ft_rotate_dir(t_camera *cam, t_vec3 *dir);
float		ft_find_dist(t_shapes *sh, t_vec3 *cam_origin, t_vec3 *direction);

/* interesect */
int			ft_intersection(t_main *data, t_shapes *sh, t_vec3 direction);

/* interesect_utils */
float		ft_cylinder_intersect(t_shapes *cyl, t_vec3 *cam_origin, \
											t_vec3 *direction, t_discrmn box);
t_vec3		ft_cylinder_norm(t_shapes *cyl, t_vec3 *inter_point);

/* lighting */
int			ft_lighting(t_main *data, t_shapes *shape, t_vec3 *direction, \
																	float dist);

/* add_colors */
int			ft_add_clr3(int c1, int c2, int c3);
int			ft_add_clr(int color, int coef);
int			ft_mul_clr(t_vec3 clr, float ratio);

/* common_buttons */
void		ft_general_scene(int key, t_main *data);
int			ft_exit_cross(int key, t_main *data);

/* movement_buttons */
int			ft_move_light(int key, t_main *data);
int			ft_move_shape(int key, t_shapes *sh);

/* mouse */
int			ft_mouse(int button, int x, int y, void *data1);

/* program_completion */
void		ft_exit(t_main *data, char *str, int flag);

#endif
