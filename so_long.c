/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:40:49 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/05 13:44:20 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	close_window(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (map)
	{
		if (map->window && map->mlx_ptr)
			mlx_destroy_window(map->mlx_ptr, map->window);
		if (map->mlx_ptr)
		{
			mlx_destroy_display(map->mlx_ptr);
			free(map->mlx_ptr);
			map->mlx_ptr = NULL;
		}
		if (map->tab)
		{
			ft_free_tab(map->tab);
			map->tab = NULL;
		}
	}
	exit(0);
}

int	ft_handle_key(int keycode, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (!map)
		return (0);
	if (keycode == 65307)
		close_window(map);
	else if (keycode == 119 || keycode == 87)
		ft_move_player(map, 0, -1);
	else if (keycode == 115 || keycode == 83)
		ft_move_player(map, 0, 1);
	else if (keycode == 97 || keycode == 65)
		ft_move_player(map, -1, 0);
	else if (keycode == 100 || keycode == 68)
		ft_move_player(map, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	void	*mlx_ptr;
	void	*window;

	if (argc != 2 || !ft_strstr(argv[1], ".ber"))
	{
		ft_printf("Error\nInvalid arguments\n");
		return (1);
	}
	if (ft_read_and_validate(argv[1], &map) != 0)
		return (1);
	if (ft_init_graphics(&map, &mlx_ptr, &window) != 0)
	{
		ft_free_tab(map.tab);
		return (1);
	}
	map.moves = 0;
	map.mlx_ptr = mlx_ptr;
	map.window = window;
	ft_render_map(&map, mlx_ptr, window);
	mlx_key_hook(window, ft_handle_key, &map);
	mlx_hook(window, 17, 0, close_window, &map);
	mlx_loop(mlx_ptr);
	return (0);
}
