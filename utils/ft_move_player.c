/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:00:00 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/11 12:00:00 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_handle_exit(t_map *map)
{
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
	ft_printf("You reached the exit!\n");
	close_window(map);
}

static int	ft_process_exit(t_map *map, int x, int y)
{
	if (map->tab[y][x] != 'E')
		return (0);
	if (map->collectibles == 0)
	{
		ft_handle_exit(map);
		return (1);
	}
	ft_printf("Collect all collectibles before exiting!\n");
	return (-1);
}

static void	ft_process_collectible(t_map *map, int x, int y)
{
	if (map->tab[y][x] != 'C')
		return ;
	map->tab[y][x] = '0';
	if (map->collectibles > 0)
		map->collectibles--;
	ft_printf("Collectible collected!\n");
	if (map->collectibles == 0)
		ft_printf("All collectibles collected!\n");
}

static void	ft_apply_move(t_map *map, int new_x, int new_y)
{
	map->tab[map->player_y][map->player_x] = '0';
	map->tab[new_y][new_x] = 'P';
	map->player_x = new_x;
	map->player_y = new_y;
	map->moves++;
	ft_printf("Moves: %d\n", map->moves);
	ft_render_map(map, map->mlx_ptr, map->window);
}

int	ft_move_player(t_map *map, int dx, int dy)
{
	int	new_x;
	int	new_y;
	int	exit_state;

	if (!map || !map->tab)
		return (0);
	new_x = map->player_x + dx;
	new_y = map->player_y + dy;
	if (new_x < 0 || new_x >= map->width || new_y < 0 || new_y >= map->length)
		return (0);
	if (map->tab[new_y][new_x] == '1')
		return (0);
	exit_state = ft_process_exit(map, new_x, new_y);
	if (exit_state == 1)
		return (1);
	if (exit_state == -1)
		return (0);
	ft_process_collectible(map, new_x, new_y);
	ft_apply_move(map, new_x, new_y);
	return (1);
}
