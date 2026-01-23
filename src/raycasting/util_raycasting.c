/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:24 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:25 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_step_distance(t_ray_casting *rc)
{
	if (rc->dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (rc->ray_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0f - rc->ray_x) * rc->delta_dist_x;
	}
	if (rc->dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (rc->ray_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0f - rc->ray_y) * rc->delta_dist_y;
	}
}

void	init_ray_casting(t_ray_casting *rc, t_data *data, int i)
{
	rc->ray_angle = data->map->player->rotation - (rc->fov / 2) \
		+ (i * rc->angle_step);
	rc->ray_x = data->map->player->current_position->y;
	rc->ray_y = data->map->player->current_position->x;
	rc->dir_x = cos(rc->ray_angle);
	rc->dir_y = -sin(rc->ray_angle);
	rc->delta_dist_x = fabs(1.0f / rc->dir_x);
	rc->delta_dist_y = fabs(1.0f / rc->dir_y);
	rc->map_x = (int)rc->ray_x;
	rc->map_y = (int)rc->ray_y;
	init_step_distance(rc);
}

void	perform_dda(t_ray_casting *rc, t_data *data)
{
	rc->hit = 0;
	while (!rc->hit && rc->map_x >= 0 && rc->map_x < data->map->map_width
		&& rc->map_y >= 0 && rc->map_y < data->map->map_height)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (rc->map_x >= 0 && rc->map_x < data->map->map_width
			&& rc->map_y >= 0 && rc->map_y < data->map->map_height
			&& data->map->map_2d[rc->map_y][rc->map_x] == '1')
			rc->hit = 1;
	}
}
