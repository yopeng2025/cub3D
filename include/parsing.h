/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peiyli <peiyli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:04:16 by peiyli            #+#    #+#             */
/*   Updated: 2026/01/22 16:04:17 by peiyli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

//texture
char		**split_line(char *line);
bool		fill_texture_data(char *line, t_textures *textures);
bool		fill_color(char *str, char c, t_textures *textures);
bool		fill_color_data(char *line, t_textures *textures);
bool		parse_texture(int fd, t_data *data, int	*n_line);

//line
char		*get_next_line_trim(int fd);

//initial
bool		init_texture(t_data *data);
void		init_data(t_data *data);
bool		init_player(t_data *data);
bool		init_map(t_data *data, int n_line);

//parse map
int			get_total_lines(char *filename);
bool		fill_map(char *old_line, int fd, t_data *data);
bool		padding_map(t_map *map);
bool		parse_map(int fd, t_data *data, int *n_line);

//parsing
bool		check_extension(char *filename);
char		**dup_map(t_map *map);
bool		check_file(int fd, char *filename, t_data *data);
bool		parsing(char *filename, int ac, t_data *data);

//util
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup_trim(char *line);
int			ft_isnumeric(char *str);
int			get_max_len(char **map_2d);
void		ft_copy(char *dest, char *src);

//free
void		free_tab(char **table);
void		free_texture(t_textures *textures);
void		free_texture_tab(t_data *data);
void		free_player(t_player *player);
void		free_data(t_data *data);

//valid
bool		is_valid_color(char **color_tab);
bool		is_valid_filename(char *filename, char *ext);
bool		is_valid_texture(t_textures *textures);

//player
bool		is_player_char(char c);
t_vector	*set_player_pos(int i, int j, char c, t_player *player);
void		get_player(t_data *data);

//check_texture
bool		texture_ok(t_textures *textures);
bool		color_not_ok(t_textures *textures);
bool		check_texture(t_data *data);

//check_map
void		free_map(char **map);
bool		check_map(t_data *data);
bool		check_map_character(char **map_2d);
bool		flood_fill(t_map *map, char **map_2d, int x, int y);

//debug
void		print_map(t_map *map);
void		print_file(int fd);
void		debug_map(char **map);

#endif
