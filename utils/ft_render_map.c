/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:20:00 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/11 12:20:00 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_put_image(t_map *game, int x, int y)
{
	if (game->floor_image)
		mlx_put_image_to_window(
			game->mlx_ptr, game->window, game->floor_image, x * 64, y * 64);
	if (game->tab[y][x] == '1' && game->wall_image)
		mlx_put_image_to_window(
			game->mlx_ptr, game->window, game->wall_image, x * 64, y * 64);
	else if (game->tab[y][x] == 'P' && game->player_image)
		mlx_put_image_to_window(
			game->mlx_ptr, game->window, game->player_image, x * 64, y * 64);
	else if (game->tab[y][x] == 'C' && game->collectable_image)
		mlx_put_image_to_window(
			game->mlx_ptr, game->window,
			game->collectable_image, x * 64, y * 64);
	else if (game->tab[y][x] == 'E' && game->exit_image)
		mlx_put_image_to_window(
			game->mlx_ptr, game->window, game->exit_image, x * 64, y * 64);
}

void	ft_render_map(t_map *game, void *mlx_ptr, void *window)
{
	int	x;
	int	y;

	y = 0;
	if (!mlx_ptr || !window || !game->floor_image)
	{
		ft_printf("Error: NULL pointer in render\n");
		return ;
	}
	while (y < game->length)
	{
		x = 0;
		while (x < game->width)
		{
			ft_put_image(game, x, y);
			x++;
		}
		y++;
	}
}
