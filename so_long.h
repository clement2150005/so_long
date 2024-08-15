/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:06:03 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/15 17:07:45 by ccolin           ###   ########.fr       */
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

# define TILE 32
# define PLAYER "./xpm_images/player.xpm"
# define WALL "./xpm_images/wall.xpm"
# define COLLEC "./xpm_images/collectible.xpm"
# define EMPTY "./xpm_images/empty.xpm"
# define EXIT "./xpm_images/exit.xpm"

void	ft_checkcharacters(char *map);
void	ft_isrectangle(char *map);
void	ft_isclosed(char *map);
void	ft_isallowedchar(char *map);
void	extractmap(char *filename, t_map *mapdata);
void	debug(char *str);
void	ft_error(char *errormessage);

#endif