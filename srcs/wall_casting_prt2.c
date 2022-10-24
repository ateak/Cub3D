/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_casting_prt2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:50:22 by ateak             #+#    #+#             */
/*   Updated: 2022/10/24 16:50:40 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pixels_screen_buf(t_info *data, t_wall *wall)
{
	while (wall->y < wall->rend_end)
	{
		wall->texture_y = (int)wall->texture_pos & (TEXTURE_H - 1);
		wall->texture_pos += wall->step;
		wall->color = data->textures[wall->texture_num][TEXTURE_H * wall->texture_y + wall->texture_x];
		if (wall->side == 1)
			wall->color = (wall->color >> 1) & 0x7F7F7F;
		data->buf_img[wall->y][wall->x] = wall->color;
		wall->y++;
	}
}

static void	ft_choose_texture(t_wall *wall)
{
	if (wall->hit == 2)
		wall->texture_num = 4;
	else if (wall->side == 1 && wall->ray_dir_y < 0)
		wall->texture_num = 0;
	else if (wall->side == 1 && wall->ray_dir_y >= 0)
		wall->texture_num = 1;
	else if (wall->side == 0 && wall->ray_dir_x < 0)
		wall->texture_num = 2;
	else if (wall->side == 0 && wall->ray_dir_x >= 0)
		wall->texture_num = 3;
}

void	ft_choose_pixel(t_info *data, t_wall *wall)
{
	ft_choose_texture(wall);
	if (wall->side == 0)
		wall->wall_x = data->player_y + wall->perp_wall_dist * wall->ray_dir_y;
	else
		wall->wall_x = data->player_x + wall->perp_wall_dist * wall->ray_dir_x;
	wall->wall_x = wall->wall_x - floor((wall->wall_x)); // floor округляет аргумент до наибольшего целого значения, но не большее чем сам аргумент
	wall->texture_x = (int)(wall->wall_x * (double)TEXTURE_W);
	if (wall->side == 0 && wall->ray_dir_x > 0)
		wall->texture_x = TEXTURE_W - wall->texture_x - 1;
	if (wall->side == 1 && wall->ray_dir_y < 0)
		wall->texture_x = TEXTURE_W - wall->texture_x - 1;
	wall->step = 1.0 * TEXTURE_H / wall->line_height;
	wall->texture_pos = (wall->rend_start - WIN_H / 2 + wall->line_height / 2) * wall->step;
	wall->y = wall->rend_start;
}
