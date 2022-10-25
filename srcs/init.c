/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:02:07 by ateak             #+#    #+#             */
/*   Updated: 2022/10/25 18:46:49 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_info *data)
{
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		ft_error_exit("Malloc for map failed");
	data->map->north_texture = NULL;
	data->map->south_texture = NULL;
	data->map->east_texture = NULL;
	data->map->west_texture = NULL;
	data->map->map_width = 0;
	data->map->map_height = 0;
	data->map->map_components = 0;
	data->map->ceiling = NULL;
	data->map->floor = NULL;
	data->map->ceiling_clr = 0;
	data->map->floor_clr = 0;
	data->map->map_array = NULL;
	data->map->data = NULL;
}

void	ft_init_data(t_info *data)
{
	data->pl_dir_x = -1.0;
	data->pl_dir_y = 0.0;
	data->cam_pln_x = 0.0;
	data->cam_pln_y = FIELD_OF_VIEW;
	data->ctrl.key_esc = 0;
	data->ctrl.key_up = 0;
	data->ctrl.key_down = 0;
	data->ctrl.key_left = 0;
	data->ctrl.key_right = 0;
	data->speed_rotate = 0.04;
	data->speed_move = 0.04;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error_exit("Mlx_init failed");
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, WIN_NAME);
	data->img.img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	if (data->win == NULL || data->img.img == NULL)
		ft_error_exit("Mlx_new_window_or_new_image_creating failed");
	data->img.data = (int *)mlx_get_data_addr(data->img.img, &data->img.bpp, \
					&data->img.len, &data->img.endian);
	ft_init_map(data);
}
