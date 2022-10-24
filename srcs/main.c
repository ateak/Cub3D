/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/10/24 17:16:40 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_window(t_info *data)
{
	if (data->mlx != 0)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	exit (EXIT_SUCCESS);
}


void	ft_player_forward(t_info *data)
{
	int nxt_x;
	int nxt_y;

	nxt_x = (int)(data->player_x + data->pl_dir_x * data->speed_move);
	nxt_y = (int)(data->player_y);
	if (data->map->map_array[nxt_x][nxt_y] == '0')
		data->player_x = data->player_x + data->pl_dir_x * data->speed_move;
	nxt_x = (int)(data->player_x);
	nxt_y = (int)(data->player_y + data->pl_dir_y * data->speed_move);
	if (data->map->map_array[nxt_x][nxt_y] == '0')
		data->player_y = data->player_y + data->pl_dir_y * data->speed_move;
}

void	ft_key_action(t_info *data)
{
	if (data->ctrl.key_up)
		ft_player_forward(data);
	if (data->ctrl.key_down)
		ft_player_backward(data);
	if (data->ctrl.key_left)
		ft_player_left(data);
	if (data->ctrl.key_right)
		ft_player_right(data);
	if (data->ctrl.key_arr_right)
		ft_player_rotate_r(data);
	if (data->ctrl.key_arr_left)
		ft_player_rotate_l(data);
	if (data->ctrl.key_esc)
		exit(0);
}


void	ft_render(t_info *data)
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

int	ft_game_loop(t_info *data)
{
	fill_floor_and_ceiling(data);//заполняем буфер для экрана цветом потолка и пола по половине
	wall_casting(data);
	ft_render(data);
	ft_key_action(data);
	return (0);
}


int	main(int argc, char **argv)
{
	t_info	*data;
	int		fd;

	fd = first_check(argc, argv); //проверка кол-ва аргументов, fd, расширения файла
	data = malloc(sizeof(t_info));
	if (data == NULL)
		ft_error_exit("Malloc for data failed");
	ft_init_data(data);
	parser(data, fd);
	//print_map_data(data); //удалить
	//print_map_struct(data->map); //удалить
	//print_map_array(data);  //удалить
	malloc_for_textures(data);//маллок памяти для 5ти текстур размером 64х64 стены и дверь
	import_textures(data);
	mlx_loop_hook(data->mlx, &ft_game_loop, data);
	mlx_hook(glb->win, PRESS, 0, &ft_key_press, glb);
	mlx_hook(glb->win, RELEASE, 0, &ft_key_release, glb);
	mlx_hook(glb->win, REDCROSS, 0, ft_close_window, glb);
	mlx_loop(glb->mlx);

	
	return (0);
}
