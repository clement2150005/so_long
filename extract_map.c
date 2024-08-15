/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:39:59 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/15 17:57:24 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mapcheck(char *map)
{
	ft_isallowedchar(map);
	ft_checkcharacters(map);
	ft_isrectangle(map);
	ft_isclosed(map);
}

void	ft_mapsize(t_map *mapdata)
{
	int	i;

	i = 0;
	while (mapdata->map[i])
		i++;
	mapdata->height = i * TILE;
	i = 0;
	while (mapdata->map[0][i])
		i++;
	mapdata->width = i * TILE;
}

void	extractmap(char *filename, t_map *mapdata)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nCould not read the map file\n");
	line = get_next_line(fd);
	while (line)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(line);
		free(temp);
		line = get_next_line(fd);
	}
	ft_mapcheck(map);
	mapdata->map = ft_split(map, '\n');
	ft_mapsize(mapdata);
}
