/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:52 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:53 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_data *data)
{
	free_data(data);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		free_data(data);
		exit(0);
	}
	if (keycode == KEY_LEFT)
		data->map->player->rotate_left = 1;
	if (keycode == KEY_RIGHT)
		data->map->player->rotate_right = 1;
	if (keycode == KEY_A)
		data->map->player->move_left = 1;
	if (keycode == KEY_D)
		data->map->player->move_right = 1;
	if (keycode == KEY_W)
		data->map->player->move_forward = 1;
	if (keycode == KEY_S)
		data->map->player->move_backward = 1;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT)
		data->map->player->rotate_left = 0;
	if (keycode == KEY_RIGHT)
		data->map->player->rotate_right = 0;
	if (keycode == KEY_A)
		data->map->player->move_left = 0;
	if (keycode == KEY_D)
		data->map->player->move_right = 0;
	if (keycode == KEY_W)
		data->map->player->move_forward = 0;
	if (keycode == KEY_S)
		data->map->player->move_backward = 0;
	return (0);
}
