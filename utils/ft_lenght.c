/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenght.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:15:11 by ouamarko          #+#    #+#             */
/*   Updated: 2025/10/29 16:46:37 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_lenght(int fd, t_map *map)
{
	int	lenght;
	int	width;
	char	*line;
	lenght = 0;
	width = 0;

	line = get_next_line(fd);
	if (!line)
	{
		map->width = 0;
		map->lenght = 0;
		return ;
	}
	while (line[width] && line[width] != '\n')
		width++;
	while (line)
	{
		lenght++;
		printf("%s", line);	
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->width = width;
	map->lenght = lenght;
	close(fd);
}

