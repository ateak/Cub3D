/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:03:15 by ateak             #+#    #+#             */
/*   Updated: 2022/10/16 20:41:44 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_exit(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	free_ptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i])
		{
			free(arr[i]);
			arr[i] = NULL; 
		}
		i++;
	}
	free(arr);
	arr = NULL; 
}

void	print_arr(t_info *data)
{
	int i = 0;

	while (data->map->data[i])
	{
		printf("%s\n", data->map->data[i]);
		i++;
	}
}