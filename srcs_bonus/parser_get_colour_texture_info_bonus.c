/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_get_colour_texture_info_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:08:14 by ateak             #+#    #+#             */
/*   Updated: 2022/10/24 14:20:17 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	get_colour_texture_info(t_info *data, char **splitted_line)
{
	if (!ft_strcmp(splitted_line[0], "NO"))
		save_texture(splitted_line, &data->map->north_texture, data);
	else if (!ft_strcmp(splitted_line[0], "SO"))
		save_texture(splitted_line, &data->map->south_texture, data);
	else if (!ft_strcmp(splitted_line[0], "WE"))
		save_texture(splitted_line, &data->map->west_texture, data);
	else if (!ft_strcmp(splitted_line[0], "EA"))
		save_texture(splitted_line, &data->map->east_texture, data);
	else if (!ft_strcmp(splitted_line[0], "C"))
		save_colour(splitted_line, &data->map->ceiling, data);
	else if (!ft_strcmp(splitted_line[0], "F"))
		save_colour(splitted_line, &data->map->floor, data);
}

int	colour_texture_info(char *str)
{
	if (!ft_strcmp(str, "NO") || !ft_strcmp(str, "SO")
		|| !ft_strcmp(str, "WE") || !ft_strcmp(str, "EA")
		|| !ft_strcmp(str, "C") || !ft_strcmp(str, "F"))
		return (1);
	return (0);
}

static int	ft_empty_line(char **tmp_map, int *i, char **splitted_line)
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

int	parse_map_data(t_info *data, int i)
{
	char	**tmp_map;
	char	**splitted_line;

	splitted_line = NULL;
	tmp_map = data->map->data;
	while (tmp_map[i] != NULL)
	{
		splitted_line = ft_split(tmp_map[i], ' ');
		if (ft_empty_line(tmp_map, &i, splitted_line)) //освобождаем память, если строка пустая, и увеличиваем i
			continue ;
		if (colour_texture_info(splitted_line[0])) //есть ли в начале строки информация о текстурах и цветах (NO, C и т.п.)
			get_colour_texture_info(data, splitted_line);//сохраняем пути текстур стен и цвет потолка и пола и заодно проверка валидности
		else if (ft_empty_line(tmp_map, &i, splitted_line))
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
	return (i);
}