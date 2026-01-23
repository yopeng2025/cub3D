/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:28 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:29 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	calculate_wall_dist(t_ray_casting *rc)
{
	float	ray_wall_dist;

	if (rc->side == 0)
		ray_wall_dist = (rc->map_x - rc->ray_x + (1 - rc->step_x) / 2) \
			/ rc->dir_x;
	else
		ray_wall_dist = (rc->map_y - rc->ray_y + (1 - rc->step_y) / 2) \
			/ rc->dir_y;
	if (ray_wall_dist < 0.1f)
		ray_wall_dist = 0.1f;
	return (ray_wall_dist);
}

float	normalize_angle_diff(float angle_diff)
{
	while (angle_diff > M_PI)
		angle_diff -= 2 * M_PI;
	while (angle_diff < -M_PI)
		angle_diff += 2 * M_PI;
	return (angle_diff);
}

float	get_texture_index(t_ray_casting *rc)
{
	if (rc->side == 0)
	{
		if (rc->dir_x > 0)
			return (TEXTURE_EA);
		return (TEXTURE_WE);
	}
	if (rc->dir_y > 0)
		return (TEXTURE_SO);
	return (TEXTURE_NO);
}

void	calculate_wall_properties(t_ray_casting *rc, t_data *data)
{
	float	ray_wall_dist;
	float	wall_hit_fraction;
	float	angle_diff;

	ray_wall_dist = calculate_wall_dist(rc);
	angle_diff = normalize_angle_diff(rc->ray_angle - \
		data->map->player->rotation);
	rc->wall_height = (data->img->height / (ray_wall_dist * cos(angle_diff))) \
		* 0.75;
	if (rc->side == 0)
		wall_hit_fraction = rc->ray_y + ray_wall_dist * rc->dir_y;
	else
		wall_hit_fraction = rc->ray_x + ray_wall_dist * rc->dir_x;
	wall_hit_fraction -= floor(wall_hit_fraction);
	rc->tex_x = wall_hit_fraction;
	rc->texture_index = get_texture_index(rc);
}
