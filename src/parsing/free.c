/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:15 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 15:29:16 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_tab(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
}

void	free_texture(t_textures *textures)
{
	if (textures->no_file)
		free(textures->no_file);
	if (textures->so_file)
		free(textures->so_file);
	if (textures->we_file)
		free(textures->we_file);
	if (textures->ea_file)
		free(textures->ea_file);
	free(textures);
}

void	free_player(t_player *player)
{
	if (player->current_position)
		free(player->current_position);
	if (player->start_position)
		free(player->start_position);
	free (player);
}

void	free_texture_tab(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4 && data->map)
	{
		if (data->map->textures[i])
		{
			if (data->map->textures[i]->img)
				mlx_destroy_image(data->mlx, data->map->textures[i]->img);
			free(data->map->textures[i]);
		}
		i++;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_texture_tab(data);
	if (data->mlx)
	{
		if (data->img)
			mlx_destroy_image(data->mlx, data->img);
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->textures)
		free_texture(data->textures);
	if (data->map)
	{
		if (data->map->player)
			free_player(data->map->player);
		if (data->map->map_2d)
			free_tab(data->map->map_2d);
		free(data->map);
	}
	free(data);
}
