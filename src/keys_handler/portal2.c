/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 10:10:27 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/17 18:14:36 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	get_portal_angle(int *u, int *v)
{
	int		res;
	double	angle;

	res = u[0] * v[1] - v[0] * u[1];
	if (res == 0)
		res = u[0] + v[0] + u[1] + v[1];
	angle = -(M_PI / 2) * res;
	return (angle);
}

void	change_dir_after_portal(t_map *map, double angle)
{
	double	dir_x;
	double	plane_x;

	dir_x = map->dir_x;
	plane_x = map->plane_x;
	map->dir_x = map->dir_x * cos(angle) - map->dir_y * sin(angle);
	map->dir_y = dir_x * sin(angle) + map->dir_y * cos(angle);
	map->plane_x = map->plane_x * cos(angle) - map->plane_y * sin(angle);
	map->plane_y = plane_x * sin(angle) + map->plane_y * cos(angle);
}

void	change_pos_after_portal(t_map *map, t_portal portal)
{
	if (portal.wall_tex == NORTH)
	{
		map->pos_x = portal.pos_x + 0.5;
		map->pos_y = portal.pos_y + 1.5;
	}
	else if (portal.wall_tex == SOUTH)
	{
		map->pos_x = portal.pos_x + 0.5;
		map->pos_y = portal.pos_y - 0.5;
	}
	else if (portal.wall_tex == EAST)
	{
		map->pos_x = portal.pos_x - 0.5;
		map->pos_y = portal.pos_y + 0.5;
	}
	else if (portal.wall_tex == WEST)
	{
		map->pos_x = portal.pos_x + 1.5;
		map->pos_y = portal.pos_y + 0.5;
	}
}

void	check_portal(t_map *map)
{
	double	angle;

	if (map->level[(int)(map->pos_y)][(int)(map->pos_x)] == 20)
	{
		angle = get_portal_angle(map->dir_vector[map->blue.wall_tex],
				map->dir_vector[map->orange.wall_tex]);
		change_dir_after_portal(map, angle);
		change_pos_after_portal(map, map->orange);
	}
	else if (map->level[(int)(map->pos_y)][(int)(map->pos_x)] == 21)
	{
		angle = get_portal_angle(map->dir_vector[map->orange.wall_tex],
				map->dir_vector[map->blue.wall_tex]);
		change_dir_after_portal(map, angle);
		change_pos_after_portal(map, map->blue);
	}
}

void	set_portal_positions(t_map *map)
{
	map->blue.center_x = map->map_x;
	map->blue.center_y = map->map_y;
	map->orange.center_x = map->map_x;
	map->orange.center_y = map->map_y;
}
