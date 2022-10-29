/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realize_doors_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 20:29:39 by ateak             #+#    #+#             */
/*   Updated: 2022/10/28 20:33:08 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	close_door(t_info *data, int x, int y)
{
	int	x1;
	int	y1;

	x1 = x;
	y1 = y;
	data->map.map_array[x1][y1] = '2';
}

static void	open_door(t_info *data, int x, int y)
{
	int	x1;
	int	y1;

	x1 = x;
	y1 = y;
	data->map.map_array[x1][y1] = '3';
}

void	realize_doors(t_info *data)
{
	int	x;
	int	y;

	x = (int)data->player_x;
	y = (int)data->player_y;
	if (data->map.map_array[x][y - 1] == '2' && data->ctrl.key_open)
		open_door(data, x, y - 1);
	else if (data->map.map_array[x][y + 1] == '2' && data->ctrl.key_open)
		open_door(data, x, y + 1);
	else if (data->map.map_array[x + 1][y] == '2' && data->ctrl.key_open)
		open_door(data, x + 1, y);
	else if (data->map.map_array[x - 1][y] == '2' && data->ctrl.key_open)
		open_door(data, x - 1, y);
	else if (data->map.map_array[x][y - 1] == '3' && data->ctrl.key_open)
		close_door(data, x, y - 1);
	else if (data->map.map_array[x][y + 1] == '3' && data->ctrl.key_open)
		close_door(data, x, y + 1);
	else if (data->map.map_array[x + 1][y] == '3' && data->ctrl.key_open)
		close_door(data, x + 1, y);
	else if (data->map.map_array[x - 1][y] == '3' && data->ctrl.key_open)
		close_door(data, x - 1, y);
	data->ctrl.key_open = 0;
}
