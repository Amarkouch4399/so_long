#include "../includes/so_long.h"

int	ft_load_textures(t_map *game, void *mlx)
{
	int img_width;
	int img_height;

	game->wall_image = mlx_xpm_file_to_image(mlx, 
			"textures/red.xpm", &img_width, &img_height);
	game->floor_image = mlx_xpm_file_to_image(mlx, 
                        "textures/red.xpm", &img_width, &img_height);
	game->player_image = mlx_xpm_file_to_image(mlx, 
			"textures/red.xpm", &img_width, &img_height);
	game->collectable_image = mlx_xpm_file_to_image(mlx, 
			"textures/coins.xpm", &img_width, &img_height);
	game->exit_image = mlx_xpm_file_to_image(mlx, 
			"textures/red.xpm", &img_width, &img_height);
	if (!game->floor_image)
	{
		ft_printf("Failed floor image\n");
		return (0);
	}
    /*if (!game->img_wall || !game->img_floor || !game->img_player 
        || !game->img_collectable || !game->img_exit)
        return (0);*/
    return (1);
}
