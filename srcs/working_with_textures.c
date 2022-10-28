/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_with_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ateak <ateak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:36 by ateak             #+#    #+#             */
/*   Updated: 2022/10/28 17:35:41 by ateak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_xpm(t_info *data, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_w, &img->img_h);
	if (img->img == NULL)
		ft_error_exit("Xpm file error");
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
										&img->len, &img->endian);
	y = 0;
	while (y < img->img_h)
	{
		x = 0;
		while (x < img->img_w)
		{
			texture[img->img_w * y + x] = img->data[img->img_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->img);
}

void	import_textures(t_info *data)
{
	t_img	img;

	make_xpm(data, data->textures[0], data->map.north_texture, &img);
	make_xpm(data, data->textures[1], data->map.south_texture, &img);
	make_xpm(data, data->textures[2], data->map.east_texture, &img);
	make_xpm(data, data->textures[3], data->map.west_texture, &img);
}

int	malloc_for_textures(t_info *data)
{
	int	i;

	data->textures = (int **)malloc(sizeof(int *) * 5);
	if (data->textures == NULL)
		ft_error_exit("Malloc for textures failed");
	i = 0;
	while (i < 5)
	{
		data->textures[i] = (int *)malloc(sizeof(int)
				*(TEXTURE_H * TEXTURE_W));
		if (data->textures[i] == NULL)
			ft_error_exit("Malloc for textures failed");
		i++;
	}
	return (0);
}
