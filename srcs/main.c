/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/10/16 20:51:17 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	ft_find_param_name(char *str)
{
	if (ft_strcmp(str, "NO") == 0 || ft_strcmp(str, "SO") == 0
		|| ft_strcmp(str, "WE") == 0 || ft_strcmp(str, "EA") == 0
		|| ft_strcmp(str, "C") == 0 || ft_strcmp(str, "F") == 0)
		return (1);
	return (0);
}

void	ft_params_save(t_glb *glb, char **splitted_line)
{
	if (ft_strcmp(splitted_line[0], "NO") == 0)
		ft_texture_save(splitted_line, &glb->map.north_texture, glb);
	else if (ft_strcmp(splitted_line[0], "SO") == 0)
		ft_texture_save(splitted_line, &glb->map.south_texture, glb);
	else if (ft_strcmp(splitted_line[0], "WE") == 0)
		ft_texture_save(splitted_line, &glb->map.west_texture, glb);
	else if (ft_strcmp(splitted_line[0], "EA") == 0)
		ft_texture_save(splitted_line, &glb->map.east_texture, glb);
	else if (ft_strcmp(splitted_line[0], "C") == 0)
		ft_color_save(splitted_line, &glb->map.ceiling, glb);
	else if (ft_strcmp(splitted_line[0], "F") == 0)
		ft_color_save(splitted_line, &glb->map.floor, glb);
}

int	ft_emptyline(char **tmp_map, int *i, char **splitted_line)
{
	if (splitted_line[0] == NULL)
	{
		free_arr(splitted_line);
		(*i)++;
		return (1);
	}
	if (tmp_map[*i][0] == '\n')
	{
		free_arr(splitted_line);
		(*i)++;
		return (1);
	}
	return (0);
}

int	ft_pars_params(t_info *data, int i)
{
	char	**tmp_map;
	char	**splitted_line;

	splitted_line = NULL;
	tmp_map = data->map->data;
	while (tmp_map[i] != NULL)
	{
		splitted_line = ft_split(tmp_map[i], ' ');
		if (ft_emptyline(tmp_map, &i, splitted_line)) //освобождает пустые строки
			continue ;
		if (ft_find_param_name(splitted_line[0])) //есть ли в начале строки NO и тд
			ft_params_save(data, splitted_line);//сохраняем пути текстур стен и цвет потолка и пола и заодно проверка валидности
		else if (ft_emptyline(tmp_map, &i, splitted_line))
			continue ;
		else
		{
			if (data->map->map_components != 6)
				ft_error_exit("There are not all parameters in the map!");
			break ;
		}
		i++;
		free_arr(splitted_line);
	}
	//free_arr(splitted_line);
	return (i);
}

void	read_map(t_map *map, int fd)
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

/*void	ft_parser_map_info(char **argv, t_info *data)
{
	char	**map;
	int		i;

	map = NULL;
	i = 0;
	void	read_map(t_game *map, int fd)
}*/


int	main(int argc, char **argv)
{
	t_info	*data;
	int		fd;

	fd = first_check(argc, argv); //проверка кол-ва аргументов, fd, расширения файла
	data = malloc(sizeof(t_info));
	if (data == NULL)
		ft_error_exit("Malloc for data failed");
	ft_init_data(data);
	read_map(data->map, fd); //сохраняем всю информацию из карты в двумерный массив
	print_arr(data);


	return (0);
}
