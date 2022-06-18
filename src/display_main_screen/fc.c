/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:04:13 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 18:33:35 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_floor(t_map *map, int y)
{
	map->fc.pf = y - SCREENHEIGHT / 2;
	map->fc.posf_z = SCREENHEIGHT / 2;
	map->fc.row_distf = map->fc.posf_z / map->fc.pf;
	map->fc.floor_stepx = map->fc.row_distf
		* (map->fc.raydirx1 - map->fc.raydirx0) / SCREENWIDTH;
	map->fc.floor_stepy = map->fc.row_distf
		* (map->fc.raydiry1 - map->fc.raydiry0) / SCREENWIDTH;
	map->fc.floorx = map->pos_x + map->fc.row_distf * map->fc.raydirx0;
	map->fc.floory = map->pos_y + map->fc.row_distf * map->fc.raydiry0;
}

void	init_ceiling(t_map *map, int y)
{
	map->fc.pc = SCREENHEIGHT / 2 - y;
	map->fc.posc_z = SCREENHEIGHT / 2;
	map->fc.row_distc = map->fc.posc_z / map->fc.pc;
	map->fc.ceiling_stepx = map->fc.row_distc
		* (map->fc.raydirx1 - map->fc.raydirx0) / SCREENWIDTH;
	map->fc.ceiling_stepy = map->fc.row_distc
		* (map->fc.raydiry1 - map->fc.raydiry0) / SCREENWIDTH;
	map->fc.ceilingx = map->pos_x + map->fc.row_distc * map->fc.raydirx0;
	map->fc.ceilingy = map->pos_y + map->fc.row_distc * map->fc.raydiry0;
}

void	draw_fc(t_map *map)
{
	int	y;

	y = 0;
	while (y < SCREENHEIGHT)
	{
		map->fc.raydirx0 = map->dir_x - map->plane_x;
		map->fc.raydiry0 = map->dir_y - map->plane_y;
		map->fc.raydirx1 = map->dir_x + map->plane_x;
		map->fc.raydiry1 = map->dir_y + map->plane_y;
		init_floor(map, y);
		init_ceiling(map, y);
		plot_fc(map, y);
		y++;
	}
}
