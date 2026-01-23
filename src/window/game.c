/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:47 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:48 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_forward(t_data *data, t_player *player, float move_speed)
{
	double	new_x;
	double	new_y;

	new_x = player->current_position->x - move_speed * player->delta_y;
	new_y = player->current_position->y + move_speed * player->delta_x;
	if (check_collision(data, new_x, new_y))
	{
		player->current_position->x = new_x;
		player->current_position->y = new_y;
	}
}

void	handle_backward(t_data *data, t_player *player, float move_speed)
{
	double	new_x;
	double	new_y;

	new_x = player->current_position->x + move_speed * player->delta_y;
	new_y = player->current_position->y - move_speed * player->delta_x;
	if (check_collision(data, new_x, new_y))
	{
		player->current_position->x = new_x;
		player->current_position->y = new_y;
	}
}

void	handle_side(t_data *data, t_player *player, float move_speed, int dir)
{
	double	delta_x;
	double	delta_y;
	double	new_x;
	double	new_y;

	delta_x = cos((M_PI / 2) - player->rotation) * 5;
	delta_y = sin((M_PI / 2) - player->rotation) * 5;
	new_x = player->current_position->x + (dir * delta_y * move_speed);
	new_y = player->current_position->y + (dir * delta_x * move_speed);
	if (check_collision(data, new_x, new_y))
	{
		player->current_position->x = new_x;
		player->current_position->y = new_y;
	}
}

void	handle_rotation(t_player *player, float rotation_speed, int dir)
{
	player->rotation += dir * rotation_speed;
	if (player->rotation < 0)
		player->rotation += 2 * M_PI;
	else if (player->rotation > 2 * M_PI)
		player->rotation -= 2 * M_PI;
	player->delta_x = cos(player->rotation) * 5;
	player->delta_y = sin(player->rotation) * 5;
}

int	game_loop(t_data *data)
{
	float		move_speed;
	float		rotation_speed;
	t_player	*player;

	move_speed = 0.01f;
	rotation_speed = 0.03f;
	player = data->map->player;
	if (player->move_forward)
		handle_forward(data, player, move_speed);
	if (player->move_backward)
		handle_backward(data, player, move_speed);
	if (player->move_left)
		handle_side(data, player, move_speed, -1);
	if (player->move_right)
		handle_side(data, player, move_speed, 1);
	if (player->rotate_left)
		handle_rotation(player, rotation_speed, 1);
	if (player->rotate_right)
		handle_rotation(player, rotation_speed, -1);
	if (player->move_forward || player->move_backward || player->move_left || \
		player->move_right || player->rotate_left || player->rotate_right)
		update_image(data);
	return (0);
}
