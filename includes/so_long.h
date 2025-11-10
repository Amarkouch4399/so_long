/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:40:11 by ouamarko          #+#    #+#             */
/*   Updated: 2025/11/04 19:24:45 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../gnl/get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include "../ft_printf/ft_printf.h"

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_map
{
	char	**tab;
	int	width;
	int	length;
	int	player_x;
	int	player_y;

	void	*wall_image;
	void	*floor_image;
	void	*player_image;
	void	*collectable_image;
	void	*exit_image;
}	t_map;

int		close_window(void *param);
char	*ft_strstr(const char *big, const char *little);
void	ft_length(int fd, t_map *map);
void    ft_free_map(t_map *map, int lines);
int		ft_validate_format(t_map *map);
size_t	ft_strlen(const char *s);
void	ft_trim_newline(char *str);
int		ft_check_path(t_map *game);
void	ft_free_tab(char **tab);
int	ft_load_textures(t_map *game, void *mlx_ptr);
void	ft_render_map(t_map *game, void *mlx_ptr, void *window);

#endif
