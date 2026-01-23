/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:29 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 17:21:54 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_total_lines(char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

bool	fill_map(char *old_line, int fd, t_data *data)
{
	int		i;
	char	*line;

	line = old_line;
	i = 0;
	while (line)
	{
		if (!ft_strncmp("\n", line, 1))
		{
			write(2, "Error\nEmpty line in map\n", 24);
			free(line);
			return (false);
		}
		data->map->map_2d[i++] = ft_strdup_trim(line);
		free(line);
		line = get_next_line(fd);
	}
	return (true);
}

bool	padding_map(t_map *map)
{
	char	**new_2d;
	char	*tmp;
	int		max_len;
	int		i;

	max_len = get_max_len(map->map_2d);
	new_2d = map->map_2d;
	i = 0;
	while (new_2d[i])
	{
		tmp = ft_calloc(max_len + 1, sizeof(char));
		if (!tmp)
			return (false);
		ft_memset(tmp, ' ', max_len);
		ft_copy(tmp, new_2d[i]);
		free(new_2d[i]);
		new_2d[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	map->map_width = max_len;
	return (true);
}

bool	parse_map(int fd, t_data *data, int *n_line)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (false);
	while (line && !ft_strncmp("\n", line, 1))
	{
		free(line);
		line = get_next_line(fd);
		(*n_line)++;
	}
	if (!init_map(data, *n_line))
		return (false);
	if (!fill_map(line, fd, data))
	{
		get_next_line_trim(-1);
		return (false);
	}
	if (!padding_map(data->map))
		return (false);
	if (!init_player(data))
		return (false);
	get_player(data);
	return (true);
}
