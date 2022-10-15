/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:19:38 by ateak             #+#    #+#             */
/*   Updated: 2022/10/15 19:44:29 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_error_exit(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

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

void	first_check_map(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_error_exit("Wrong number of arguments!");
	check_map_extension(argv);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		ft_error_exit("Can't open the file");
	close(fd);
}

int	main(int argc, char **argv)
{
	t_info	*data;

	first_check_map(argc, argv);
	data = malloc(sizeof(t_info));
	if (data == NULL)
		ft_error_exit("Malloc for data failed");

	return (0);
}
