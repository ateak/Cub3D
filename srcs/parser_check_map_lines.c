/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map_lines.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:33:32 by ateak             #+#    #+#             */
/*   Updated: 2022/10/18 15:59:26 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	count_map_line_len(t_info *data, char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if (len > data->map->line_len)
		data->map->line_len = len;
	if (ft_strcmp(line, "") != 0)
		data->map->lines++;
	else
		ft_error_exit("There is an empty row in the map!");
}

static void	init_player_position(t_info *data, char direction, int i, int j)
{
	data->player_y = (double)j + 0.5;
	data->player_x = (double)i + 0.5;
	if (direction == 'E')
	{
		data->cam_pln_x = FOV;
		data->cam_pln_y = 0;
		data->pl_dir_x = 0;
		data->pl_dir_y = 1;
	}
	else if (direction == 'S')
	{
		data->cam_pln_x = 0;
		data->cam_pln_y = -FOV;
		data->pl_dir_x = 1;
		data->pl_dir_y = 0;
	}
	else if (direction == 'W')
	{
		data->cam_pln_x = -FOV;
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

void	check_map_lines(t_info *data, int i)
{
	char	**map_lines;
	int		map_start;
	int		j;

	map_lines = data->map->data;
	map_start = i;
	j = 0;
	data->players = 0;
	while (map_lines[i] != 0)
	{
		j = 0;
		while (map_lines[i][j] != 0)
		{
			check_map_symbols(map_lines[i][j], &data->players);
			if (map_lines[i][j] == 'N' || map_lines[i][j] == 'S' \
				|| map_lines[i][j] == 'W' || map_lines[i][j] == 'E')
			{
				init_player_position(data, map_lines[i][j], i - map_start, j);
				map_lines[i][j] = '0';
			}
			j++;
		}
		count_map_line_len(data, map_lines[i]);
		i++;
	}
	if (data->players == 0)
		ft_error_exit("There is no player in the map!");
}
