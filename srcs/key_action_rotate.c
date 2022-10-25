/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:06:09 by ateak             #+#    #+#             */
/*   Updated: 2022/10/25 18:06:29 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
