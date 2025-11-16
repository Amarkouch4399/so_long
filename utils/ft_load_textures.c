/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:21:00 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/11 12:21:00 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_load_textures(t_map *game, void *mlx)
{
	int	img_width;
	int	img_height;

	game->wall_image = mlx_xpm_file_to_image(
			mlx, "textures/wall.xpm", &img_width, &img_height);
	game->floor_image = mlx_xpm_file_to_image(
			mlx, "textures/floor.xpm", &img_width, &img_height);
	game->player_image = mlx_xpm_file_to_image(
			mlx, "textures/player.xpm", &img_width, &img_height);
	game->collectable_image = mlx_xpm_file_to_image(
			mlx, "textures/coins.xpm", &img_width, &img_height);
	game->exit_image = mlx_xpm_file_to_image(
			mlx, "textures/exit.xpm", &img_width, &img_height);
	if (!game->floor_image)
	{
		ft_printf("Failed floor image\n");
		return (0);
	}
	return (1);
}
