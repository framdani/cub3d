/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:36:51 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:21:23 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	choice_parsing(char *line, t_game *game)
{
	if (game->elements == 8)
		get_map(line, game);
	else if (line[0] == 'R' && (line[1] == 32 || line[1] == '\t'))
		get_resolution(line, game);
	else if (line[0] == 'F' || line[0] == 'C')
		get_color(line, game);
	else if (line[0] == 'W' || line[0] == 'E' || line[0] == 'N' ||
		line[0] == 'S')
		get_texture(line, game);
	else
	{
		free(line);
		get_errors("Config file isn't in the correct format", game)	;
	}
}

void	read_cfg_file(int fd, t_game *game)
{
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\0')
			choice_parsing(line, game);
		else if (line[0] == '\0' && game->mapdetected == 1)
		{
			free(line);
			get_errors("Empty line(s) inside or at the end of the map", game);
		}
		free(line);
	}
	free(line);
	check_map(game);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc < 2 || argc > 3)
		ft_errors("Invalid number of arguments");
	game = create_new_game(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_errors(" Enter a valid path !");
	read_cfg_file(fd, &game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.width, game.height,
			"Game");
	game.mlx.img = mlx_new_image(game.mlx_ptr, game.width, game.height);
	game.mlx.add = (int *)mlx_get_data_addr(game.mlx.img, &game.mlx.bpp,
			&game.mlx.line_length, &game.mlx.endian);
	get_player_dir(&game.player);
	upload_textures(&game);
	start_drawing(&game);
	if (game.save == 1)
		screenshot(&game);
	mlx_hook(game.win_ptr, 02, 0, key_press, &game);
	mlx_hook(game.win_ptr, 17, 0, red_cross, &game);
	mlx_loop(game.mlx_ptr);
}
