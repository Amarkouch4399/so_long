/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:23:27 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/04 19:24:03 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(t_map *map, int lines)
{
	int	i;

	if (!map || !map->tab)
		return ;
	i = 0;
	while (i < lines)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	map->tab = NULL;
}
