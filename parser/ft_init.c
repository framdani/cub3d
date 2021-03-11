/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:43:32 by framdani          #+#    #+#             */
/*   Updated: 2021/01/14 14:14:27 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_game		init_game(void)
{
	t_game game;

	game.width = -1;
	game.height = -1;
	game.buffer = NULL;
	game.map = NULL;
	game.map_width = 0;
	game.map_height = 0;
	game.elements = 0;
	game.mapdetected = 0;
	game.num_sprites = 0;
	game.c = -1;
	game.f = -1;
	game.save = 0;
	return (game);
}

t_player	init_player(void)
{
	t_player player;

	player.nbr = 0;
	player.posx = 0;
	player.posy = 0;
	player.planex = 0;
	player.planey = 0;
	player.dirx = 0;
	player.diry = 0;
	player.rot_s = 0.3;
	return (player);
}

t_tex_paths	init_texture(void)
{
	t_tex_paths texture;

	texture.no = NULL;
	texture.we = NULL;
	texture.ea = NULL;
	texture.so = NULL;
	texture.sp = NULL;
	return (texture);
}
