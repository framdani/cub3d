/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:42:22 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:22:54 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		trace_further(t_ray *ray)
{
	int side;

	side = 0;
	if (ray->sidex < ray->sidey)
	{
		ray->sidex += ray->deltax;
		ray->map_x += ray->stepx;
		if (ray->dirx > 0)
			side = 0;
		else
			side = 2;
	}
	else
	{
		ray->sidey += ray->deltay;
		ray->map_y += ray->stepy;
		if (ray->diry > 0)
			side = 1;
		else
			side = 3;
	}
	return (side);
}

void	get_texture_data(t_tex_data *tex, t_game *game, int draw_start,
		int line_height)
{
	double		wallx;
	t_player	player;
	t_ray		ray;

	wallx = 0;
	player = game->player;
	ray = game->ray;
	if (tex->side % 2 == 0)
		wallx = player.posy + ray.perp_wall * ray.diry;
	else
		wallx = player.posx + ray.perp_wall * ray.dirx;
	wallx -= floor(wallx);
	tex->texx = (int)(wallx * (double)TEX_WIDTH);
	if (tex->side == 0)
		tex->texx = TEX_WIDTH - tex->texx - 1;
	if (tex->side == 3)
		tex->texx = TEX_WIDTH - tex->texx - 1;
	tex->step = 1.0 * TEX_HEIGHT / line_height;
	tex->texpos = (draw_start - game->height / 2.0 + line_height / 2.0) *
		tex->step;
}

int		define_interval(t_tex_data tex, t_game *game, t_interval *interval,
		int h)
{
	t_ray		*ray;
	t_player	player;
	int			line_height;

	ray = &game->ray;
	player = game->player;
	if (tex.side % 2 == 0)
		ray->perp_wall = (ray->map_x - player.posx + (1.0 - ray->stepx) / 2) /
			ray->dirx;
	else
		ray->perp_wall = (ray->map_y - player.posy + (1.0 - ray->stepy) / 2) /
			ray->diry;
	line_height = (int)(game->height / ray->perp_wall);
	interval->draw_start = -line_height / 2 + h / 2;
	if (interval->draw_start < 0)
		interval->draw_start = 0;
	interval->draw_end = line_height / 2 + h / 2;
	if (interval->draw_end >= h)
		interval->draw_end = h - 1;
	return (line_height);
}

void	draw_walls(t_game *game, double *zbuffer)
{
	t_ray		*ray;
	t_tex_data	tex;
	t_interval	interval;
	int			x;
	int			line_height;

	ray = &game->ray;
	x = 1;
	line_height = 0;
	while (x < game->width)
	{
		get_ray(game, x);
		while (game->map[ray->map_x][ray->map_y] != '1')
			tex.side = trace_further(ray);
		line_height = define_interval(tex, game, &interval, game->height);
		get_texture_data(&tex, game, interval.draw_start, line_height);
		draw_ceiling(game, x, interval.draw_start, game->c);
		draw_texture(game, tex, x, interval);
		draw_floor(game, x, interval.draw_end, game->f);
		zbuffer[x] = ray->perp_wall;
		x++;
	}
}

void	start_drawing(t_game *game)
{
	double *zbuffer;

	zbuffer = (double *)malloc(sizeof(double) * game->width);
	draw_walls(game, zbuffer);
	draw_sprites(game, zbuffer, game->num_sprites);
	free(zbuffer);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->mlx.img, 0, 0);
}
