/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:41 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:42 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	init_mlx_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		write(2, "Error\nmlx_init failed\n", 23);
		return (false);
	}
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->mlx_win)
	{
		write(2, "Error\nmlx_new_window failed\n", 29);
		return (false);
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		write(2, "Error\nmlx_new_image failed\n", 28);
		return (false);
	}
	if (!load_texture(data))
	{
		write(2, "Error\nload_texture failed\n", 27);
		return (false);
	}
	return (true);
}

void	update_image(t_data *data)
{
	raycasting(data);
	minimap(data, HEIGHT / 80);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

bool	create_window(t_data *data)
{
	if (!init_mlx_window(data))
		return (false);
	update_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_hook(data->mlx_win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_win, 3, 1L << 1, key_release, data);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_loop_hook(data->mlx, game_loop, data);
	mlx_loop(data->mlx);
	return (true);
}
