/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realize_mouse_rotate_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:06:14 by ateak             #+#    #+#             */
/*   Updated: 2022/10/29 14:27:22 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	mouse_rotate_right(t_info *data, int diff, int x, int y)
{
	data->ctrl.mouse_rotate = x;
	while (diff-- != 0)
		rotate_right(data);
	if (x > (int)(WIN_W * 0.7))
	{
		mlx_mouse_move(data->win, (int)(WIN_W / 2), y);
		data->ctrl.mouse_rotate = (int)(WIN_W / 2);
	}
}

static void	mouse_rotate_left(t_info *data, int diff, int x, int y)
{
	data->ctrl.mouse_rotate = x;
	while (diff-- != 0)
		rotate_left(data);
	if (x < (int)(WIN_W * 0.3))
	{
		mlx_mouse_move(data->win, (int)(WIN_W / 2), y);
		data->ctrl.mouse_rotate = (int)(WIN_W / 2);
	}
}

int	mouse_rotate(int x, int y, t_info *data)
{
	int	diff;

	if (data->ctrl.key_mouse == 1)
	{
		mlx_mouse_hide();
		diff = abs(data->ctrl.mouse_rotate - x) / 2;
		if (diff > 3)
			diff = 3;
		if (y < (int)(WIN_H * 0.3) || y > (int)(WIN_H * 0.7))
			mlx_mouse_move(data->win, x, (int)(WIN_H / 2));
		if (x > data->ctrl.mouse_rotate)
			mouse_rotate_right(data, diff, x, y);
		else if (x < data->ctrl.mouse_rotate)
			mouse_rotate_left(data, diff, x, y);
	}
	else
		mlx_mouse_show();
	return (0);
}
