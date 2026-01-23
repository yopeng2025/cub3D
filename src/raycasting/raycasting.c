/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:04 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:05 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	raycasting(t_data *data)
{
	t_ray_casting	rc;
	int				x;

	rc.fov = M_PI / 3;
	rc.angle_step = rc.fov / data->img->width;
	rc.side = 0;
	x = data->img->width - 1;
	while (x >= 0)
	{
		init_ray_casting(&rc, data, data->img->width - 1 - x);
		perform_dda(&rc, data);
		calculate_wall_properties(&rc, data);
		draw_vertical_line(data, x, rc.wall_height, &rc);
		x--;
	}
}
