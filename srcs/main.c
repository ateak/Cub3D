/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/10/20 17:23:36 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		
	return (0);
}
