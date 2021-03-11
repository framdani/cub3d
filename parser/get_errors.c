/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 18:21:21 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:16:24 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <string.h>

void	clear_memory(char **str)
{
	int j;

	j = 0;
	while (str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}

void	get_errors(char *str, t_game *game)
{
	int i;

	i = 0;
	if (game->map != NULL)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	ft_errors(str);
}

void	ft_errors(char *str)
{
	write(1, "ERROR\n", 6);
	write(1, str, strlen(str));
	exit(1);
}

void	ft_error_free(char *str, char **mem)
{
	ft_errors(str);
	clear_memory(mem);
	exit(1);
}
