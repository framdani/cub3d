/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:59:51 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:17:42 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_texture(char *str, t_game *game, int i)
{
	t_tex_paths		*texture;

	texture = &game->texture;
	if (str[i] != ' ' && str[i] != '\t')
		get_errors("Invalid input : texture", game);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		get_errors("Invalid input : texture", game);
	if (str[0] == 'N')
		texture->no = ft_strdup(&str[i]);
	else if (str[0] == 'E')
		texture->ea = ft_strdup(&str[i]);
	else if (str[0] == 'W')
		texture->we = ft_strdup(&str[i]);
	else if (str[0] == 'S' && str[1] == 'O')
		texture->so = ft_strdup(&str[i]);
	else
		texture->sp = ft_strdup(&str[i]);
}

void	get_texture(char *str, t_game *game)
{
	t_tex_paths		*texture;

	texture = &game->texture;
	if (ft_strncmp(str, "NO", 2) == 0 && !(texture->no))
		check_texture(str, game, 2);
	else if (ft_strncmp(str, "EA", 2) == 0 && !(texture->ea))
		check_texture(str, game, 2);
	else if (ft_strncmp(str, "WE", 2) == 0 && !(texture->we))
		check_texture(str, game, 2);
	else if (ft_strncmp(str, "SO", 2) == 0 && !(texture->so))
		check_texture(str, game, 2);
	else if (ft_strncmp(str, "S ", 2) == 0 && !(texture->sp))
		check_texture(str, game, 1);
	else
		get_errors("Invalid input texture", game);
	game->elements++;
}
