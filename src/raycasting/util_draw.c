/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:18 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:19 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

unsigned int	rgba_to_color(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

void	image_draw_pixel(t_img *img, int x, int y, int color)
{
	char	*target;

	target = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(unsigned int *)target = color;
}

void	adjust_wall_height(t_draw *draw, t_data *data, float *original_height)
{
	const int	max_height = data->img->height * 4;

	*original_height = draw->wall_height;
	if (draw->wall_height > max_height)
	{
		draw->wall_start = (data->img->height - max_height) / 2.0f;
		draw->wall_end = draw->wall_start + max_height;
		draw->wall_height = max_height;
	}
}

int	get_texture_y(float tex_pos, int texture_height)
{
	int	tex_y;

	tex_y = (int)tex_pos;
	if (tex_y >= texture_height)
		tex_y = texture_height -1;
	if (tex_y < 0)
		tex_y = 0;
	return (tex_y);
}
