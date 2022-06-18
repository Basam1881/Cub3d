/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fm_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:04:05 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/15 21:37:46 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	fm_init_draw_ray(t_minimap *minimap, t_map *map)
{
	map->fmm.x0 = minimap->p_pos_x;
	map->fmm.y0 = minimap->p_pos_y;
	map->fmm.x1 = (minimap->p_pos_x
			+ ((map->map_xs[map->fmm.x] - map->pos_x)
				* minimap->block_width));
	map->fmm.y1 = (minimap->p_pos_y
			+ ((map->map_ys[map->fmm.x] - map->pos_y)
				* minimap->block_height));
	map->fmm.dx = abs(map->fmm.x1 - map->fmm.x0);
	if (map->fmm.x0 < map->fmm.x1)
		map->fmm.sx = 1;
	else
		map->fmm.sx = -1;
	map->fmm.dy = -abs(map->fmm.y1 - map->fmm.y0);
	if (map->fmm.y0 < map->fmm.y1)
		map->fmm.sy = 1;
	else
		map->fmm.sy = -1;
	map->fmm.error = map->fmm.dx + map->fmm.dy;
}

static int	go_to_next_point(t_map *map)
{
	map->fmm.e2 = 2 * map->fmm.error;
	if (map->fmm.e2 >= map->fmm.dy)
	{
		if (map->fmm.x0 == map->fmm.x1)
			return (0);
		map->fmm.error = map->fmm.error + map->fmm.dy;
		map->fmm.x0 += map->fmm.sx;
	}
	if (map->fmm.e2 <= map->fmm.dx)
	{
		if (map->fmm.y0 == map->fmm.y1)
			return (0);
		map->fmm.error = map->fmm.error + map->fmm.dx;
		map->fmm.y0 += map->fmm.sy;
	}
	return (1);
}

static int	check_n_plot(t_minimap *minimap, t_map *map)
{
	char	*dst;

	dst = minimap->addr + (map->fmm.y0 * minimap->line_len
			+ map->fmm.x0 * (minimap->bpp / 8));
	map->fmm.i = map->fmm.y0;
	map->fmm.j = map->fmm.x0;
	if (!print_visibal_rays(minimap, dst, map))
		return (0);
	if ((map->fmm.x0 == map->fmm.x1
			&& map->fmm.y0 == map->fmm.y1)
		|| map->fmm.x0 >= minimap->width - 1
		|| map->fmm.y0 >= minimap->height - 1
		|| map->fmm.y0 < 0 || map->fmm.x0 < 0)
		return (0);
	return (1);
}

void	draw_player_vision(t_minimap *minimap, t_map *map)
{
	map->fmm.x = -1;
	while (++map->fmm.x < SCREENWIDTH)
	{
		fm_init_ray(map);
		fm_check_ray_direction(map);
		fm_check_wall_hit(map);
	}
	map->fmm.x = -1;
	while (++map->fmm.x < map->map_xy_cnt)
	{
		fm_init_draw_ray(minimap, map);
		while (1)
		{
			if (!check_n_plot(minimap, map))
				break ;
			if (!go_to_next_point(map))
				break ;
		}
	}
}
