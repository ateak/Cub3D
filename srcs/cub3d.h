/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:31:23 by ateak             #+#    #+#             */
/*   Updated: 2022/10/26 19:55:21 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx/mlx.h"

# define WIN_W 640
# define WIN_H 480
# define WIN_NAME "cub3D"
# define TEXTURE_W 64
# define TEXTURE_H 64
# define FIELD_OF_VIEW 0.66

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define REDCROSS 17
# define PRESS 2
# define RELEASE 3

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		map_width;
	int		map_height;
	int		map_components;
	char	*ceiling;
	char	*floor;
	int		ceiling_clr;
	int		floor_clr;
	char	**map_array;
}			t_map;

typedef struct s_wall
{
	int		x;
	int		y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		rend_start;
	int		rend_end;
	double	wall_x;
	int		texture_num;
	int		texture_x;
	int		texture_y;
	double	texture_pos;
	double	step;
	int		color;
}			t_wall;

typedef struct s_img
{
	void	*img;
	int		len;
	int		bpp;
	int		endian;
	int		img_w;
	int		img_h;
	int		*data;
}			t_img;

typedef struct s_controls
{
	int		key_open;
	int		key_esc;
	int		key_up;
	int		key_down;
	int		key_left;
	int		key_right;
	int		key_arr_left;
	int		key_arr_right;
}			t_controls;

typedef struct s_info
{
	double		player_x;
	double		player_y;
	double		pl_dir_x;
	double		pl_dir_y;
	double		cam_pln_x;
	double		cam_pln_y;
	double		speed_rotate;
	double		speed_move;
	int			players;
	void		*win;
	void		*mlx;
	int			**textures;
	int			buf_img[WIN_H][WIN_W];
	t_map		map;
	t_img		img;
	t_controls	ctrl;
}				t_info;

//PARSER

//parser_first_check.c
int		first_check(int argc, char **argv);
void	check_map_extension(char **argv);

//parser_main.c
void	parser(t_info *data, char **argv, int fd);
void	get_map_data(char ***map, char **argv, int fd);
void	save_map_into_array(char **map, t_info *data, int i);

//parser_get_colour_texture_info.c
int		parse_map_data(char ***map, t_info *data, int i);
int		colour_texture_info(char *str);
void	get_colour_texture_info(t_info *data, char **splitted_line);

//parser_save_texture.c
void	save_texture(char **splitted_line, char **texture_path, t_info *data);

//parser_save_colour.c
void	save_colour(char **splitted_line, char **colour, t_info *data);

//parser_check_player_find_map_size.c
void	check_player_find_map_size(char	**map, t_info *data, int i);

//parser_check_map_border.c
void	check_map_height_border(char **map, t_info *data);
void	check_map_width_border(char **map, t_info *data);
void	check_border_map_in_height(char **map, t_info *data);
void	check_border_map_in_width(char **map, t_info *data);
void	map_error_exit(char error, char symbol, int i, int j);

//MAIN_PART

//init.c
void	init_data(t_info *data);
void	init_map(t_info *data);

//working_with_textures.c
int		malloc_for_textures(t_info *data);
void	import_textures(t_info *data);
void	make_xpm(t_info *data, int *texture, char *path, t_img *img);

//game_loop.c
int		game_loop(t_info *data);
void	fill_floor_and_ceiling(t_info *data);
void	wall_casting(t_info *data);
void	rendering(t_info *data);
void	key_action(t_info *data);

//wall_casting_prt1.c
void	wall_casting(t_info *data);
void	ft_get_position(t_info *data, t_wall *wall);
void	ft_get_step_side_dist(t_info *data, t_wall *wall);
void	ft_dda(t_info *data, t_wall *wall);
void	ft_wall_size_x(t_info *data, t_wall *wall);

//wall_casting_prt2.c
void	ft_choose_pixel(t_info *data, t_wall *wall);
void	ft_pixels_screen_buf(t_info *data, t_wall *wall);

//key_action_move.c
void	move_forward(t_info *data);
void	move_backward(t_info *data);
void	move_left(t_info *data);
void	move_right(t_info *data);

//key_action_rotate.c
void	rotate_right(t_info *data);
void	rotate_left(t_info *data);

//utils.c
void	ft_error_exit(char *str);
void	free_ptr(char *ptr);
void	free_arr(char **arr);
void	print_map_data(t_info *data); //удалить
void	print_map_struct(t_map *map); //удалить
void	print_map_array(t_info *data); //удалить

#endif