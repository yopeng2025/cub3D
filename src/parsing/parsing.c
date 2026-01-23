/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:33 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 17:13:07 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_extension(char *filename)
{
	if (!filename)
		return (false);
	if (ft_strlen(filename) < 4)
		return (false);
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".cub", 4) != 0)
		return (false);
	return (true);
}

char	**dup_map(t_map *map)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (map->map_height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->map_height)
	{
		copy[i] = ft_strdup(map->map_2d[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[map->map_height] = NULL;
	return (copy);
}

bool	check_file(int fd, char *filename, t_data *data)
{
	int	n_line;

	data->n_line_file = get_total_lines(filename);
	n_line = 0;
	if (!init_texture(data))
		return (false);
	if (!parse_texture(fd, data, &n_line))
	{
		get_next_line_trim(-1);
		write(2, "Error\nInvalid texture\n", 22);
		return (false);
	}
	if (!check_texture(data))
	{
		get_next_line_trim(-1);
		return (false);
	}
	if (!parse_map(fd, data, &n_line))
		return (false);
	if (!check_map(data))
		return (false);
	return (true);
}

bool	parsing(char *filename, int ac, t_data *data)
{
	int	fd;

	if (ac != 2)
		return (write(2, "Error\nInvalid number of arguments\n", 34), false);
	if (!check_extension(filename))
		return (write(2, "Error\nInvalid file name or extension\n", 37), false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (write(2, "Error\nFile cannot open\n", 23), false);
	if (!check_file(fd, filename, data))
	{
		if (fd > 0)
			close(fd);
		return (false);
	}
	close(fd);
	return (true);
}
