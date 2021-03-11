/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:16:35 by framdani          #+#    #+#             */
/*   Updated: 2021/03/04 19:22:35 by framdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		init_textures(t_game *game)
{
	game->textures[0].img = NULL;
	game->textures[1].img = NULL;
	game->textures[2].img = NULL;
	game->textures[3].img = NULL;
	game->textures[4].img = NULL;
}

t_data		generate_texture(t_game *game, char *path)
{
	t_data	tex_data;
	char	*new_path;
	int		i;

	i = 0;
	new_path = malloc(ft_strlen(path) + 1);
	while (path[i] != '\0' && path[i] != 32 && path[i] != '\t')
	{
		new_path[i] = path[i];
		i++;
	}
	new_path[i] = '\0';
	tex_data.img = mlx_xpm_file_to_image(game->mlx_ptr, new_path,
			&tex_data.width, &tex_data.height);
	free(path);
	free(new_path);
	if (tex_data.img == NULL || tex_data.width != 64 || tex_data.height != 64)
		get_errors(" Invalid texture", game);
	tex_data.add = (int *)mlx_get_data_addr(tex_data.img, &tex_data.bpp,
			&tex_data.line_length, &tex_data.endian);
	return (tex_data);
}

void		upload_textures(t_game *game)
{
	init_textures(game);
	game->textures[0] = generate_texture(game, game->texture.no);
	game->textures[1] = generate_texture(game, game->texture.we);
	game->textures[2] = generate_texture(game, game->texture.so);
	game->textures[3] = generate_texture(game, game->texture.ea);
	game->textures[4] = generate_texture(game, game->texture.sp);
}

t_game		create_new_game(int argc, char **argv)
{
	t_game game;

	game = init_game();
	game.player = init_player();
	game.texture = init_texture();
	check_extension(argv[1]);
	if (argc == 3)
		check_save(argv[2], &game);
	return (game);
}
