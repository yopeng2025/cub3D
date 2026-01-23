/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:19 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/23 11:06:08 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	init_texture(t_data *data)
{
	data->textures = malloc(sizeof(t_textures));
	if (!data->textures)
		return (false);
	data->textures->no_file = NULL;
	data->textures->so_file = NULL;
	data->textures->we_file = NULL;
	data->textures->ea_file = NULL;
	data->textures->f_ok = 0;
	data->textures->c_ok = 0;
	data->textures->f_r = -1;
	data->textures->f_g = -1;
	data->textures->f_b = -1;
	data->textures->c_r = -1;
	data->textures->c_g = -1;
	data->textures->c_b = -1;
	return (true);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->map = NULL;
	data->textures = NULL;
}

bool	init_player(t_data *data)
{
	data->map->player = ft_calloc(1, sizeof(t_player));
	if (!data->map->player)
		return (false);
	data->map->player->current_position = NULL;
	data->map->player->start_position = NULL;
	data->map->player->delta_x = 0.0;
	data->map->player->delta_y = 0.0;
	data->map->player->rotation = 0.0;
	data->map->player->move_forward = 0;
	data->map->player->move_backward = 0;
	data->map->player->move_left = 0;
	data->map->player->move_right = 0;
	data->map->player->rotate_left = 0;
	data->map->player->rotate_right = 0;
	return (true);
}

bool	init_map(t_data *data, int n_line)
{
	int	i;

	data->map = ft_calloc(1, sizeof(t_map));
	if (!data->map)
		return (false);
	data->map->map_height = data->n_line_file - n_line;
	data->map->map_width = 0;
	data->map->map_2d = ft_calloc(data->map->map_height + 1, sizeof(char *));
	if (!data->map->map_2d)
		return (false);
	data->map->map_2d[data->map->map_height] = NULL;
	data->map->n_player = 0;
	data->map->player_x = 0;
	data->map->player_y = 0;
	data->map->player = NULL;
	i = 0;
	while (i < 4)
	{
		data->map->textures[i] = NULL;
		i++;
	}
	return (true);
}
