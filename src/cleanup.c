/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:10:49 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/29 10:30:52 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_unload_textures(t_mlx *mlx)
{
	if (mlx->player)
		mlx_destroy_image(mlx->mlx, mlx->player);
	if (mlx->wall)
		mlx_destroy_image(mlx->mlx, mlx->wall);
	if (mlx->collectible)
		mlx_destroy_image(mlx->mlx, mlx->collectible);
	if (mlx->exit)
		mlx_destroy_image(mlx->mlx, mlx->exit);
	if (mlx->empty)
		mlx_destroy_image(mlx->mlx, mlx->empty);
}

int	ft_cleanup(t_param *param)
{
	ft_unload_textures(param->mlx);
	ft_free_textures(param->mlx);
	ft_freemap(param->map->map);
	mlx_destroy_window(param->mlx->mlx, param->mlx->win);
	exit(0);
}
