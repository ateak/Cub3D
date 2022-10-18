/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:13:48 by ateak             #+#    #+#             */
/*   Updated: 2022/10/18 16:05:19 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_map_data(t_map *map, int fd)
{
	char	*map_string;
	char	*tmp;
	char	*tmp2;

	map_string = NULL;
	tmp = NULL;
	tmp = get_next_line(fd);
	if (tmp == NULL)
		ft_error_exit("The map is empty!");
	while (tmp)
	{
		tmp2 = map_string;
		map_string = ft_strjoin(tmp2, tmp);
		free_ptr(tmp2);
		free_ptr(tmp);
		tmp = get_next_line(fd);
	}
	map->data = ft_split(map_string, '\n');
	free(map_string);
	close(fd);
}

void	parser(t_info *data, int fd)
{
	int		i;

	i = 0;
	get_map_data(data->map, fd); //сохраняем всю информацию из карты в двумерный массив
	i = parse_map_data(data, i); //проверяем и распределяем информацию из двумерного массива в структуры и возвращаем номер строки, где начинается сама карта
	check_map_lines(data, i); //проверка валидности карты, сохранение позиции игрока, камеры и размера карты
	
	printf("%d\n", i);
}
