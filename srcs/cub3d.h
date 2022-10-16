/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:31:23 by ateak             #+#    #+#             */
/*   Updated: 2022/10/16 20:37:56 by ateak            ###   ########.fr       */
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
# define FOV 0.66

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		row_len; //line_len
	int		rows; //lines
	int		map_components; //количество параметров в карте
	char	*ceiling;
	char	*floor;
	int		ceiling_clr;
	int		floor_clr;
	char	**map_array;
	char	**data;
}			t_map;

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

}				t_info;


int		first_check(int argc, char **argv);
void	check_map_extension(char **argv);
void	ft_error_exit(char *str);
void	ft_init_data(t_info *data);
void	ft_init_map(t_info *data);
void	read_map(t_map *map, int fd);
void	print_arr(t_info *data); //удалить
void	free_ptr(char *ptr);
void	free_arr(char **arr);


#endif