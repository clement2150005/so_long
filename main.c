/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:06:16 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/11 15:43:35 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

void	debug(char *str)
{
	ft_printf("%s\n", str);
}

void	ft_error(char *errormessage)
{
	ft_putstr_fd(errormessage, 2);
	exit(1);
}

void	ft_checkcharacters(char *map)
{
	int	i;
	int	exit;
	int	player;
	int	collectible;

	i = 0;
	exit = 0;
	player = 0;
	collectible = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			collectible++;
		if (map[i] == 'P')
			player++;
		if (map[i] == 'E')
			exit++;
		i++;
	}
	if (collectible == 0)
		ft_error("Error\nNo collectibles found in the map\n");
	if (player != 1)
		ft_error("Error\nThere is no player or more than 1 player in the map\n");
	if (exit != 1)
		ft_error("Error\nThere is no exit or more than 1 exit in the map\n");
	debug("characters ok");
}

void	ft_isrectangle(char *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	/*debug*/ft_printf("%s", map);
	while (map[i] != '\n')
		i++;
	len = i;
	i++;
	while (map[i])
	{
		while (map[i] && map[i] != '\n')
		{
			i++;
			j++;
		}
		i++;
 		if (len != j)
			ft_error("Error\nThe map must be rectangular\n");
		j = 0;
	}
	debug("rectangle ok");
}

void	ft_isclosed(char *map)
{
	int	i;

	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			ft_error("Error\nThe map is not surrounded by walls");
		i++;
	}
	while (map[i])
	{
		if (map[i] == '\n' && !(map[i - 1] == '1'))
			ft_error("Error\nThe map is not surrounded by walls");
		i++;
	}
	i--;
	while (map[i] != '\n')
	{		
		if (map[i] != '1')
			ft_error("Error\nThe map is not surrounded by walls");
		i--;
	}
	debug("map is closed");
}

void	ft_mapcheck(char *map)
{
	ft_checkcharacters(map);
	ft_isrectangle(map);
	ft_isclosed(map);
}

char	*extractmap(char *filename)
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
	return (map);
}

// void	ft_errorcheck(char **map)
// {

// }

int	main(int argc, char	**argv)
{
	char	*map;

	if (argc != 2)
		ft_error("Usage: ./so_long filename.ber\n");
	map = extractmap(argv[1]);
}
