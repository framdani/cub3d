/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_resolution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:53:41 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:17:08 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		normalize_resolution(t_game *game, long long w, long long h)
{
	if (w > MAX_INT || h > MAX_INT)
		get_errors("Enter a resolution under MAX_INT", game);
	if (w > 2560 && w <= MAX_INT)
		game->width = 2560;
	else if (w < MAX_INT)
		game->width = (int)w;
	if (h > 1440 && h <= MAX_INT)
		game->height = 1440;
	else if (h < MAX_INT)
		game->height = (int)h;
}

void		check_duplicate(t_game *game)
{
	game->elements++;
	if (game->width != -1)
		get_errors("Duplicate value for resolution", game);
}

void		get_resolution(char *str, t_game *game)
{
	int			i;
	long long	width;
	long long	height;

	i = 1;
	check_duplicate(game);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] < '0' || str[i] > '9' || (ft_atoi(&(str[i])) < 0))
		get_errors(" Invalid resolution", game);
	width = ft_atoi(&str[i]);
	i = i + len_num(ft_atoi(&str[i])) + 1;
	if (str[i] != ' ' && str[i] != '\t')
		get_errors(" Invalid resolution", game);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] < '0' || str[i] > '9' || (ft_atoi(&(str[i])) < 0))
		get_errors(" Invalid resolution", game);
	height = ft_atoi(&str[i]);
	i = i + len_num(height) + 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] != '\0')
		get_errors(" Invalid resolution", game);
	normalize_resolution(game, width, height);
}
