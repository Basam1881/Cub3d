/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:36:37 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 20:54:50 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	skipper(t_map *map, int i, int *j, int flag)
{
	if (!flag)
	{
		while (map->map[i][*j] && !(map->map[i][*j] == 32
			|| (map->map[i][*j] >= 9 && map->map[i][*j] <= 13)))
			(*j)++;
	}
	else if (flag == 1)
	{
		while (map->map[i][*j] && (map->map[i][*j] == 32
			|| (map->map[i][*j] >= 9 && map->map[i][*j] <= 13)))
			(*j)++;
	}
	else if (flag == 2)
	{
		while (map->map[i][*j]
			&& ((map->map[i][*j] >= '0' && map->map[i][*j] <= '9')
			|| map->map[i][*j] == '+'))
			(*j)++;
	}
}

void	parser(int fd, t_map *map)
{
	char	*tmp;
	int		len;
	char	*m;

	len = 1;
	m = (char *)malloc (sizeof(char));
	*m = 0;
	while (len)
	{
		tmp = (char *)malloc (sizeof(char) + 1);
		len = read(fd, tmp, 1);
		tmp[len] = 0;
		m = ft_strjoin(m, tmp);
		free(tmp);
	}
	close(fd);
	if (check_map_lines(m))
		error(13, map);
	map->map = ft_split(m, '\n');
	free(m);
	if (!map->map)
		error(3, map);
	elements_parser(map);
	map_parser(map);
}
