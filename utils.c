/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:46:08 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/15 11:47:13 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	debug(char *str)
{
	ft_printf("%s\n", str);
}

void	ft_error(char *errormessage)
{
	ft_putstr_fd(errormessage, 2);
	exit(1);
}
