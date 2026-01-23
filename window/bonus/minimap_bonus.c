/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:35 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:36 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_minimap(t_data *data, int x, int y, int modifier)
{
	draw_border(data, x, y, modifier);
	draw_content(data, x, y, modifier);
	if (x == (int)data->map->player->current_position->y && \
		y == (int)data->map->player->current_position->x)
		draw_player(data, x, y, modifier);
}

void	minimap(t_data *data, int modifier)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map->map_height)
	{
		x = 0;
		while (x < data->map->map_width)
		{
			draw_minimap(data, x, y, modifier);
			x++;
		}
		y++;
	}
}
