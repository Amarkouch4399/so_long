/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:12:00 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/11 12:12:00 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_read_and_validate(const char *path, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	ft_length(fd, map);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	map->tab = ft_read_map(fd, *map);
	close(fd);
	if (!map->tab)
		return (1);
	if (ft_validate_format(map) != 0)
		return (1);
	return (0);
}

int	ft_init_graphics(t_map *map, void **mlx_ptr, void **window)
{
	*mlx_ptr = mlx_init();
	if (!*mlx_ptr)
		return (1);
	if (!ft_load_textures(map, *mlx_ptr))
		return (1);
	*window = mlx_new_window(
			*mlx_ptr,
			map->width * 64,
			map->length * 64,
			"so_long");
	if (!*window)
	{
		ft_printf("Error\nFailed to create window\n");
		return (1);
	}
	return (0);
}
