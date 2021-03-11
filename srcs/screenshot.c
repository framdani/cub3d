/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:00:25 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:21:40 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_header(int w, int h, int bpp, int fd)
{
	char	*str;
	int		offset;
	int		file_size;
	int		header_size;
	int		planes;

	offset = 54;
	file_size = 54 + 4 * w * h;
	header_size = 40;
	planes = 1;
	str = ft_calloc(54, 1);
	ft_memcpy(str, "BM", 2);
	ft_memcpy(str + 2, &file_size, 4);
	ft_memcpy(str + 10, &offset, 4);
	ft_memcpy(str + 14, &header_size, 4);
	ft_memcpy(str + 18, &w, 4);
	ft_memcpy(str + 22, &h, 4);
	ft_memcpy(str + 26, &planes, 2);
	ft_memcpy(str + 28, &bpp, 2);
	write(fd, str, 54);
	free(str);
}

void	write_data(t_game *game, int fd)
{
	int		x;
	int		y;

	y = game->height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->width)
		{
			write(fd, &game->mlx.add[y * game->mlx.line_length / 4 + x], 4);
			x++;
		}
		y--;
	}
}

void	screenshot(t_game *game)
{
	int fd;

	if (game->height <= 64 || game->width <= 64)
		get_errors("Invalid screenshot resolution", game);
	fd = open("image.bmp", O_CREAT | O_RDWR);
	set_header(game->width, game->height, game->mlx.bpp, fd);
	write_data(game, fd);
	exit(1);
}
