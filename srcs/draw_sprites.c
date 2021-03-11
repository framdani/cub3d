/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:51:41 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:20:56 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		sprite_distance(t_game *game, int *sprite_order,
		double *sprite_dist, int n)
{
	int			i;
	t_player	player;
	t_place		*sprite;

	i = 0;
	player = game->player;
	sprite = game->sprite_place;
	while (i < n)
	{
		sprite_order[i] = i;
		sprite_dist[i] = ((player.posx - sprite[i].x) *
				(player.posx - sprite[i].x) + (player.posy - sprite[i].y) *
				(player.posy - sprite[i].y));
		i++;
	}
}

void		draw_vertical_stripe(int stripe, t_game *game, t_sprite sprite,
		double *zbuffer)
{
	t_pixel tex;
	int		y;
	int		d;
	int		color;

	tex.x = (int)(256 * (stripe - (-sprite.width / 2 + sprite.screen_x))
			* 64 / sprite.width) / 256;
	if (sprite.transform_y > 0 && stripe > 0 && stripe < game->width &&
			sprite.transform_y < zbuffer[stripe])
	{
		y = sprite.draw_start_y;
		while (y < sprite.draw_end_y)
		{
			d = (y) * 256 - game->height * 128 + sprite.height * 128;
			tex.y = ((d * 64) / sprite.height) / 256;
			color = game->textures[4].add[TEX_HEIGHT * tex.y + tex.x];
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(game, stripe, y, color);
			y++;
		}
	}
}

void		draw_sprite(t_game *game, t_sprite sprite, double *zbuffer)
{
	int stripe;

	stripe = sprite.draw_start_x;
	while (stripe < sprite.draw_end_x)
	{
		draw_vertical_stripe(stripe, game, sprite, zbuffer);
		stripe++;
	}
}

void		draw_sprites(t_game *game, double *zbuffer, int num_sprites)
{
	int			sprite_order[num_sprites];
	double		sprite_dist[num_sprites];
	t_sprite	sprite;
	int			i;

	i = 0;
	sprite_distance(game, sprite_order, sprite_dist,
			num_sprites);
	sort_sprites(sprite_order, sprite_dist, num_sprites);
	while (i < num_sprites)
	{
		sprite = sprite_setup(game, sprite_order, i);
		draw_sprite(game, sprite, zbuffer);
		i++;
	}
}
