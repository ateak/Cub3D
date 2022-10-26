/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:13:48 by ateak             #+#    #+#             */
/*   Updated: 2022/10/26 19:52:16 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_map_into_array(char **map, t_info *data, int i)
{
	int	n;
	int	j;

	data->map.map_array = malloc(sizeof(char *) * data->map.map_height + 1);
	if (data->map.map_array == NULL)
		ft_error_exit("Malloc for map_array failed");
	j = 0;
	while (j < data->map.map_height)
	{
		data->map.map_array[j] = malloc(sizeof(char) * data->map.map_width + 1);
		if (data->map.map_array[j] == NULL)
			ft_error_exit("Malloc for map_array failed");
		ft_memset(data->map.map_array[j], ' ', data->map.map_width + 1);//заполняем пробелами чтобы выровнить строки и карта была прямоугольной
		j++;
	}
	j = 0;
	while (j < data->map.map_height)
	{
		n = -1;
		while (map[i][++n])
			data->map.map_array[j][n] = map[i][n];
		j++;
		i++;
	}
}

static int	find_map_height(int fd)
{
	int		map_height;
	int		gnl_res;
	char	*str;

	map_height = 0;
	str = NULL;
	gnl_res = 1;
	while (gnl_res != 0)
	{
		gnl_res = get_next_line(fd, &str);
		free(str);
		map_height++;
	}
	close(fd);
	return (map_height);
}

void	get_map_data(char ***map, char **argv, int fd)
{
	int		map_height;
	char	**tmp;
	int		gnl_res;
	int		i;

	gnl_res = 1;
	tmp = NULL;
	map_height = find_map_height(fd);//считает кол-во строк в файле карты создаем массив указателей на строки карты
	tmp = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (tmp == NULL)
		ft_error_exit("Malloc error");
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error_exit("Can't open the file");
	i = 0;
	while (gnl_res != 0)
	{
		gnl_res = get_next_line(fd, &tmp[i]);
		i++;
	}
	tmp[i] = NULL;
	*map = tmp;
	close(fd);
}

void	 parser(t_info *data, char **argv, int fd)
{
	char	**map;
	int		i;

	map = NULL;
	i = 0;
	get_map_data(&map, argv, fd); //сохраняем всю информацию из карты в двумерный массив
	i = parse_map_data(&map, data, i); //проверяем и распределяем информацию из двумерного массива в структуры и возвращаем номер строки, где начинается сама карта
	check_player_find_map_size(map, data, i); //проверка валидности карты, сохранение позиции игрока, камеры и размера карты
	save_map_into_array(map, data, i);//выравниваем карту до прямогуольной и сохраняем в массив data->map->map_array
	check_map_height_border(data->map.map_array, data);
	check_map_width_border(data->map.map_array, data);
	check_border_map_in_height(data->map.map_array, data);
	check_border_map_in_width(data->map.map_array, data);
	free_arr(map);
}
