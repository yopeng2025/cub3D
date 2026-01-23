/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yopeng <yopeng@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:28:25 by yopeng            #+#    #+#             */
/*   Updated: 2026/01/22 15:28:27 by yopeng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# define WIDTH 1920
# define HEIGHT 1080

# define ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

//window.c
bool			create_window(t_data *data);
void			update_image(t_data *data);
bool			init_mlx_window(t_data *data);

//load_texture.c
bool			load_texture(t_data *data);
void			texture_loaded(t_data *data, t_texture **t, char *filename);

//key.c
int				close_window(t_data *data);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);

//raycasting
void			raycasting(t_data *data);

//util_raycasting.c
void			init_step_distance(t_ray_casting *rc);
void			init_ray_casting(t_ray_casting *rc, t_data *data, int i);
void			perform_dda(t_ray_casting *rc, t_data *data);

//wall.c
float			calculate_wall_dist(t_ray_casting *rc);
float			normalize_angle_diff(float angle_diff);
void			calculate_wall_properties(t_ray_casting *rc, t_data *data);
float			get_texture_index(t_ray_casting *rc);

//draw.c
void			draw_simple_wall(t_data *data, int x, float wall_start, \
				float wall_end);
void			draw_vertical_line(t_data *data, int x, float wall_height, \
				t_ray_casting *rc);
void			draw_wall(t_data *data, t_draw *draw, t_texture *texture);
void			draw_ceiling_floor(t_data *data, int x, float wall_start, \
				float wall_end);

//util_draw.c
unsigned int	rgba_to_color(int a, int r, int g, int b);
void			image_draw_pixel(t_img *img, int x, int y, int color);
void			adjust_wall_height(t_draw *draw, t_data *data, \
				float *original_height);
int				get_texture_y(float tex_pos, int texture_height);

//game.c
int				game_loop(t_data *data);
void			handle_forward(t_data *data, t_player *player, \
				float move_speed);
void			handle_backward(t_data *data, t_player *player, \
				float move_speed);
void			handle_side(t_data *data, t_player *player, float move_speed, \
				int dir);
void			handle_rotation(t_player *player, float rotation_speed, \
				int dir);

//collision
bool			check_collision(t_data *data, double x, double y);
void			allocate_points(int points[4][2], double x, double y);

//bonus
void			update_image(t_data *data);
void			minimap(t_data *data, int modifier);
void			draw_minimap(t_data *data, int x, int y, int modifier);
void			draw_border(t_data *data, int x, int y, int modifier);
void			draw_content(t_data *data, int x, int y, int modifier);
void			draw_player(t_data *data, int x, int y, int modifier);
void			draw_player_pixel(t_data *data, double x, double y, int size);

#endif
