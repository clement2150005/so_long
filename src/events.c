/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 09:36:54 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/29 10:31:04 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_up(t_param *param)
{
	if (param->map->map[param->mlx->playery - 1][param->mlx->playerx] == '1')
		return ;
	if (param->map->map[param->mlx->playery - 1][param->mlx->playerx] == 'E')
	{
		if (ft_isonmap(param->map->map, "C"))
			return ;
	}
	param->map->map[param->mlx->playery][param->mlx->playerx] = '0';
	param->map->map[param->mlx->playery - 1][param->mlx->playerx] = 'P';
	ft_render_map(param->map, param->mlx);
	ft_printf("\nmoves: %d", ++param->mlx->moves);
	if (!ft_isonmap(param->map->map, "E"))
	{
		ft_printf("\nCongratulations!");
		ft_cleanup(param);
	}	
	return ;
}

void	ft_down(t_param *param)
{
	if (param->map->map[param->mlx->playery + 1][param->mlx->playerx] == '1')
		return ;
	if (param->map->map[param->mlx->playery + 1][param->mlx->playerx] == 'E')
	{
		if (ft_isonmap(param->map->map, "C"))
			return ;
	}
	param->map->map[param->mlx->playery][param->mlx->playerx] = '0';
	param->map->map[param->mlx->playery + 1][param->mlx->playerx] = 'P';
	ft_render_map(param->map, param->mlx);
	ft_printf("\nmoves: %d", ++param->mlx->moves);
	if (!ft_isonmap(param->map->map, "E"))
	{
		ft_printf("\nCongratulations!");
		ft_cleanup(param);
	}	
	return ;
}

void	ft_left(t_param *param)
{
	if (param->map->map[param->mlx->playery][param->mlx->playerx - 1] == '1')
		return ;
	if (param->map->map[param->mlx->playery][param->mlx->playerx - 1] == 'E')
	{
		if (ft_isonmap(param->map->map, "C"))
			return ;
	}
	param->map->map[param->mlx->playery][param->mlx->playerx] = '0';
	param->map->map[param->mlx->playery][param->mlx->playerx - 1] = 'P';
	ft_render_map(param->map, param->mlx);
	ft_printf("\nmoves: %d", ++param->mlx->moves);
	if (!ft_isonmap(param->map->map, "E"))
	{
		ft_printf("\nCongratulations!");
		ft_cleanup(param);
	}	
	return ;
}

void	ft_right(t_param *param)
{
	if (param->map->map[param->mlx->playery][param->mlx->playerx + 1] == '1')
		return ;
	if (param->map->map[param->mlx->playery][param->mlx->playerx + 1] == 'E')
	{
		if (ft_isonmap(param->map->map, "C"))
			return ;
	}
	param->map->map[param->mlx->playery][param->mlx->playerx] = '0';
	param->map->map[param->mlx->playery][param->mlx->playerx + 1] = 'P';
	ft_render_map(param->map, param->mlx);
	ft_printf("\nmoves: %d", ++param->mlx->moves);
	if (!ft_isonmap(param->map->map, "E"))
	{
		ft_printf("\nCongratulations!");
		ft_cleanup(param);
	}	
	return ;
}

int	ft_events(int keycode, void *param)
{
	t_param	*p;
	int		w;
	int		a;
	int		s;
	int		d;

	p = (t_param *)param;
	w = 13;
	a = 0;
	s = 1;
	d = 2;
	if (keycode == w)
	{
		ft_up(p);
	}
	if (keycode == a)
		ft_left(p);
	if (keycode == s)
		ft_down(p);
	if (keycode == d)
		ft_right(p);
	if (keycode == 53)
		ft_cleanup(p);
	return (0);
}
