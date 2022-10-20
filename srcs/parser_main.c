/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:13:48 by ateak             #+#    #+#             */
/*   Updated: 2022/10/20 17:32:51 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_map_into_array(t_info *data, int i)
{
	int	n;
	int	j;

	data->map->map_array = malloc(sizeof(char *) * data->map->map_height);
	if (data->map->map_array == NULL)
		ft_error_exit("Malloc for map_array failed");
	data->map->map_array[data->map->map_height] = NULL;
	j = 0;
	while (j < data->map->map_height)
	{
		data->map->map_array[j] = malloc(sizeof(char) * data->map->map_width);
		if (data->map->map_array[j] == NULL)
			ft_error_exit("Malloc for map_array failed");
		ft_memset(data->map->map_array[j], ' ', data->map->map_width);//заполняем пробелами чтобы выровнить строки и карта была прямоугольной
		j++;
	}
	j = 0;
	while (j < data->map->map_height)
	{
		n = -1;
		while (data->map->data[i][++n])
			data->map->map_array[j][n] = data->map->data[i][n];
		data->map->map_array[j][n] = '\0';
		j++;
		i++;
	}
}

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
	check_player_find_map_size(data, i); //проверка валидности карты, сохранение позиции игрока, камеры и размера карты
	save_map_into_array(data, i);//выравниваем карту до прямогуольной и сохраняем в массив data->map->map_array
	check_map_height_border(data);
	check_map_width_border(data);
	check_border_map_in_height(data);
	check_border_map_in_width(data);
	free_arr(data->map->map_array);
}
