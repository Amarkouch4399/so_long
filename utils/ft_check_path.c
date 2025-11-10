#include "../includes/so_long.h"

void ft_flood_fill(char **map, int x, int y)
{
    if (map[y][x] == '1' || map[y][x] == 'F')
        return;
    map[y][x] = 'F';
    
    ft_flood_fill(map, x + 1, y);
    ft_flood_fill(map, x - 1, y);
    ft_flood_fill(map, x, y + 1);
    ft_flood_fill(map, x, y - 1);
}

char **ft_copy_map(char **map)
{
    char    **copy;
    int     i;

    i = 0;
    while (map[i])
        i++;
    copy = malloc(sizeof(char *) * (i + 1));
    if (!copy)
        return (NULL);
    i = 0;
    while (map[i])
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[i] = NULL;
    
    return (copy);
}

int ft_check_path(t_map *game)
{
    char    **map_copy;
    int     i, j;
    
    map_copy = ft_copy_map(game->tab);
    ft_flood_fill(map_copy, game->player_x, game->player_y);
    i = 0;
    while (map_copy[i])
    {
        j = 0;
        while (map_copy[i][j])
        {
            if (map_copy[i][j] == 'C' || map_copy[i][j] == 'E')
            {
                ft_free_tab(map_copy);
                return (0);
            }
            j++;
        }
        i++;
    }
    ft_free_tab(map_copy);
    return (1);
}