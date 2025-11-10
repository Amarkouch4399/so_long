#include "../includes/so_long.h"

void	ft_render_map(t_map *game, void *mlx_ptr, void *window)
{
	int	x;
	int	y;

	y = 0;
	if (!mlx_ptr || !window || !game->floor_image)
	{
		ft_printf("Error: NULL pointer in render\n");
		return;
	}
	while(y < game->length)
	{
		x = 0;
		while(x < game->width)
		{
			if (game->floor_image)
				mlx_put_image_to_window(mlx_ptr, window, 
					game->floor_image, x * 64, y * 64);
			if (game->tab[y][x] == '1' && game->wall_image)
				mlx_put_image_to_window(mlx_ptr, window, 
					game->wall_image, x * 64, y * 64);
			else if (game->tab[y][x] == 'P' && game->player_image)
				mlx_put_image_to_window(mlx_ptr, window, 
					game->player_image, x * 64, y * 64);
			else if (game->tab[y][x] == 'C' && game->collectable_image)
				mlx_put_image_to_window(mlx_ptr, window, 
					game->collectable_image, x * 64, y * 64);
			else if (game->tab[y][x] == 'E' && game->exit_image)
				mlx_put_image_to_window(mlx_ptr, window, 
					game->exit_image, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
