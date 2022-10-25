/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/10/25 18:48:56 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_window(t_info *data)
{
	if (data->mlx != 0)
	{
		mlx_clear_window(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
	}
	exit (EXIT_SUCCESS);
}

int	key_release(int key, t_info *data)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
		data->ctrl.key_up = 0;
	else if (key == LEFT)
		data->ctrl.key_left = 0;
	else if (key == DOWN)
		data->ctrl.key_down = 0;
	else if (key == RIGHT)
		data->ctrl.key_right = 0;
	else if (key ==ARROW_RIGHT)
		data->ctrl.key_arr_right = 0;
	else if (key == ARROW_LEFT)
		data->ctrl.key_arr_left = 0;
	return (0);
}

int	key_press(int key, t_info *data)
{
	if (key == ESC)
		exit(0);
	else if (key == UP)
		data->ctrl.key_up = 1;
	else if (key == LEFT)
		data->ctrl.key_left = 1;
	else if (key == DOWN)
		data->ctrl.key_down = 1;
	else if (key == RIGHT)
		data->ctrl.key_right = 1;
	else if (key ==ARROW_RIGHT)
		data->ctrl.key_arr_right = 1;
	else if (key == ARROW_LEFT)
		data->ctrl.key_arr_left = 1;
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
	mlx_loop_hook(data->mlx, &game_loop, data);
	mlx_hook(data->win, PRESS, 0, &key_press, data);
	mlx_hook(data->win, RELEASE, 0, &key_release, data);
	mlx_hook(data->win, REDCROSS, 0, close_window, data);
	mlx_loop(data->mlx);

	
	return (0);
}
