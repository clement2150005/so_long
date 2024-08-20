/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:06:03 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/17 10:16:20 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
}					t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
	void	*empty;
	int		collectibles;
	int		playerx;
	int		playery;
	int		*height_player;
	int		*height_collectible;
	int		*height_exit;
	int		*height_wall;
	int		*height_empty;
	int		*width_player;
	int		*width_collectible;
	int		*width_exit;
	int		*width_wall;
	int		*width_empty;
}					t_mlx;

typedef struct s_param
{
	t_map	map;
	t_mlx	mlx;
}					t_param;

# define TILE 32
# define PLAYER "./textures/player.xpm"
# define WALL "./textures/wall.xpm"
# define COLLEC "./textures/collectible.xpm"
# define EMPTY "./textures/empty.xpm"
# define EXIT "./textures/exit.xpm"

void	ft_checkcharacters(char *map);
void	ft_isrectangle(char *map);
void	ft_isclosed(char *map);
void	ft_isallowedchar(char *map);
void	extractmap(char *filename, t_map *mapdata);
void	ft_error(char *errormessage);
void	ft_alloc_sizes(t_mlx *mlx);
void	ft_free_textures(t_mlx *mlx);
void	ft_start_mlx(t_map *map, t_mlx *mlx);
void	ft_events(int keycode, void *map);

#endif