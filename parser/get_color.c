/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:37:00 by framdani          #+#    #+#             */
/*   Updated: 2021/01/19 10:37:03 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	comma(char *str, t_game *game)
{
	int i;
	int cmpt;

	i = 0;
	cmpt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			cmpt++;
		i++;
	}
	if (cmpt != 2)
		get_errors("Invalid input for colors", game);
}

int		create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	check_color(char *rgb, t_game *game)
{
	int			j;
	long long	c;

	j = 0;
	while (rgb[j] == ' ' || rgb[j] == '\t')
		j++;
	if (!(ft_isdigit(rgb[j])))
		get_errors("Invalid input for colors", game);
	while (rgb[j] != '\0' && ft_isdigit(rgb[j]))
		j++;
	while (rgb[j] == ' ' || rgb[j] == '\t')
		j++;
	if (rgb[j] != '\0')
		get_errors("Invalid input for colors", game);
	c = ft_atoi(rgb);
	if (c > 255 || c < 0)
		get_errors("Invalid input for colors", game);
}

void	check_dup_color(char c, t_game *game)
{
	if ((c == 'F' && game->f != -1) || (c == 'C' && game->c != -1))
		get_errors("Duplicate input for color", game);
}

void	get_color(char *str, t_game *game)
{
	char	**rgb;
	int		cmpt;

	cmpt = 0;
	check_dup_color(str[0], game);
	comma(str, game);
	if (str[1] != ' ' && str[1] != '\t')
		get_errors("Invalid input for colors", game);
	rgb = ft_split(str + 1, ',');
	while (rgb[cmpt])
		cmpt++;
	if (cmpt != 3)
		get_errors("Invalid input for colors", game);
	cmpt = 0;
	while (rgb[cmpt])
	{
		check_color(rgb[cmpt], game);
		cmpt++;
	}
	if (str[0] == 'F')
		game->f = create_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	else if (str[0] == 'C')
		game->c = create_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	clear_memory(rgb);
	game->elements++;
}
