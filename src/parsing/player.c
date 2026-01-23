/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:38 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 15:29:39 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_player_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

t_vector	*set_player_pos(int i, int j, char c, t_player *player)
{
	t_vector	*current_pos;

	if (!player->current_position)
	{
		current_pos = ft_calloc(1, sizeof(t_vector));
		if (!current_pos)
			return (NULL);
		player->current_position = current_pos;
	}
	player->current_position->x = i + 0.5;
	player->current_position->y = j + 0.5;
	if (c == 'N')
		player->rotation = M_PI / 2;
	else if (c == 'S')
		player->rotation = 3 * M_PI / 2;
	else if (c == 'W')
		player->rotation = M_PI;
	else if (c == 'E')
		player->rotation = 0;
	player->delta_x = cos(player->rotation) * 5;
	player->delta_y = sin(player->rotation) * 5;
	return (player->current_position);
}

void	get_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map_2d[i])
	{
		j = 0;
		while (data->map->map_2d[i][j])
		{
			if (is_player_char(data->map->map_2d[i][j]))
			{
				set_player_pos(i, j, data->map->map_2d[i][j], \
					data->map->player);
					data->map->n_player++;
					data->map->player_x = i;
					data->map->player_y = j;
					data->map->map_2d[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}
