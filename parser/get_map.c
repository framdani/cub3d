/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:36:04 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:16:42 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_direction(char c)
{
	int i;

	i = 0;
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		is_valid(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
				&& str[i] != 'N' && str[i] != 'S' && str[i] != 'W' &&
				str[i] != 'E' && str[i] != 32 && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int		is_sprite(char c)
{
	if (c == '2')
		return (1);
	return (0);
}

void	get_sprite_position(t_game *game, int i, int j)
{
	game->sprite_place[game->num_sprites].x = i + 0.5;
	game->sprite_place[game->num_sprites].y = j + 0.5;
	game->num_sprites++;
}

void	get_map(char *str, t_game *game)
{
	int		j;
	char	*buf;

	game->mapdetected = 1;
	if (is_valid(str) != 1)
		get_errors("Invalid character(s) in the map", game);
	j = 0;
	while (str[j] != '\0')
	{
		if (is_direction(str[j]))
			game->player.nbr++;
		if (is_sprite(str[j]))
			get_sprite_position(game, game->map_height, j);
		j++;
	}
	if (game->map_width < (int)ft_strlen(str))
		game->map_width = (int)ft_strlen(str);
	game->map_height++;
	buf = game->buffer;
	game->buffer = ft_strjoin(game->buffer, str);
	free(buf);
	buf = game->buffer;
	game->buffer = ft_strjoin(game->buffer, "\n");
	free(buf);
}
