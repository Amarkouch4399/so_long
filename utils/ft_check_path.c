/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                  :+:      :+:    :+:     */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:00:00 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/11 12:00:00 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_flood_fill(char **map, int x, int y, t_map *game)
{
	if (x < 0 || x >= game->width || y < 0 || y >= game->length)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	ft_flood_fill(map, x + 1, y, game);
	ft_flood_fill(map, x - 1, y, game);
	ft_flood_fill(map, x, y + 1, game);
	ft_flood_fill(map, x, y - 1, game);
}

static char	**ft_copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static int	ft_check_unreachable(char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_path(t_map *game)
{
	char	**map_copy;

	map_copy = ft_copy_map(game->tab);
	if (!map_copy)
		return (0);
	ft_flood_fill(map_copy, game->player_x, game->player_y, game);
	if (ft_check_unreachable(map_copy) == 0)
	{
		ft_free_tab(map_copy);
		return (0);
	}
	ft_free_tab(map_copy);
	return (1);
}
