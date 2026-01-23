/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:29:08 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 15:29:09 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	init_data(data);
	if (!parsing(av[1], ac, data))
	{
		free_data(data);
		return (1);
	}
	if (!create_window(data))
	{
		free_data(data);
		return (1);
	}
	free_data(data);
	return (0);
}
