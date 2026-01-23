/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:01 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:02 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_simple_wall(t_data *data, int x, float wall_start, float wall_end)
{
	int	y;
	int	color;

	color = rgba_to_color(255, 128, 128, 128);
	y = (int)wall_start;
	while (y < (int)wall_end && y < data->img->height)
	{
		if (y >= 0)
			image_draw_pixel(data->img, x, y, color);
		y++;
	}
}

void	draw_ceiling_floor(t_data *data, int x, float wall_start, \
		float wall_end)
{
	int	y;

	y = 0;
	while (y < wall_start && y < data->img->height)
	{
		if (y >= 0)
			image_draw_pixel(data->img, x, y, rgba_to_color(0, \
			data->textures->c_r, data->textures->c_g, data->textures->c_b));
		y++;
	}
	y = wall_end;
	while (y < data->img->height)
	{
		if (y >= 0)
			image_draw_pixel(data->img, x, y, rgba_to_color(0, \
			data->textures->f_r, data->textures->f_g, data->textures->f_b));
		y++;
	}
}

void	draw_wall(t_data *data, t_draw *draw, t_texture *texture)
{
	float			original_height;
	float			step;
	float			tex_pos;
	int				y;
	unsigned char	*pixel;

	adjust_wall_height(draw, data, &original_height);
	step = (float)texture->height / original_height;
	tex_pos = (draw->wall_start - (data->img->height - original_height) \
				/ 2.0f) * step;
	y = (int)draw->wall_start;
	while (y < draw->wall_end && y < data->img->height)
	{
		if (y >= 0 && draw->tex_x_int >= 0 && draw->tex_x_int < texture->width)
		{
			pixel = (unsigned char *)texture->addr + \
					(get_texture_y(tex_pos, texture->height) * \
					texture->line_length + draw->tex_x_int * 4);
			image_draw_pixel(data->img, draw->x, y, *(unsigned int *)pixel);
		}
		tex_pos += step;
		y++;
	}
}

void	draw_vertical_line(t_data *data, int x, float wall_height,
		t_ray_casting *rc)
{
	t_draw		draw;
	t_texture	*texture;
	float		tex_x;
	int			texture_index;

	tex_x = rc->tex_x;
	texture_index = rc->texture_index;
	if (!data || !data->img || x < 0 || x >= data->img->width)
		return ;
	draw.x = x;
	draw.wall_height = wall_height;
	draw.wall_start = (data->img->height - wall_height) / 2.0f;
	draw.wall_end = draw.wall_start + wall_height;
	draw.texture_index = texture_index;
	texture = data->map->textures[texture_index];
	if (!texture || !texture->addr || !texture->img)
	{
		draw_simple_wall(data, x, draw.wall_start, draw.wall_end);
		return ;
	}
	draw.tex_x_int = (int)(tex_x * (texture->width - 1));
	draw_ceiling_floor(data, x, draw.wall_start, draw.wall_end);
	draw_wall(data, &draw, texture);
}
