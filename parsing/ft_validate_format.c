/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:17:00 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/05 20:17:00 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_check_rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (map->tab[i])
	{
		if ((int)ft_strlen(map->tab[i]) != map->width)
		{
			ft_printf("Error\nMap is not rectangular.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_horizontal_walls(t_map *map)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		if (map->tab[0][j] != '1' || map->tab[map->length - 1][j] != '1')
		{
			ft_printf("Error\nMap is not surrounded by walls.\n");
			return (1);
		}
		j++;
	}
	return (0);
}

static int	ft_check_vertical_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->length)
	{
		if (map->tab[i][0] != '1' || map->tab[i][map->width - 1] != '1')
		{
			ft_printf("Error\nMap is not surrounded by walls.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_walls(t_map *map)
{
	if (ft_check_horizontal_walls(map) != 0)
		return (1);
	if (ft_check_vertical_walls(map) != 0)
		return (1);
	return (0);
}

static void	init_counts(int *p_count, int *e_count, int *c_count)
{
	*p_count = 0;
	*e_count = 0;
	*c_count = 0;
}

static int	process_char(t_map *map, int i, int j, int *counts)
{
	if (map->tab[i][j] == 'P')
	{
		counts[0]++;
		map->player_x = j;
		map->player_y = i;
	}
	else if (map->tab[i][j] == 'E')
		counts[1]++;
	else if (map->tab[i][j] == 'C')
		counts[2]++;
	else if (map->tab[i][j] != '0' && map->tab[i][j] != '1')
	{
		ft_printf("Error\nInvalid character in map: %c\n", map->tab[i][j]);
		return (1);
	}
	return (0);
}

static int	validate_counts(int *counts)
{
	if (counts[0] != 1)
	{
		ft_printf("Error\nMap must contain exactly one player 'P'.\n");
		return (1);
	}
	if (counts[1] != 1)
	{
		ft_printf("Error\nMap must contain exactly one exit 'E'.\n");
		return (1);
	}
	if (counts[2] == 0)
	{
		ft_printf("Error\nMap must contain at least one collectible 'C'.\n");
		return (1);
	}
	return (0);
}

static int	ft_check_characters_and_counts(t_map *map)
{
	int	i;
	int	j;
	int	counts[3]; // counts[0]=P, counts[1]=E, counts[2]=C

	init_counts(&counts[0], &counts[1], &counts[2]);
	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			if (process_char(map, i, j, counts) != 0)
				return (1);
			j++;
		}
		i++;
	}
	if (validate_counts(counts) != 0)
		return (1);
	map->collectibles = counts[2];
	return (0);
}

int	ft_validate_format(t_map *map)
{
	if (ft_check_rectangular(map) != 0)
		return (1);
	if (ft_check_walls(map) != 0)
		return (1);
	if (ft_check_characters_and_counts(map) != 0)
		return (1);
	if (ft_check_path(map) == 0)
	{
		ft_printf("Error\nAll collectibles and exit are not reachable.\n");
		return (1);
	}
	return (0);
}
