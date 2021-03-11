/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:01:36 by framdani          #+#    #+#             */
/*   Updated: 2021/02/13 15:01:39 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_side_step(t_player *player, t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidex = (player->posx - ray->map_x) * ray->deltax;
	}
	else
	{
		ray->stepx = 1;
		ray->sidex = (ray->map_x + 1.0 - player->posx) * ray->deltax;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidey = (player->posy - ray->map_y) * ray->deltay;
	}
	else
	{
		ray->stepy = 1;
		ray->sidey = (ray->map_y + 1.0 - player->posy) * ray->deltay;
	}
}

void	get_delta_dist(t_ray *ray)
{
	if (ray->diry == 0)
		ray->deltax = 0;
	else
	{
		if (ray->dirx == 0)
			ray->deltax = 1;
		else
			ray->deltax = fabs(1 / ray->dirx);
	}
	if (ray->dirx == 0)
		ray->deltay = 0;
	else
	{
		if (ray->diry == 0)
			ray->deltay = 1;
		else
			ray->deltay = fabs(1 / ray->diry);
	}
}

void	get_ray_dir(t_game *game, int x)
{
	double		camera_x;
	t_player	*player;
	t_ray		*ray;

	player = &game->player;
	ray = &game->ray;
	camera_x = 2 * x / (double)game->width - 1;
	ray->dirx = player->dirx + player->planex * camera_x;
	ray->diry = player->diry + player->planey * camera_x;
}

void	get_ray(t_game *game, int x)
{
	t_ray	*ray;

	ray = &game->ray;
	get_ray_dir(game, x);
	ray->map_x = (int)game->player.posx;
	ray->map_y = (int)game->player.posy;
	get_delta_dist(ray);
	get_side_step(&game->player, ray);
}
