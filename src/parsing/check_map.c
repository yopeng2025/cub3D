/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:59 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 16:32:32 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

bool	flood_fill(t_map *map, char **map_2d, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->map_height || y >= map->map_width \
		|| map_2d[x][y] == ' ')
		return (false);
	if (map_2d[x][y] == '1' || map_2d[x][y] == 'V')
		return (true);
	map_2d[x][y] = 'V';
	if (!flood_fill(map, map_2d, x - 1, y))
		return (false);
	if (!flood_fill(map, map_2d, x + 1, y))
		return (false);
	if (!flood_fill(map, map_2d, x, y - 1))
		return (false);
	if (!flood_fill(map, map_2d, x, y + 1))
		return (false);
	return (true);
}

bool	check_map_character(char **map_2d)
{
	int	i;
	int	j;

	i = 0;
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (!ft_strchr("01EWSN ", map_2d[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map(t_data *data)
{
	char	**copy;

	if (!data->map->n_player)
		return (write(2, "Error\nNo player in the map\n", 28), false);
	if (data->map->n_player > 1)
		return (write(2, "Error\nMore than 1 player in the map\n", 37), false);
	if (!check_map_character(data->map->map_2d))
		return (write(2, "Error\nInvalid character in the map\n", 36), false);
	copy = dup_map(data->map);
	if (!copy)
		return (false);
	if (!flood_fill(data->map, copy, data->map->player_x, data->map->player_y))
	{
		free_map(copy);
		return (write(2, "Error\nMap unclosed\n", 20), false);
	}
	free_map(copy);
	return (true);
}
