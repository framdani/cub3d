/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_steup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 18:53:36 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:22:45 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_interval			y_interval(int sprite_height, int h)
{
	t_interval y;

	y.draw_start = -sprite_height / 2 + h / 2;
	if (y.draw_start < 0)
		y.draw_start = 0;
	y.draw_end = sprite_height / 2 + h / 2;
	if (y.draw_end >= h)
		y.draw_end = h - 1;
	return (y);
}

t_interval			x_interval(int sprite_width, int screen_x, int w)
{
	t_interval x;

	x.draw_start = -sprite_width / 2 + screen_x;
	if (x.draw_start < 0)
		x.draw_start = 0;
	x.draw_end = sprite_width / 2 + screen_x;
	if (x.draw_end >= w)
		x.draw_end = w - 1;
	return (x);
}

t_sprite			sprite_setup(t_game *game, int sprite_order[], int i)
{
	t_sprite	sprite;
	double		inv_det;
	t_player	player;

	player = game->player;
	sprite.x = game->sprite_place[sprite_order[i]].x - game->player.posx;
	sprite.y = game->sprite_place[sprite_order[i]].y - game->player.posy;
	inv_det = 1.0 / (player.planex * player.diry - player.dirx * player.planey);
	sprite.transform_x = inv_det * (player.diry * sprite.x - player.dirx *
			sprite.y);
	sprite.transform_y = inv_det * (-player.planey * sprite.x + player.planex
			* sprite.y);
	sprite.screen_x = (int)((game->width / 2) * (1 + sprite.transform_x /
				sprite.transform_y));
	sprite.height = abs((int)(game->height / sprite.transform_y));
	sprite.width = abs((int)(game->height / sprite.transform_y));
	sprite.draw_start_y = y_interval(sprite.height, game->height).draw_start;
	sprite.draw_end_y = y_interval(sprite.height, game->height).draw_end;
	sprite.draw_start_x = x_interval(sprite.width, sprite.screen_x,
			game->width).draw_start;
	sprite.draw_end_x = x_interval(sprite.width, sprite.screen_x,
			game->width).draw_end;
	return (sprite);
}
