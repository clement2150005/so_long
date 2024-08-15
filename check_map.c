/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:42:32 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/15 17:58:56 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	ft_isrectangle(char *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
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
		if (map[i] != '\0')
			i++;
		if (len != j)
			ft_error("Error\nThe map must be rectangular\n");
		j = 0;
	}
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
}

void	ft_isallowedchar(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '0' && map[i] != '1' && map[i] != 'C' && map[i] != \
		'E' && map[i] != 'P' && map[i] != '\n')
			ft_error("Error\nThe map contains forbidden character(s)");
		i++;
	}
}
