/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:32 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:33 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_border(t_data *data, int x, int y, int modifier)
{
	int	i;
	int	j;

	i = 0;
	while (i < modifier)
	{
		j = 0;
		while (j < modifier)
		{
			if (i < 1 || i >= modifier - 1 || j < 1 || j >= modifier - 1)
				image_draw_pixel(data->img, x * modifier + i, y * modifier + j \
				, rgba_to_color(0, 135, 206, 235));
			j++;
		}
		i++;
	}
}

void	draw_content(t_data *data, int x, int y, int modifier)
{
	int	color;
	int	i;
	int	j;

	i = 0;
	while (i < modifier - 1)
	{
		j = 1;
		while (j < modifier - 1)
		{
			if (data->map->map_2d[y][x] == '1')
				color = rgba_to_color(255, 105, 180, 255);
			else
				color = rgba_to_color(255, 182, 193, 200);
			image_draw_pixel(data->img, x * modifier + i, y * modifier + j \
			, color);
			j++;
		}
		i++;
	}
}
