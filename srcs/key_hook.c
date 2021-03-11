/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:16:30 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:20:46 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_horizontal(t_player *player, char **map, int factor)
{
	double	x;
	double	y;

	x = player->posx + (player->planex * factor) * MOVE_S;
	y = player->posy + (player->planey * factor) * MOVE_S;
	if (map[(int)x][(int)player->posy] == '0')
		player->posx = x;
	if (map[(int)player->posx][(int)y] == '0')
		player->posy = y;
}

void	move_vertical(t_player *player, char **map, int factor)
{
	double	x;
	double	y;

	x = player->posx + (player->dirx * factor) * MOVE_S;
	y = player->posy + (player->diry * factor) * MOVE_S;
	if (map[(int)x][(int)player->posy] == '0')
		player->posx = x;
	if (map[(int)player->posx][(int)y] == '0')
		player->posy = y;
}

void	turn(t_player *player, double rot_s)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = player->dirx;
	player->dirx = player->dirx * cos(rot_s) - player->diry * sin(rot_s);
	player->diry = old_dirx * sin(rot_s) + player->diry * cos(rot_s);
	old_planex = player->planex;
	player->planex = player->planex * cos(rot_s) - player->planey * sin(rot_s);
	player->planey = old_planex * sin(rot_s) + player->planey * cos(rot_s);
}

int		key_press(int key, t_game *game)
{
	if (key == ESC)
		red_cross(key);
	else if (key == KEY_A)
		move_horizontal(&game->player, game->map, -1);
	else if (key == KEY_D)
		move_horizontal(&game->player, game->map, 1);
	else if (key == KEY_W)
		move_vertical(&game->player, game->map, 1);
	else if (key == KEY_S)
		move_vertical(&game->player, game->map, -1);
	else if (key == KEY_RIGHT)
		turn(&game->player, -game->player.rot_s);
	else if (key == KEY_LEFT)
		turn(&game->player, game->player.rot_s);
	start_drawing(game);
	return (0);
}

int		red_cross(int key)
{
	key = 0;
	exit(1);
	return (0);
}
