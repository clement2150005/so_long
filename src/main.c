/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:06:16 by ccolin            #+#    #+#             */
/*   Updated: 2024/09/08 16:30:39 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_map	map;
	t_mlx	mlx;

	if (argc != 2)
		ft_error("Usage: ./so_long filename.ber\n");
	extractmap(argv[1], &map);
	ft_start_mlx(&map, &mlx);
	system("leaks a.out");
	mlx.moves = 0;
	mlx_loop(mlx.mlx);
}
