/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 18:14:16 by framdani          #+#    #+#             */
/*   Updated: 2021/03/03 16:34:31 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		check_extension(char *arg)
{
	int i;

	i = ft_strlen(arg) - 4;
	if (ft_strcmp(arg + i, ".cub") != 0)
		ft_errors("config file should have the extension .cub");
}

void		check_save(char *arg, t_game *game)
{
	if (ft_strcmp(arg, "--save") != 0)
		ft_errors("The second arguments isn't --save");
	game->save = 1;
}
