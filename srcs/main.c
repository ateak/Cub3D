/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/10/25 18:07:15 by ateak            ###   ########.fr       */
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
	mlx_hook(glb->win, PRESS, 0, &ft_key_press, glb);
	mlx_hook(glb->win, RELEASE, 0, &ft_key_release, glb);
	mlx_hook(glb->win, REDCROSS, 0, ft_close_window, glb);
	mlx_loop(glb->mlx);

	
	return (0);
}
