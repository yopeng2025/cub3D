/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:04:09 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 16:04:10 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../minilibx-linux/mlx_int.h"

typedef struct s_textures
{
	char	*no_file;
	char	*so_file;
	char	*we_file;
	char	*ea_file;
	int		f_ok;
	int		c_ok;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
}	t_textures;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	*start_position;
	t_vector	*current_position;
	double		delta_x;
	double		delta_y;
	double		rotation;
	int			move_forward;
	int			move_backward;
	int			move_left;
	int			move_right;
	int			rotate_left;
	int			rotate_right;
}	t_player;

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		line_length;
}	t_texture;

typedef struct s_map
{
	char		**map_2d;
	int			map_height;
	int			map_width;
	int			n_player;
	int			player_x;
	int			player_y;
	t_player	*player;
	t_texture	*textures[4];
}	t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_textures	*textures;
	t_map		*map;
	t_img		*img;
	int			n_line_file;
}	t_data;

typedef struct s_ray_casting
{
	float	fov;
	float	angle_step;
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	float	dir_x;
	float	dir_y;
	float	delta_dist_x;
	float	delta_dist_y;
	int		map_x;
	int		map_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	float	wall_height;
	float	tex_x;
	int		texture_index;
}	t_ray_casting;

typedef struct s_draw
{
	int		x;
	float	wall_height;
	float	wall_start;
	float	wall_end;
	int		texture_index;
	int		tex_x_int;
	float	step;
	float	tex_pos;
	int		img_height;
}	t_draw;

#endif
