/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:44 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 17:45:00 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	allocate_points(int points[4][2], double x, double y)
{
	points[0][0] = (int)(x - 0.1);
	points[0][1] = (int)(y - 0.1);
	points[1][0] = (int)(x + 0.1);
	points[1][1] = (int)(y - 0.1);
	points[2][0] = (int)(x - 0.1);
	points[2][1] = (int)(y + 0.1);
	points[3][0] = (int)(x + 0.1);
	points[3][1] = (int)(y + 0.1);
}

bool	check_collision(t_data *data, double x, double y)
{
	int	points[4][2];

	allocate_points(points, x, y);
	if (points[0][0] >= 0 && points[0][0] < data->map->map_height && \
		points[0][1] >= 0 && points[0][1] < data->map->map_width && \
		data->map->map_2d[points[0][0]][points[0][1]] == '1')
		return (false);
	if (points[1][0] >= 0 && points[1][0] < data->map->map_height && \
		points[1][1] >= 0 && points[1][1] < data->map->map_width && \
		data->map->map_2d[points[1][0]][points[1][1]] == '1')
		return (false);
	if (points[2][0] >= 0 && points[2][0] < data->map->map_height && \
		points[2][1] >= 0 && points[2][1] < data->map->map_width && \
		data->map->map_2d[points[2][0]][points[2][1]] == '1')
		return (false);
	if (points[3][0] >= 0 && points[3][0] < data->map->map_height && \
		points[3][1] >= 0 && points[3][1] < data->map->map_width && \
		data->map->map_2d[points[3][0]][points[3][1]] == '1')
		return (false);
	return (true);
}
