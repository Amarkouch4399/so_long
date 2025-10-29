/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:40:11 by ouamarko          #+#    #+#             */
/*   Updated: 2025/10/29 17:02:56 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../gnl/get_next_line.h"
#include <stdlib.h>

typedef struct	s_map
{
	char	**tab;
	int	width;
	int	lenght;
	int	player_x;
	int	player_y;
}	t_map;

int	close_window(void *param);
char	*ft_strstr(const char *big, const char *little);
void	ft_lenght(int fd, t_map *map);
#endif

