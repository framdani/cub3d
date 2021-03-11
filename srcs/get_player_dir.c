/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:16:40 by framdani          #+#    #+#             */
/*   Updated: 2021/02/11 11:16:44 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		get_player_dir(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dirx = -1;
		player->planey = 0.66;
	}
	else if (player->dir == 'S')
	{
		player->dirx = 1;
		player->planey = -0.66;
	}
	else if (player->dir == 'W')
	{
		player->diry = -1;
		player->planex = -0.66;
	}
	else
	{
		player->diry = 1;
		player->planex = 0.66;
	}
}
