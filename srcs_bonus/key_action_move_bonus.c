/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action_move_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:05:07 by ateak             #+#    #+#             */
/*   Updated: 2022/10/29 14:00:16 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_right(t_info *data)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(data->player_x + data->cam_pln_x * data->speed_move);
	nxt_y = (int)(data->player_y + data->cam_pln_y * data->speed_move);
	if (data->map.map_array[nxt_x][nxt_y] == '0' || data->map.map_array[nxt_x][nxt_y] == '3')
	{
		data->player_x = data->player_x + data->cam_pln_x * data->speed_move;
		data->player_y = data->player_y + data->cam_pln_y * data->speed_move;
	}
}

void	move_left(t_info *data)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(data->player_x - data->cam_pln_x * data->speed_move);
	nxt_y = (int)(data->player_y - data->cam_pln_y * data->speed_move);
	if (data->map.map_array[nxt_x][nxt_y] == '0' || data->map.map_array[nxt_x][nxt_y] == '3')
	{
		data->player_x = data->player_x - data->cam_pln_x * data->speed_move;
		data->player_y = data->player_y - data->cam_pln_y * data->speed_move;
	}
}

void	move_backward(t_info *data)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(data->player_x - data->pl_dir_x * data->speed_move);
	nxt_y = (int)(data->player_y);
	if (data->map.map_array[nxt_x][nxt_y] == '0' || data->map.map_array[nxt_x][nxt_y] == '3')
		data->player_x = data->player_x - data->pl_dir_x * data->speed_move;
	nxt_x = (int)(data->player_x);
	nxt_y = (int)(data->player_y - data->pl_dir_y * data->speed_move);
	if (data->map.map_array[nxt_x][nxt_y] == '0' || data->map.map_array[nxt_x][nxt_y] == '3')
		data->player_y = data->player_y - data->pl_dir_y * data->speed_move;
}

void	move_forward(t_info *data)
{
	int	nxt_x;
	int	nxt_y;

	nxt_x = (int)(data->player_x + data->pl_dir_x * data->speed_move);
	nxt_y = (int)(data->player_y);
	if (data->map.map_array[nxt_x][nxt_y] == '0' || data->map.map_array[nxt_x][nxt_y] == '3')
		data->player_x = data->player_x + data->pl_dir_x * data->speed_move;
	nxt_x = (int)(data->player_x);
	nxt_y = (int)(data->player_y + data->pl_dir_y * data->speed_move);
	if (data->map.map_array[nxt_x][nxt_y] == '0' || data->map.map_array[nxt_x][nxt_y] == '3')
		data->player_y = data->player_y + data->pl_dir_y * data->speed_move;
}
