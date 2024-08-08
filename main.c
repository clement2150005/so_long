/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccolin <ccolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:06:16 by ccolin            #+#    #+#             */
/*   Updated: 2024/08/08 16:15:40 by ccolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

char	**extractmap(char *filename)
{
	int		fd;
	char	*line;
	char	*map;
	char	*temp;

	map = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error("Could not read the map file\n");
	line = get_next_line_bonus(fd);
	while (line)
	{
		temp = map;
		map = ft_strjoin(map, line);
		free(line);
		free(temp);
		line = get_next_line_bonus(fd);
	}
	return (map);
}

void	ft_error(char *errormessage)
{
	ft_putstr_fd(errormessage, 2);
	exit(1);
}

// void	ft_errorcheck(char **map)
// {

// }

int	main(int argc, char	**argv)
{
	char	**map;

	if (argc != 2)
		ft_error("Usage: ./so_long filename.ber\n");
	map = extractmap(argv[1]);
	ft_printf("%s", map);
	// ft_errorcheck(map);
}
