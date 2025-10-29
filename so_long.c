/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:40:49 by ouamarko          #+#    #+#             */
/*   Updated: 2025/10/29 16:48:13 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}
/*
int	ft_parsemap(char argv, t_map map)
{


}
*/
int	main(int argc, char **argv)
{
	t_map	map;
	void	*mlx_ptr;
	void	*window;
	int	fd;

	if (argc != 2 || ft_strstr(argv[1], ".ber") == NULL)
	{
		write(2,"Error arguments", 14);
		return 0;
	}
	fd = open(argv[1], O_RDONLY);
	ft_lenght(fd, &map);
	printf("%d\n", map.width);
	printf("%d", map.lenght);
	if (fd < 0)
		return (perror("open"), 1);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (0);
	window = mlx_new_window(mlx_ptr, 800, 720, "Fdf");
	mlx_hook(window, 17, 0, close_window, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
