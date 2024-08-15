/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:46:08 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/15 17:57:22 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_alloc_sizes(t_mlx *mlx)
{
	mlx->width_player = malloc(sizeof(int));
	mlx->height_player = malloc(sizeof(int));
	mlx->width_wall = malloc(sizeof(int));
	mlx->height_wall = malloc(sizeof(int));
	mlx->width_collectible = malloc(sizeof(int));
	mlx->height_collectible = malloc(sizeof(int));
	mlx->width_empty = malloc(sizeof(int));
	mlx->height_empty = malloc(sizeof(int));
	mlx->width_exit = malloc(sizeof(int));
	mlx->height_exit = malloc(sizeof(int));
	if (!mlx->width_player || !mlx->height_player || !mlx->width_wall \
	|| !mlx->height_wall || !mlx->width_collectible || !mlx->height_collectible \
	|| !mlx->width_empty || !mlx->height_empty || !mlx->width_exit || \
	!mlx->height_exit)
		ft_error("failed to allocate memory for width/height pointers");
}

void	ft_free_textures(t_mlx *mlx)
{
	free(mlx->width_player);
	free(mlx->height_player);
	free(mlx->width_wall);
	free(mlx->height_wall);
	free(mlx->width_collectible);
	free(mlx->height_collectible);
	free(mlx->width_empty);
	free(mlx->height_empty);
	free(mlx->width_exit);
	free(mlx->height_exit);
}

void	ft_error(char *errormessage)
{
	ft_putstr_fd(errormessage, 2);
	exit(1);
}
