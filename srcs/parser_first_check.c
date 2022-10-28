/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_first_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:04:40 by ateak             #+#    #+#             */
/*   Updated: 2022/10/28 12:20:35 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_map_extension(char **argv)
{
	char			*map_format;
	int				len;
	unsigned int	start;

	len = 4;
	start = ft_strlen(argv[1]) - 4;
	map_format = ft_substr(argv[1], start, len);
	if (ft_strncmp(map_format, ".cub", len))
	{
		free(map_format);
		ft_error_exit("Wrong map extension!");
	}
	free(map_format);
}

int	first_check(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_error_exit("Wrong number of arguments!");
	check_map_extension(argv);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error_exit("Can't open the file");
	return (fd);
}
