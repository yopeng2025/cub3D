/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:38 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:39 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_player_pixel(t_data *data, double x, double y, int size)
{
	int	i;
	int	j;
	int	glow_color;

	glow_color = rgba_to_color(0, 255 - (size * 30), 215 - (size * 25), 0);
	i = -size;
	while (i <= size)
	{
		j = -size;
		while (j <= size)
		{
			if (i * i + j * j <= size * size)
				image_draw_pixel(data->img, x + i, y + j, glow_color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data, int x, int y, int modifier)
{
	int		player_size;
	double	precise_x;
	double	precise_y;

	player_size = modifier / 4;
	precise_x = (x + (data->map->player->current_position->y - \
		(int)data->map->player->current_position->y)) * modifier;
	precise_y = (y + (data->map->player->current_position->x - \
		(int)data->map->player->current_position->x)) * modifier;
	while (player_size >= 0)
	{
		draw_player_pixel(data, precise_x, precise_y, player_size);
		player_size--;
	}
}
