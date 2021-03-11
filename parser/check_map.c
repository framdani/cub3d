/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:47:25 by framdani          #+#    #+#             */
/*   Updated: 2021/01/22 17:47:38 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	verify_boundaries(t_game *game, char **map, int w, int h)
{
	int j;

	j = 0;
	while (j < w)
	{
		if (map[0][j] == '0' || map[h - 1][j] == '0' ||
				map[0][j] == '2' || map[h - 1][j] == '2' ||
				is_direction(map[0][j]) || is_direction(map[h - 1][j]))
			get_errors("Map not closed", game);
		j++;
	}
	j = 0;
	while (j < h)
	{
		if (map[j][0] == '0' || map[j][w - 1] == '0' ||
				map[j][0] == '2' || map[j][w - 1] == '2' ||
				is_direction(map[j][0]) || is_direction(map[j][w - 1]))
			get_errors("Map not closed", game);
		j++;
	}
}

void	is_closed(t_game *game)
{
	int j;
	int i;

	verify_boundaries(game, game->map, game->map_width, game->map_height);
	i = 1;
	j = 1;
	while (i < game->map_height)
	{
		j = 1;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '2' || game->map[i][j] == '0')
			{
				if (game->map[i][j - 1] == 32 || game->map[i][j + 1] == 32 ||
						game->map[i - 1][j] == 32 || game->map[i + 1][j] == 32)
					get_errors("Map not closed", game);
			}
			j++;
		}
		i++;
	}
}

void	check_player(t_game *game, int i, char dir, int j)
{
	game->player.posx = i + 0.5;
	game->player.posy = j + 0.5;
	game->player.dir = dir;
	game->map[i][j] = '0';
}

void	fill(t_game *game, int i, char *src)
{
	int j;
	int l;

	j = 0;
	l = ft_strlen(src);
	while (j < l)
	{
		if (is_direction(src[j]))
			check_player(game, i, src[j], j);
		else
			game->map[i][j] = src[j];
		j++;
	}
	while (j < game->map_width)
	{
		game->map[i][j] = 32;
		j++;
	}
	game->map[i][j] = 0;
}

void	check_map(t_game *game)
{
	int		i;
	char	**split_map;

	i = 0;
	if (game->map_width < 3 || game->map_height < 3)
		get_errors("It has to be at least 3  lines/columns to have a valid map",
				game);
	if (game->player.nbr != 1)
		get_errors("there is no/multiple player(s)", game);
	split_map = ft_split(game->buffer, '\n');
	free(game->buffer);
	if (!(game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1))))
		get_errors("Can't allocate memory for the map", game);
	while (i < game->map_height)
	{
		if (!(game->map[i] = (char *)malloc(sizeof(char) *
						(game->map_width + 1))))
			get_errors("Can't allocate memory for the map", game);
		fill(game, i, split_map[i]);
		i++;
	}
	clear_memory(split_map);
	game->map[i] = 0;
	is_closed(game);
}
