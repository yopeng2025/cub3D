/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:55 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 15:29:56 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_valid_color(char **color_tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (!color_tab[i] || !ft_isnumeric(color_tab[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_filename(char *filename, char *ext)
{
	if ((!filename || ft_strlen(filename) < 4) || \
		(ft_strcmp(filename + ft_strlen(filename) - 4, ext)))
		return (false);
	return (true);
}

bool	is_valid_texture(t_textures *textures)
{
	int	valid;
	int	file_name;

	valid = (textures->no_file && textures->so_file && \
			textures->we_file && textures->ea_file && \
			textures->f_ok && textures->c_ok);
	file_name = (is_valid_filename(textures->no_file, ".xpm") && \
				is_valid_filename(textures->so_file, ".xpm") && \
				is_valid_filename(textures->we_file, ".xpm") && \
				is_valid_filename(textures->ea_file, ".xpm"));
	return (valid && file_name);
}
