/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:06:16 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/17 09:46:17 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_events(int keycode, void *map)
{
	int	w;
	int	a;
	int	s;
	int	d;

	w = 13;
	a = 0;
	s = 1;
	d = 2;
	if (keycode == w)
		ft_up(map);
	if (keycode == a)
		ft_left(map);
	if (keycode == s)
		ft_down(map);
	if (keycode == d)
		ft_right(map);
}

int	main(int argc, char	**argv)
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		ft_error("Usage: ./so_long filename.ber\n");
	extractmap(argv[1], &map);
	ft_start_mlx(&map, &mlx);
	ft_free_textures(&mlx);
}
