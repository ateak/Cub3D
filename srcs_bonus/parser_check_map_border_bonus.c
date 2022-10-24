/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_map_border_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 15:46:54 by ateak             #+#    #+#             */
/*   Updated: 2022/10/24 14:20:10 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"


void	map_error_exit(char error, char symbol, int i, int j)
{
	char	*error_msg;

	if (error == 'v')
		error_msg = "vertical contour is unclosed";
	else
		error_msg = "horizontal contour is unclosed";
	printf("Error: %s '%c' h - %d, w - %d\n", error_msg, symbol, i, j);
	exit (EXIT_FAILURE);
}

void	check_border_map_in_width(t_info *data)
{
	char **map;
	int	j;
	int	i;

	map = data->map->map_array;
	i = 0;
		while (i < data->map->map_width)
	{
		j = 0;
		while (j < data->map->map_height - 1)
		{
			while (j < data->map->map_height - 1 && map[j][i] != ' ')
				j++;
			if (j > 0 && j < data->map->map_height - 1 && map[j - 1][i] != '1')
				map_error_exit('v', map[j][i], j, i);
			while (j < data->map->map_height - 1 && map[j][i] == ' ')
				j++;
			if (j < data->map->map_height - 1 && map[j][i] != '1')
				map_error_exit('v', map[j][i], j, i);
		}
		i++;
	}
}

void	check_border_map_in_height(t_info *data)
{
	char **map;
	int	j;
	int	i;

	map = data->map->map_array;
	i = 0;
	while (i < data->map->map_height)
	{
		j = 0;
		while (j < data->map->map_width - 1)
		{
			while (j < data->map->map_width - 1 && map[i][j] != ' ')
				j++;
			if (j > 0 && j < data->map->map_width - 1 && map[i][j - 1] != '1')
				map_error_exit('h', map[i][j], i, j);
			while (j < data->map->map_width - 1 && map[i][j] == ' ')
				j++;
			if (j < data->map->map_width - 1 && map[i][j] != '1')
				map_error_exit('h', map[i][j], i, j);
		}
		i++;
	}
}

void	check_map_width_border(t_info *data)
{
	char **map;
	int	j;
	int	i;

	map = data->map->map_array;
	i = 0;
	while (i < data->map->map_width)
	{
		j = 0;
		while (map[j][i] == ' ' && j < data->map->map_height - 1)
			j++;
		if (map[j][i] != '1' && j < data->map->map_height - 1)
			map_error_exit('v', map[j][i], j, i);
		j = data->map->map_height - 1;
		while (map[j][i] == ' ' && j > 0)
			j--;
		if (map[j][i] != '1' && j > 0)
			map_error_exit('v', map[j][i], j, i);
		i++;
	}
}

void	check_map_height_border(t_info *data)
{
	char **map;
	int	j;
	int	i;

	map = data->map->map_array;
	i = 0;
	while (i < data->map->map_height)
	{
		j = 0;
		while (map[i][j] == ' ' && j < data->map->map_width - 1)
			j++;
		if (map[i][j] != '1' && j < data->map->map_width - 1)
			map_error_exit('h', map[i][j], i, j);
		j = data->map->map_width - 1;
		while (map[i][j] == ' ' && j > 0)
			j--;
		if (map[i][j] != '1' && j > 0)
			map_error_exit('h', map[i][j], i, j);
		i++;
	}
}
