/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:05 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 16:50:11 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	texture_ok(t_textures *textures)
{
	int	tmp_fd[4];
	int	count;
	int	i;

	tmp_fd[0] = open(textures->no_file, O_RDONLY);
	tmp_fd[1] = open(textures->so_file, O_RDONLY);
	tmp_fd[2] = open(textures->we_file, O_RDONLY);
	tmp_fd[3] = open(textures->ea_file, O_RDONLY);
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (tmp_fd[i] != -1)
		{
			count++;
			close(tmp_fd[i]);
		}
		i++;
	}
	return (count == 4);
}

bool	color_not_ok(t_textures *textures)
{
	int	color;

	color = (textures->f_ok == 0 || textures->c_ok == 0
			|| textures->f_r < 0 || textures->f_r > 255
			|| textures->f_g < 0 || textures->f_g > 255
			|| textures->f_b < 0 || textures->f_b > 255
			|| textures->c_r < 0 || textures->c_r > 255
			|| textures->c_g < 0 || textures->c_g > 255
			|| textures->c_b < 0 || textures->c_b > 255);
	return (color);
}

bool	check_texture(t_data *data)
{
	if (!texture_ok(data->textures))
	{
		write(2, "Error\nCannot open texture\n", 26);
		return (false);
	}
	if (color_not_ok(data->textures))
	{
		write(2, "Error\nProblem with color\n", 25);
		return (false);
	}
	return (true);
}
