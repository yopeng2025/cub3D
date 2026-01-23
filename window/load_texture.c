/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:00 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:29:01 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	texture_loaded(t_data *data, t_texture **t, char *filename)
{
	int	width;
	int	height;
	int	bpp;
	int	endian;

	(*t) = malloc(sizeof(t_texture));
	if (!(*t))
	{
		printf("Error\nmalloc texture failed\n");
		return ;
	}
	(*t)->img = mlx_xpm_file_to_image(data->mlx, filename, &width, &height);
	if ((*t)->img == NULL)
		return (free(*t), (*t) = NULL, (void)0);
	(*t)->width = width;
	(*t)->height = height;
	(*t)->addr = \
		mlx_get_data_addr((*t)->img, &bpp, &(*t)->line_length, &endian);
	if (!(*t)->addr)
	{
		mlx_destroy_image(data->mlx, (*t)->img);
		return (free((*t)), (*t) = NULL, (void)0);
	}
}

bool	load_texture(t_data *data)
{
	int	i;

	texture_loaded(data, &data->map->textures[0], data->textures->no_file);
	texture_loaded(data, &data->map->textures[1], data->textures->so_file);
	texture_loaded(data, &data->map->textures[2], data->textures->we_file);
	texture_loaded(data, &data->map->textures[3], data->textures->ea_file);
	i = 0;
	while (i < 4)
	{
		if (data->map->textures[i] == 0)
			return (false);
		i++;
	}
	return (true);
}
