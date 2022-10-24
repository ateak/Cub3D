/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:31:23 by ateak             #+#    #+#             */
/*   Updated: 2022/10/24 09:15:36 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define WIN_NAME "cub3D_bonus"
# define TEXTURE_W 64
# define TEXTURE_H 64
# define FIELD_OF_VIEW 0.66

# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define OPEN 49
# define ESC 53
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_UP 126
# define ARROW_DOWN 125
# define MOUSE_SHOW 46

# define REDCROSS 17
# define PRESS 2
# define RELEASE 3
# define MOUSE 6

# define LIGHTGREY 0xC8C8C8
# define BLUE 0xC8
# define LIGHTBLUE 0x64C8FA
# define RED 0xFF0000


typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		map_width; 	//row_len
	int		map_height;  //rows
	int		map_components; //count_prm, количество параметров в карте
	char	*ceiling;
	char	*floor;
	int		ceiling_clr;
	int		floor_clr;
	char	**map_array;
	char	**data;
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

typedef struct s_minimap
{
	int	x;
	int	y;
	int	x2;
	int	y2;
}		t_minimap;

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
	int		key_arr_up;
	int		key_arr_down;
	int		key_mouse;
	int		mouse_rotate;
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
	int			**texturs;
	int			buf_img[WIN_H][WIN_W];
	t_map		*map;
	t_img		img;
	t_controls	ctrl;

}				t_info;


//PARSER

//first_check.c
int		first_check(int argc, char **argv);
void	check_map_extension(char **argv);

//parser_main.c
void	parser(t_info *data, int fd);
void	get_map_data(t_map *map, int fd);

//parser_get_colour_texture_info.c
int		parse_map_data(t_info *data, int i);
int		colour_texture_info(char *str);
void	get_colour_texture_info(t_info *data, char **splitted_line);

//parser_save_texture.c
void	save_texture(char **splitted_line, char **texture_path, t_info *data);

//parser_save_colour.c
void	save_colour(char **splitted_line, char **colour, t_info *data);

//parser_check_player_find_map_size.c
void	check_player_find_map_size(t_info *data, int i);

//parser_check_map_border.c
void	check_map_height_border(t_info *data);
void	check_map_width_border(t_info *data);
void	check_border_map_in_height(t_info *data);
void	check_border_map_in_width(t_info *data);
void	map_error_exit(char error, char symbol, int i, int j);


//init.c
void	ft_init_data(t_info *data);
void	ft_init_map(t_info *data);

//main.c
void	save_map_into_array(t_info *data, int i);

//utils.c
void	ft_error_exit(char *str);
void	free_ptr(char *ptr);
void	free_arr(char **arr);
void	print_map_data(t_info *data); //удалить
void	print_map_struct(t_map *map); //удалить
void	print_map_array(t_info *data); //удалить



#endif