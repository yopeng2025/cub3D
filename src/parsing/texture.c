/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:44 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 17:02:50 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**split_line(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	if (!split[0] || !split[1] || ft_strlen(split[0]) > 2)
		return (free_tab(split), NULL);
	return (split);
}

bool	fill_texture_data(char *line, t_textures *textures)
{
	char	**line_tab;
	char	*element;

	line_tab = split_line(line);
	if (!line_tab)
		return (false);
	if (textures->no_file && textures->so_file \
		&& textures->we_file && textures->ea_file)
		return (free_tab(line_tab), false);
	element = line_tab[0];
	if (!textures->no_file && (!ft_strcmp(element, "NO") \
		|| (element[0] == 'N' && ft_strlen(element) == 1)))
		textures->no_file = ft_strdup(line_tab[1]);
	if (!textures->so_file && (!ft_strcmp(element, "SO") \
		|| (element[0] == 'S' && ft_strlen(element) == 1)))
		textures->so_file = ft_strdup(line_tab[1]);
	if (!textures->we_file && (!ft_strcmp(element, "WE") \
		|| (element[0] == 'W' && ft_strlen(element) == 1)))
		textures->we_file = ft_strdup(line_tab[1]);
	if (!textures->ea_file && (!ft_strcmp(element, "EA") \
		|| (element[0] == 'E' && ft_strlen(element) == 1)))
		textures->ea_file = ft_strdup(line_tab[1]);
	return (free_tab(line_tab), true);
}

bool	fill_color(char *str, char c, t_textures *textures)
{
	char	**color_tab;

	color_tab = ft_split(str, ',');
	if (!color_tab)
		return (false);
	if (!is_valid_color(color_tab) || color_tab[3])
		return (free_tab(color_tab), false);
	if (c == 'F')
	{
		textures->f_r = ft_atoi(color_tab[0]);
		textures->f_g = ft_atoi(color_tab[1]);
		textures->f_b = ft_atoi(color_tab[2]);
		textures->f_ok = 1;
		return (free_tab(color_tab), true);
	}
	else if (c == 'C')
	{
		textures->c_r = ft_atoi(color_tab[0]);
		textures->c_g = ft_atoi(color_tab[1]);
		textures->c_b = ft_atoi(color_tab[2]);
		textures->c_ok = 1;
		return (free_tab(color_tab), true);
	}
	return (false);
}

bool	fill_color_data(char *line, t_textures *textures)
{
	char	**line_tab;
	char	*element;

	line_tab = split_line(line);
	if (!line_tab)
		return (false);
	element = line_tab[0];
	if ((!ft_strcmp(element, "F") || !ft_strcmp(element, "C")) \
		&& fill_color(line_tab[1], element[0], textures))
	{
		free_tab(line_tab);
		return (true);
	}
	free_tab(line_tab);
	return (false);
}

bool	parse_texture(int fd, t_data *data, int	*n_line)
{
	char	*line;

	line = get_next_line_trim(fd);
	if (!line)
		return (false);
	while (line)
	{
		(*n_line)++;
		if (ft_strlen(line) && ft_strchr("NSWE", line[0]) && \
			!fill_texture_data(line, data->textures))
			return (free(line), false);
		else if (ft_strlen(line) && ft_strchr("FC", line[0]) && \
			!fill_color_data(line, data->textures))
			return (free(line), false);
		free(line);
		if (is_valid_texture(data->textures))
			break ;
		line = get_next_line_trim(fd);
	}
	return (is_valid_texture(data->textures));
}
