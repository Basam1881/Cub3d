/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_allocation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:27:28 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/20 11:19:40 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	store_map_width(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->width = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i + N_ELEMENTS][j])
			j++;
		if (j > map->width)
			map->width = j;
		i++;
	}
	if (map->width > MAP_WIDTH_MAX || map->height > MAP_HEIGHT_MAX)
		error(16, map);
	map->sprite_tmp = (t_sprite *)malloc(sizeof(t_sprite)
			* (map->width * map->height));
}

void	allocation(t_map *map)
{
	int	i;
	int	j;

	i = N_ELEMENTS;
	while (map->map[i++])
		;
	map->height = i - N_ELEMENTS - 1;
	map->level = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (!map->level)
		error(3, map);
	i = 0;
	while (i < map->height + 1)
		map->level[i++] = NULL;
	store_map_width(map);
	i = 0;
	while (i < map->height)
	{
		map->level[i] = (int *)malloc(sizeof(int) * (map->width));
		if (!map->level[i])
			error(3, map);
		j = -1;
		while (++j < map->width)
			map->level[i][j] = -1;
		i++;
	}
}
