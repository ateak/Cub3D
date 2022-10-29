/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:07:36 by ateak             #+#    #+#             */
/*   Updated: 2022/10/29 13:42:40 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (data->ctrl.key_arr_up)
		ft_fov_plus(data);
	if (data->ctrl.key_arr_down)
		ft_fov_minus(data);
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
	make_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
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
			data->buf_img[y][x] = data->map.floor_clr;
			data->buf_img[WIN_H - y - 1][x] = data->map.ceiling_clr;
			x++;
		}
		y++;
	}
}

int	game_loop(t_info *data)
{
	fill_floor_and_ceiling(data); //заполняем буфер для экрана цветом потолка наполовину и пола на половину
	realize_doors(data); //если рядом с дверью и нажали кнопку, отк/закр дверь
	wall_casting(data);
	rendering(data);
	key_action(data);
	return (0);
}
