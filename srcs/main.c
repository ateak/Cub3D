/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/10/17 21:14:24 by ateak            ###   ########.fr       */
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
	print_arr(data); //удалить
	print_map_struct(data->map); //удалить
		
	return (0);
}
