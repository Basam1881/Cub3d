/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fm_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:03:42 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 22:23:09 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	minimap_blocks_division(t_minimap *minimap, t_map *map)
{
	if (map->fmm.k)
	{
		map->fmm.kk = (double)map->fmm.k;
		map->fmm.kk = map->fmm.kk / minimap->block_height;
	}
	else
		map->fmm.kk = 0;
	if (map->fmm.l)
	{
		map->fmm.ll = (double)map->fmm.l;
		map->fmm.ll = map->fmm.ll / minimap->block_width;
	}
	else
		map->fmm.ll = 0;
}

static int	set_sprites_color_flag(t_map *map, int flag)
{
	int	i;

	i = -1;
	while (++i < map->sprite_cnt)
	{
		if ((int)(map->pos_x - FOCUSED_MINIMAP_SIZE / 2
			+ map->fmm.i + map->fmm.ll) == (int)map->sprite[i].x
			&& (int)(map->pos_y - FOCUSED_MINIMAP_SIZE / 2
			+ map->fmm.j + map->fmm.kk) == (int)map->sprite[i].y)
		{
			if (map->sprite[i].type == 'C')
				flag = -11;
			else if (map->sprite[i].type == 'G')
			{
				if (!map->fmm.exit_flag)
					flag = -12;
				else
					flag = 0;
			}
			else
				flag = -13;
		}
	}
	return (flag);
}

static int	get_color_flag(t_map *map)
{
	int	flag;

	if ((map->pos_x - FOCUSED_MINIMAP_SIZE / 2
			+ map->fmm.i + map->fmm.ll) >= 0
		&& (int)(map->pos_x - FOCUSED_MINIMAP_SIZE / 2
		+ map->fmm.i + map->fmm.ll) < map->width
		&& (map->pos_y - FOCUSED_MINIMAP_SIZE / 2
		+ map->fmm.j + map->fmm.kk) >= 0
		&& (int)(map->pos_y - FOCUSED_MINIMAP_SIZE / 2
		+ map->fmm.j + map->fmm.kk) < map->height)
		flag = map->level[(int)(map->pos_y
				- FOCUSED_MINIMAP_SIZE / 2 + map->fmm.j
				+ map->fmm.kk)][(int)(map->pos_x
				- FOCUSED_MINIMAP_SIZE / 2 + map->fmm.i
				+ map->fmm.ll)];
	else
		flag = -1;
	flag = set_sprites_color_flag(map, flag);
	return (flag);
}

static void	draw_focused_minimap_blocks(t_minimap *minimap, t_map *map)
{
	int	flag;

	map->fmm.k = -1;
	while (++map->fmm.k < minimap->block_height)
	{
		map->fmm.l = -1;
		while (++map->fmm.l < minimap->block_width)
		{
			minimap_blocks_division(minimap, map);
			flag = get_color_flag(map);
			if ((map->fmm.i * minimap->block_width)
				+ map->fmm.l < minimap->width
				&& (map->fmm.j * minimap->block_height)
				+ map->fmm.k < minimap->height
				&& (map->fmm.i * minimap->block_width) + map->fmm.l >= 0
				&& (map->fmm.j * minimap->block_height) + map->fmm.k >= 0)
				draw_minimap_pixel(minimap, (map->fmm.i * minimap->block_width)
					+ map->fmm.l, (map->fmm.j * minimap->block_height)
					+ map->fmm.k, flag);
		}
	}
}

void	draw_focused_minimap(t_minimap *minimap, t_map *map)
{
	sprite_minimap_exit(map);
	map->fmm.i = -1;
	while (++map->fmm.i * minimap->block_width < minimap->width)
	{
		map->fmm.j = -1;
		while (++map->fmm.j * minimap->block_height < minimap->height)
			draw_focused_minimap_blocks(minimap, map);
	}
}
