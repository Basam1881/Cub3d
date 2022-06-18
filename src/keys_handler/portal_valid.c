/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmekky <mmekky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:47:50 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/20 16:17:51 by mmekky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_portal_condition(t_map *map, t_portal *p, int x, int y)
{
	if (map->level[p->center_y + y][p->center_x + x] != 1
		&& map->level[p->center_y + y][p->center_x + x] != -1
		&& map->level[p->center_y + y][p->center_x + x] != 20
		&& map->level[p->center_y + y][p->center_x + x] != 21)
		return (1);
	return (0);
}

int	portal_check_sides(t_map *map, t_portal *p)
{
	int	x;
	int	y;

	x = 2;
	y = 2;
	if (map->portal_wall == NORTH || map->portal_wall == SOUTH)
		x = -1;
	else if (map->portal_wall == EAST || map->portal_wall == WEST)
		y = -1;
	while (x <= 1)
	{
		if (valid_portal_condition(map, p, x, 0))
			return (0);
		x += 2;
	}
	while (y <= 1)
	{
		if (valid_portal_condition(map, p, 0, y))
			return (0);
		y += 2;
	}
	return (1);
}

int	portal_check_back(t_map *map, t_portal *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (map->portal_wall == NORTH && p->center_y == 0)
		return (1);
	else if (map->portal_wall == SOUTH && p->center_y == map->height - 1)
		return (1);
	else if (map->portal_wall == WEST && p->center_x == 0)
		return (1);
	else if (map->portal_wall == EAST && p->center_x == map->width - 1)
		return (1);
	if (map->portal_wall == NORTH)
		y = -1;
	else if (map->portal_wall == SOUTH)
		y = 1;
	else if (map->portal_wall == WEST)
		x = -1;
	else if (map->portal_wall == EAST)
		x = 1;
	if (valid_portal_condition(map, p, x, y))
		return (0);
	return (1);
}

int	portal_check_front(t_map *map, t_portal *p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (map->portal_wall == NORTH)
		y = 1;
	else if (map->portal_wall == SOUTH)
		y = -1;
	else if (map->portal_wall == WEST)
		x = 1;
	else if (map->portal_wall == EAST)
		x = -1;
	if (map->level[p->center_y + y][p->center_x + x] != 0)
		return (0);
	return (1);
}

int	valid_portal(t_map *map, t_portal *p)
{
	if (portal_check_sides(map, p)
		&& portal_check_back(map, p)
		&& portal_check_front(map, p))
		return (1);
	return (0);
}
