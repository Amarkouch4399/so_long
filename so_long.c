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
#include <string.h>

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

char	**ft_read_map(int fd, t_map map)
{
	char	*line;
	char	**tab_map;
	int	i;
	int	length;

	if (fd < 0)
		return (NULL);
	length = map.length;
	tab_map = malloc(sizeof(char *) * (length + 1));
	if (!tab_map)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		ft_trim_newline(line);
		tab_map[i] = line;
		i++;
	}
	tab_map[i] = NULL;
	close(fd);
	return (tab_map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	//void	*mlx_ptr;
	//void	*window;
	int	fd;

	if (argc != 2 || ft_strstr(argv[1], ".ber") == NULL)
	{
		write(2,"Error arguments", 14);
		return 0;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	ft_length(fd, &map);
	close(fd);
	printf("%d\n", map.width);
	printf("%d\n", map.length);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);
	map.tab = ft_read_map(fd, map);
	ft_validate_format(&map);
	ft_printf("=== MAP ===\n");
    	int	i = 0;
    	while (i < map.length)
    	{
        	if (map.tab[i])
            	printf("%s\n", map.tab[i]);
        	i++;
    	}
	/*
	int	i = 0;
	 while (map.tab[i])
	{
		printf("%s\n", map.tab[i]);
		i++;
	}
	*/
	/*mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	window = mlx_new_window(mlx_ptr, 800, 720, "Fdf");
	mlx_hook(window, 17, 0, close_window, NULL);
	mlx_loop(mlx_ptr);
	return (0);
	*/
}
