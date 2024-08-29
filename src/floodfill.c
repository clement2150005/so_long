/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:48:08 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/29 10:12:45 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(char **map, int y, int x)
{
	if (x < 0 || y < 0 || !map[y + 1][x] || !map[y][x + 1])
		return ;
	map[y][x] = 'P';
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'P')
		ft_floodfill(map, y + 1, x);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'P')
		ft_floodfill(map, y - 1, x);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'P')
		ft_floodfill(map, y, x + 1);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'P')
		ft_floodfill(map, y, x - 1);
}
