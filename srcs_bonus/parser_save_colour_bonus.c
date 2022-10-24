/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_colour_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:03:24 by ateak             #+#    #+#             */
/*   Updated: 2022/10/24 14:20:34 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	ft_str_is_num(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_rgb_to_int(int r, int g, int b)
{
	int	colour;

	colour = r;
	colour = (colour << 8) | g;
	colour = (colour << 8) | b;
	return (colour);
}

static int	check_colour(char **colour)
{
	int	rgb[3];
	int	i;
	int	colour_int;

	i = 0;
	while (i < 3)
	{
		if (ft_str_is_num(colour[i]) && ft_atoi(colour[i]) <= 255)
			rgb[i] = ft_atoi(colour[i]);
		else
			ft_error_exit("Colour number not correct");
		i++;
	}
	colour_int = ft_rgb_to_int(rgb[0], rgb[1], rgb[2]);
	return (colour_int);
}

void	save_colour(char **splitted_line, char **colour, t_info *data)
{
	char	**splitted_colour;

	if (splitted_line[2])
		ft_error_exit("Wrong map information!");
	if (*colour)
		ft_error_exit("Colour information is duplicated!");
	*colour = splitted_line[1];
	splitted_colour = ft_split(*colour, ',');
	if (splitted_colour[3])
		ft_error_exit("Wrong map information!");
	if (!ft_strcmp(splitted_line[0], "C"))
		data->map->ceiling_clr = check_colour(splitted_colour);
	if (!ft_strcmp(splitted_line[0], "F"))
		data->map->floor_clr = check_colour(splitted_colour);
	free_arr(splitted_colour);
	data->map->map_components++;
}