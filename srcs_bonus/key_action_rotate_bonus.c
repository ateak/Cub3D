/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:06:09 by ateak             #+#    #+#             */
/*   Updated: 2022/10/29 13:41:58 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	rotate_left(t_info *data)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->pl_dir_x;
	old_plane_x = data->cam_pln_x;
	data->pl_dir_x = data->pl_dir_x * cos(data->speed_rotate) - \
					data->pl_dir_y * sin(data->speed_rotate);
	data->pl_dir_y = old_dir_x * sin(data->speed_rotate) + \
					data->pl_dir_y * cos(data->speed_rotate);
	data->cam_pln_x = data->cam_pln_x * cos(data->speed_rotate) - \
					data->cam_pln_y * sin(data->speed_rotate);
	data->cam_pln_y = old_plane_x * sin(data->speed_rotate) + \
					data->cam_pln_y * cos(data->speed_rotate);
}

void	rotate_right(t_info *data)
{
	double	old_plane_x;
	double	old_dir_x;

	old_dir_x = data->pl_dir_x;
	old_plane_x = data->cam_pln_x;
	data->pl_dir_x = data->pl_dir_x * cos(-data->speed_rotate) - \
					data->pl_dir_y * sin(-data->speed_rotate);
	data->pl_dir_y = old_dir_x * sin(-data->speed_rotate) + \
					data->pl_dir_y * cos(-data->speed_rotate);
	data->cam_pln_x = data->cam_pln_x * cos(-data->speed_rotate) - \
					data->cam_pln_y * sin(-data->speed_rotate);
	data->cam_pln_y = old_plane_x * sin(-data->speed_rotate) + \
					data->cam_pln_y * cos(-data->speed_rotate);
}

void	ft_fov_minus(t_info *data)
{
	data->cam_pln_x *= 0.9;
	data->cam_pln_y *= 0.9;
	data->ctrl.key_arr_down = 0;
}

void	ft_fov_plus(t_info *data)
{
	data->cam_pln_x *= 1.1;
	data->cam_pln_y *= 1.1;
	data->ctrl.key_arr_up = 0;
}
