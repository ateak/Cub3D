/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_save_texture_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 21:12:32 by ateak             #+#    #+#             */
/*   Updated: 2022/10/24 14:20:37 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_texture_file(char *file_path)
{
	int	fd;
	
	fd = open(file_path, O_RDWR);
	if (fd < 0)
		ft_error_exit("Texture file not found");
	close(fd);
}

void	save_texture(char **splitted_line, char **texture_path, t_info *data)
{
	if (splitted_line[2])
		ft_error_exit("Wrong map information!");
	if (*texture_path)
		ft_error_exit("Texture information is duplicated!");
	check_texture_file(splitted_line[1]);
	*texture_path = ft_strdup(splitted_line[1]);
	data->map->map_components++;
}
