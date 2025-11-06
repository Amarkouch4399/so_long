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

void	ft_length(int fd, t_map *map)
{
	int	length;
	int	width;
	char	*line;
	length = 0;
	width = 0;

	line = get_next_line(fd);
	if (!line)
	{
		map->width = 0;
		map->length = 0;
		return ;
	}
	while (line[width] && line[width] != '\n')
		width++;
	while (line)
	{
		length++;
		printf("%s", line);	
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map->width = width;
	map->length = length;
	close(fd);
}

