/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:31:23 by ateak             #+#    #+#             */
/*   Updated: 2022/10/15 19:44:05 by ateak            ###   ########.fr       */
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
# include "../minilibx/mlx.h"

typedef struct s_map
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	int		row_len; //line_len
	int		rows; //lines
	int		count_prm;
	char	*ceiling;
	char	*floor;
	int		ceiling_clr;
	int		floor_clr;
	char	**map_array;
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
	t_map		map;

}				t_info;


void	first_check_map(int argc, char **argv);
void	check_map_extension(char **argv);
void	ft_error_exit(char *str);



#endif