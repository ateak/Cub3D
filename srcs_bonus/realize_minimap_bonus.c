/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realize_minimap_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:31:00 by ateak             #+#    #+#             */
/*   Updated: 2022/10/29 13:35:41 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_put_obj_minimap(t_info *data, int x, int y, int color)
{
	int	x_old;
	int	x1;
	int	y1;

	y1 = 0;
	x_old = x;
	while (y1 < MINIMAP)
	{
		x = x_old;
		x1 = 0;
		while (x1 < MINIMAP)
		{
			data->img.data[y * WIN_W + x] = color;
			x1++;
			x++;
		}
		y1++;
		y++;
	}
}

void	rendering_minimap(t_info *data, t_minimap *mimap)
{
	if (data->map.map_array[mimap->y][mimap->x] == '0')
		ft_put_obj_minimap(data, mimap->x2, mimap->y2, LIGHTGREY);
	if (data->map.map_array[mimap->y][mimap->x] == '1')
		ft_put_obj_minimap(data, mimap->x2, mimap->y2, BLUE);
	if (data->map.map_array[mimap->y][mimap->x] == '2'
		|| data->map.map_array[mimap->y][mimap->x] == '3')
		ft_put_obj_minimap(data, mimap->x2, mimap->y2, LIGHTBLUE);
	ft_put_obj_minimap(data, (int) data->player_y * MINIMAP, \
		(int) data->player_x * MINIMAP, RED);
}

void	make_minimap(t_info *data)
{
	t_minimap	mimap;

	mimap.y = 0;
	mimap.y2 = 0;
	while (mimap.y < data->map.map_height)
	{
		mimap.x = 0;
		mimap.x2 = 0;
		while (mimap.x <  data->map.map_width)
		{
			rendering_minimap(data, &mimap);
			mimap.x2 = mimap.x2 + MINIMAP;
			mimap.x++;
		}
		mimap.y2 = mimap.y2 + MINIMAP;
		mimap.y++;
	}
}
