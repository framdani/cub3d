/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 10:31:03 by framdani          #+#    #+#             */
/*   Updated: 2021/02/10 10:31:18 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	t_data	*mlx;

	mlx = &game->mlx;
	if (y < game->height && y >= 0)
		mlx->add[(y) * game->width + (x)] = color;
}

void	draw_texture(t_game *game, t_tex_data tex, int x, t_interval interval)
{
	int y;
	int texy;
	int color;

	y = interval.draw_start;
	while (y < interval.draw_end)
	{
		texy = (int)tex.texpos & (TEX_HEIGHT - 1);
		tex.texpos += tex.step;
		color = game->textures[tex.side].add[TEX_HEIGHT * texy + tex.texx];
		my_mlx_pixel_put(game, x, y, color);
		y++;
	}
}

void	draw_ceiling(t_game *game, int x, int draw_end, int color)
{
	int y;

	y = 0;
	while (y < draw_end)
	{
		my_mlx_pixel_put(game, x, y, color);
		y++;
	}
}

void	draw_floor(t_game *game, int x, int draw_start, int color)
{
	int y;

	y = draw_start;
	while (y < game->height - 1)
	{
		my_mlx_pixel_put(game, x, y, color);
		y++;
	}
}
