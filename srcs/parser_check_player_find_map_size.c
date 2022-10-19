/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_player_find_map_size.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:32 by ateak             #+#    #+#             */
/*   Updated: 2022/10/18 16:39:20 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_map_size(t_info *data, char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (len > data->map->map_width)
		data->map->map_width = len;
	if (ft_strcmp(line, "") != 0)
		data->map->map_height++;
	else
		ft_error_exit("There is an empty row in the map!");
}

static void	init_player_position(t_info *data, char direction, int i, int j)
{
	data->player_y = (double)j + 0.5;
	data->player_x = (double)i + 0.5;
	if (direction == 'E')
	{
		data->cam_pln_x = FIELD_OF_VIEW;
		data->cam_pln_y = 0;
		data->pl_dir_x = 0;
		data->pl_dir_y = 1;
	}
	else if (direction == 'S')
	{
		data->cam_pln_x = 0;
		data->cam_pln_y = -FIELD_OF_VIEW;
		data->pl_dir_x = 1;
		data->pl_dir_y = 0;
	}
	else if (direction == 'W')
	{
		data->cam_pln_x = -FIELD_OF_VIEW;
		data->cam_pln_y = 0;
		data->pl_dir_x = 0;
		data->pl_dir_y = -1;
	}
}

static void	check_map_symbols(char c, int *players)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S'
			&& c != 'W' && c != 'E' && c != ' ')
		ft_error_exit("Invalid symbol in the map!");
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && *players < 1)
		(*players)++;
	else if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && *players == 1)
		ft_error_exit("More then one player in the map!");
}

void	check_player_find_map_size(t_info *data, int i)
{
	char	**map;
	int		map_start;
	int		j;

	map = data->map->data;
	map_start = i;
	j = 0;
	data->players = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			check_map_symbols(map[i][j], &data->players);
			if (map[i][j] == 'N' || map[i][j] == 'S' \
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				init_player_position(data, map[i][j], i - map_start, j);
				map[i][j] = '0';
			}
			j++;
		}
		find_map_size(data, map[i]);
		i++;
	}
	if (data->players == 0)
		ft_error_exit("There is no player in the map!");
}
