/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 09:46:37 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/22 20:35:35 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_param *param)
{
	printf("%d%d", param->mlx.playery, param->mlx.playerx); fflush(stdout); // debug
	if (param->map.map[param->mlx.playery - 1][param->mlx.playerx] == '1')
		return ;
	mlx_put_image_to_window(param->mlx.mlx, param->mlx.win, param->mlx.player, \
	(param->mlx.playerx) * TILE, (param->mlx.playery - 1) * TILE);
	param->mlx.playery--;
	return ;
}

void	ft_events(int keycode, void *param)
{
	int	w;
	// int	a;
	// int	s;
	// int	d;

	w = 13;
	// a = 0;
	// s = 1;
	// d = 2;
	if (keycode == w)
		ft_up(param);
	// if (keycode == a)
	// 	ft_left(param);
	// if (keycode == s)
	// 	ft_down(param);
	// if (keycode == d)
	// 	ft_right(param);
	return ;
}
