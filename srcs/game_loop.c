/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:07:36 by ateak             #+#    #+#             */
/*   Updated: 2022/10/25 18:37:01 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_action(t_info *data)
{
	if (data->ctrl.key_up)
		move_forward(data);
	if (data->ctrl.key_down)
		move_backward(data);
	if (data->ctrl.key_left)
		move_left(data);
	if (data->ctrl.key_right)
		move_right(data);
	if (data->ctrl.key_arr_right)
		rotate_right(data);
	if (data->ctrl.key_arr_left)
		rotate_left(data);
	if (data->ctrl.key_esc)
		exit(0);
}

void	rendering(t_info *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			data->img.data[y * WIN_W + x] = data->buf_img[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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

void	fill_floor_and_ceiling(t_info *data)
{
	int	y;
	int	x;

	y = WIN_H / 2 + 1;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			data->buf_img[y][x] = data->map->floor_clr;
			data->buf_img[WIN_H - y - 1][x] = data->map->ceiling_clr;
			x++;
		}
		y++;
	}
}

int	game_loop(t_info *data)
{
	fill_floor_and_ceiling(data);//заполняем буфер для экрана цветом потолка и пола по половине
	wall_casting(data);
	rendering(data);
	key_action(data);
	return (0);
}