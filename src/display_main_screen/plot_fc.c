/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_fc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:15:45 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 18:33:46 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	plot_floor(t_map *map, int y, int x)
{
	int	color;

	map->fc.cellx = (int)map->fc.floorx;
	map->fc.celly = (int)map->fc.floory;
	map->fc.floorx += map->fc.floor_stepx;
	map->fc.floory += map->fc.floor_stepy;
	if (T_FLOOR && map->fixed_files[FLOOR_INDEX] && y >= SCREENHEIGHT / 2)
	{
		map->tex[FLOOR_INDEX].tex_x = (int)(map->tex[FLOOR_INDEX].tex_width
				* (map->fc.floorx - map->fc.cellx))
			& (map->tex[FLOOR_INDEX].tex_width - 1);
		map->tex[FLOOR_INDEX].tex_y = (int)(map->tex[FLOOR_INDEX].tex_height
				* (map->fc.floory - map->fc.celly))
			& (map->tex[FLOOR_INDEX].tex_height - 1);
		color = choose_pixel_color(map, FLOOR_INDEX);
		cub3d_mlx_pixel_put(map, x, y, color);
	}
}

void	plot_ceiling(t_map *map, int y, int x)
{
	int	color;

	map->fc.cellx = (int)map->fc.ceilingx;
	map->fc.celly = (int)map->fc.ceilingy;
	map->fc.ceilingx += map->fc.ceiling_stepx;
	map->fc.ceilingy += map->fc.ceiling_stepy;
	if (T_CEILING && map->fixed_files[CEILING_INDEX]
		&& y < SCREENHEIGHT / 2)
	{
		map->tex[CEILING_INDEX].tex_x = (int)(map->tex[CEILING_INDEX].tex_width
				* (map->fc.ceilingx - map->fc.cellx))
			& (map->tex[CEILING_INDEX].tex_width - 1);
		map->tex[CEILING_INDEX].tex_y = (int)(map->tex[CEILING_INDEX].tex_height
				* (map->fc.ceilingy - map->fc.celly))
			& (map->tex[CEILING_INDEX].tex_height - 1);
		color = choose_pixel_color(map, CEILING_INDEX);
		cub3d_mlx_pixel_put(map, x, y, color);
	}
}

void	plot_fc(t_map *map, int y)
{
	int	x;
	int	floor_color;
	int	ceiling_color;

	floor_color = (map->fr << 16) + (map->fg << 8) + map->fb;
	ceiling_color = (map->cr << 16) + (map->cg << 8) + map->cb;
	x = 0;
	while (x < SCREENWIDTH)
	{
		plot_floor(map, y, x);
		plot_ceiling(map, y, x);
		if ((!T_CEILING || !map->fixed_files[CEILING_INDEX])
			&& y < SCREENHEIGHT / 2)
			cub3d_mlx_pixel_put(map, x, y, ceiling_color);
		else if ((!T_FLOOR || !map->fixed_files[FLOOR_INDEX])
			&& y >= SCREENHEIGHT / 2)
			cub3d_mlx_pixel_put(map, x, y, floor_color);
		x++;
	}
}
