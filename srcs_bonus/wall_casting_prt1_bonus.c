/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_prt1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:47:39 by ateak             #+#    #+#             */
/*   Updated: 2022/10/28 20:38:44 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_wall_size_x(t_info *data, t_wall *wall)
{
	if (wall->side == 0)
		wall->perp_wall_dist = (wall->map_x - data->player_x + \
								(1 - wall->step_x) / 2) / wall->ray_dir_x;
	else
		wall->perp_wall_dist = (wall->map_y - data->player_y + \
								(1 - wall->step_y) / 2) / wall->ray_dir_y;
	wall->line_height = (int)(WIN_H / wall->perp_wall_dist);
	wall->rend_start = -wall->line_height / 2 + WIN_H / 2;
	if (wall->rend_start < 0)
		wall->rend_start = 0;
	wall->rend_end = wall->line_height / 2 + WIN_H / 2;
	if (wall->rend_end >= WIN_H)
		wall->rend_end = WIN_H - 1;
}

void	ft_dda(t_info *data, t_wall *wall)
{
	wall->hit = 0;
	while (wall->hit == 0)
	{
		if (wall->side_dist_x < wall->side_dist_y)
		{
			wall->side_dist_x = wall->side_dist_x + wall->delta_dist_x;
			wall->map_x = wall->map_x + wall->step_x;
			wall->side = 0;
		}
		else
		{
			wall->side_dist_y = wall->side_dist_y + wall->delta_dist_y;
			wall->map_y = wall->map_y + wall->step_y;
			wall->side = 1;
		}
		if (data->map.map_array[wall->map_x][wall->map_y] == '1')
			wall->hit = 1;
		if (data->map.map_array[wall->map_x][wall->map_y] == '2')
			wall->hit = 2;
	}
}

void	ft_get_step_side_dist(t_info *data, t_wall *wall)
{
	if (wall->ray_dir_x < 0)
	{
		wall->step_x = -1;
		wall->side_dist_x = (data->player_x - wall->map_x) * wall->delta_dist_x;
	}
	else
	{
		wall->step_x = 1;
		wall->side_dist_x = (wall->map_x + 1.0 - data->player_x)
			* wall->delta_dist_x;
	}
	if (wall->ray_dir_y < 0)
	{
		wall->step_y = -1;
		wall->side_dist_y = (data->player_y - wall->map_y) * wall->delta_dist_y;
	}
	else
	{
		wall->step_y = 1;
		wall->side_dist_y = (wall->map_y + 1.0 - data->player_y)
			* wall->delta_dist_y;
	}
}

void	ft_get_position(t_info *data, t_wall *wall)
{
	wall->camera_x = 2 * wall->x / (double)WIN_W - 1; //?????????????????? ???? 0..640 ?? -1..1
	wall->ray_dir_x = data->pl_dir_x + data->cam_pln_x * wall->camera_x; //(-1 + 0*(-1..1))
	wall->ray_dir_y = data->pl_dir_y + data->cam_pln_y * wall->camera_x; //0+0.66*(-1..1)
	wall->map_x = (int)data->player_x; 
	wall->map_y = (int)data->player_y;
	wall->delta_dist_x = fabs(1 / wall->ray_dir_x); //fabs  abs for float
	wall->delta_dist_y = fabs(1 / wall->ray_dir_y);
}

void	wall_casting(t_info *data)
{
	t_wall	wall;

	wall.x = 0;
	while (wall.x < WIN_W)
	{
		ft_get_position(data, &wall);
		ft_get_step_side_dist(data, &wall);
		ft_dda(data, &wall); //Digital Differential Analysis
		ft_wall_size_x(data, &wall);
		ft_choose_pixel(data, &wall);
		ft_pixels_screen_buf(data, &wall);
		wall.x++;
	}
}
