/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:10:00 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/11 12:10:00 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_read_map(int fd, t_map map)
{
	char	*line;
	char	**tab_map;
	int		i;
	int		length;

	if (fd < 0)
		return (NULL);
	length = map.length;
	tab_map = malloc(sizeof(char *) * (length + 1));
	if (!tab_map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_trim_newline(line);
		tab_map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	tab_map[i] = NULL;
	close(fd);
	return (tab_map);
}
