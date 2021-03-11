/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 14:15:35 by framdani          #+#    #+#             */
/*   Updated: 2021/03/05 11:16:10 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"
# include <math.h>
# include <mlx.h>
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_A 0
# define KEY_S 1
# define KEY_W 13
# define KEY_D 2
# define ESC 53
# define MOVE_S 0.3
# define ROT_S 0.3
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define MAX_INT 2147483647

typedef struct	s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct	s_interval
{
	int			draw_start;
	int			draw_end;
}				t_interval;

typedef struct	s_pair
{
	double		first;
	int			second;
}				t_pair;

typedef struct	s_place
{
	double	x;
	double	y;
}				t_place;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			screen_x;
	double		transform_x;
	double		transform_y;
	int			width;
	int			height;
	int			draw_start_x;
	int			draw_start_y;
	int			draw_end_x;
	int			draw_end_y;
}				t_sprite;

typedef struct	s_tex_data
{
	int			side;
	int			texx;
	double		step;
	double		texpos;
}				t_tex_data;

typedef	struct	s_data
{
	void		*img;
	int			*add;
	int			bpp;
	int			width;
	int			height;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_tex_paths
{
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*sp;
}				t_tex_paths;

typedef struct	s_player
{
	char		dir;
	int			nbr;
	double		posy;
	double		posx;
	double		planex;
	double		planey;
	double		dirx;
	double		diry;
	double		rot_s;
}				t_player;

typedef struct	s_ray
{
	double		dirx;
	double		diry;
	double		sidex;
	double		sidey;
	double		deltax;
	double		deltay;
	double		stepx;
	double		stepy;
	int			map_x;
	int			map_y;
	double		perp_wall;
}				t_ray;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	int			c;
	int			f;
	int			elements;
	char		*buffer;
	int			map_height;
	int			map_width;
	int			mapdetected;
	char		**map;
	int			num_sprites;
	t_place		sprite_place[200];
	t_tex_paths	texture;
	t_player	player;
	t_data		mlx;
	t_data		textures[5];
	t_ray		ray;
	int			save;
}				t_game;
t_game			init_game();
t_data			init_mlx(t_game *game);
t_player		init_player();
t_tex_paths		init_texture();
t_game			create_new_game();
void			get_errors(char *str, t_game *game);
int				is_direction(char c);
void			check_extension(char *arg);
void			check_save(char *arg, t_game *game);
void			check_map(t_game *game);
void			get_color(char *str, t_game *game);
void			get_resolution(char *str, t_game *game);
void			get_texture(char *str, t_game *game);
void			get_map(char *str, t_game *game);
void			start_drawing(t_game *game);
void			my_mlx_pixel_put(t_game *game, int x, int y, int color);
int				key_press(int key, t_game *game);
int				red_cross(int key);
void			get_player_dir(t_player *player);
void			get_ray(t_game *game, int x);
int				trace_further(t_ray *ray);
void			draw_vertical_line(t_game *game, int x,
		int draw_strart, int draw_end);
void			draw_ceiling(t_game *game, int x, int draw_end, int color);
void			draw_floor(t_game *game, int x, int draw_start, int color);
void			upload_textures(t_game *game);
void			draw_texture(t_game *game, t_tex_data tex, int x,
		t_interval interval);
void			draw_sprites(t_game *game, double *zbuffer, int num_sprites);
void			sort_sprites(int *order, double *dist, int amount);
t_sprite		sprite_setup(t_game *game, int sprite_order[], int i);
void			ft_errors(char *str);
void			clear_memory(char **str);
void			ft_errors_free(char *str, char **mem);
void			screenshot(t_game *game);
#endif
