/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:06:16 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/15 16:59:19 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_alloc_sizes(t_mlx *mlx)
{
	mlx->width_player = malloc(sizeof(int));
	mlx->height_player = malloc(sizeof(int));
	mlx->width_wall = malloc(sizeof(int));
	mlx->height_wall = malloc(sizeof(int));
	mlx->width_collectible = malloc(sizeof(int));
	mlx->height_collectible = malloc(sizeof(int));
	mlx->width_empty = malloc(sizeof(int));
	mlx->height_empty = malloc(sizeof(int));
	mlx->width_exit = malloc(sizeof(int));
	mlx->height_exit = malloc(sizeof(int));
	if (!mlx->width_player || !mlx->height_player || !mlx->width_wall \
	|| !mlx->height_wall || !mlx->width_collectible || !mlx->height_collectible \
	|| !mlx->width_empty || !mlx->height_empty || !mlx->width_exit || \
	!mlx->height_exit)
		ft_error("failed to allocate memory for width/height pointers");

}
void	ft_load_textures(t_mlx *mlx)
{
	ft_alloc_sizes(mlx);
	mlx->player = mlx_xpm_file_to_image(mlx, PLAYER, \
	mlx->width_player, mlx->height_player);
	if (mlx->player == NULL)
		ft_error("failed to load texture");
	mlx->wall = mlx_xpm_file_to_image(mlx, WALL, \
	mlx->width_wall, mlx->height_wall);
	if (mlx->wall == NULL)
		ft_error("failed to load texture");
	mlx->collectible = mlx_xpm_file_to_image(mlx, \
	COLLEC, mlx->width_collectible, mlx->height_collectible);
	if (mlx->collectible == NULL)
		ft_error("failed to load texture");
	mlx->empty = mlx_xpm_file_to_image(mlx, EMPTY, \
	mlx->width_empty, mlx->height_empty);
	if (mlx->empty == NULL)
		ft_error("failed to load texture");
	mlx->exit = mlx_xpm_file_to_image(mlx, EXIT, \
	mlx->width_exit, mlx->height_exit);
	if (mlx->exit == NULL)
		ft_error("failed to load texture");
}

void	ft_render_image(char c, t_mlx *mlx, int x, int y)
{
	int	render;

	render = 0;
	if (c == 'P')
		render = mlx_put_image_to_window(mlx->mlx, mlx->win,\
		mlx->player, x * TILE, y * TILE);
	else if (c == '1')
		render = mlx_put_image_to_window(mlx->mlx, mlx->win, \
		mlx->wall, x * TILE, y * TILE);
	else if (c == '0')
		render = mlx_put_image_to_window(mlx->mlx, mlx->win,\
		mlx->empty, x * TILE, y * TILE);
	else if (c == 'E')
		render = mlx_put_image_to_window(mlx->mlx, mlx->win, \
		mlx->exit, x * TILE, y * TILE);
	else if (c == 'C')
		render = mlx_put_image_to_window(mlx->mlx, mlx->win, \
		mlx->collectible, x * TILE, y * TILE);
	if (render == 1)
		ft_error("Error\nCould not load image");
}

void	ft_render_map(t_map *map, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map->map[y])
	{
		while (map->map[y][x])
		{
			ft_printf("%c", map->map[y][x]); //debug
			ft_render_image(map->map[y][x], mlx, x, y);
			x++;
		}
		ft_printf("\n"); //debug
		y++;
		x = 0;
	}
}

void	ft_start_mlx(t_map *map, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_error("Error initializing Minilibx");
	debug("\nmlx initialized");
	mlx->win = mlx_new_window(mlx->mlx, map->width, map->height, "So long");
	if (!mlx->win)
		ft_error("Error initializing the window");
	debug("window opened");
	ft_load_textures(mlx);
	debug("textures loaded");
	ft_render_map(map, mlx);
	debug("map rendered");
	mlx_loop(mlx->mlx);
	debug("loop active");
}

int	main(int argc, char	**argv)
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		ft_error("Usage: ./so_long filename.ber\n");
	extractmap(argv[1], &map);
	/*debug*/ft_printf("Map height = %d\nMap width = %d", map.height / TILE, map.width / TILE);
	ft_start_mlx(&map, &mlx);
}
