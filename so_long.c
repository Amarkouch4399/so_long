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

int ft_parsemap(int fd, t_map *map)
{
    char    *line;
    int     i;
    
    map->tab = malloc(sizeof(char *) * (map->lenght + 1));
    if (!map->tab)
        return (0);
    i = 0;
    while (i < map->lenght)
    {
        line = get_next_line(fd);
        if (!line)
        {
            ft_free_map(map, i);
            close(fd);
            return (0);
        } 
        map->tab[i] = malloc(sizeof(char) * (map->width + 1));
        if (!map->tab[i])
        {
            free(line);
            ft_free_map(map, i);
            close(fd);
            return (0);
        }
        strncpy(map->tab[i], line, map->width);
        map->tab[i][map->width] = '\0';
        free(line);
        i++;
    }
        while ((line = get_next_line(fd)))
		free(line); 
    //map->tab[i] = NULL;
    close(fd);
    return (1);
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
	ft_lenght(fd, &map);
	printf("%d\n", map.width);
	printf("%d\n", map.lenght);
	if (fd < 0)
		return (perror("open"), 1);
	ft_parsemap(fd, &map);
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
