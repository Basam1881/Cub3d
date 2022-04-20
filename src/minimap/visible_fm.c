/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visible_fm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:08:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/18 18:01:14 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	plot_current_dst(t_minimap *minimap, t_map *map)
{
	char	*dst;

	dst = minimap->addr + (map->fmm.i * minimap->line_len
			+ map->fmm.j * (minimap->bpp / 8));
	if (!(*(unsigned int *)dst == INVISIBLEWALLCOLOR
			|| *(unsigned int *)dst == INVISIBLEPORTALCOLOR
			|| *(unsigned int *)dst == INVISIBLECLOSEDDOORCOLOR))
		print_visible_area(dst);
}

static void	check_horizontal_n_vertical(t_minimap *minimap, t_map *map, int x)
{
	char	*dst1;
	char	*dst2;

	dst1 = NULL;
	dst2 = NULL;
	if (map->fmm.i - x >= 0 && map->fmm.i + x <= minimap->height - 2)
	{
		dst1 = minimap->addr + ((map->fmm.i - x)
				* minimap->line_len + (map->fmm.j) * (minimap->bpp / 8));
		dst2 = minimap->addr + ((map->fmm.i + x)
				* minimap->line_len + (map->fmm.j) * (minimap->bpp / 8));
		if (is_visible(dst1) && is_visible(dst2))
			plot_current_dst(minimap, map);
	}
	if (map->fmm.j - x >= 0 && map->fmm.j + x <= minimap->height - 2)
	{
		dst1 = minimap->addr + ((map->fmm.i)
				* minimap->line_len + (map->fmm.j - x) * (minimap->bpp / 8));
		dst2 = minimap->addr + ((map->fmm.i)
				* minimap->line_len + (map->fmm.j + x) * (minimap->bpp / 8));
		if (is_visible(dst1) && is_visible(dst2))
			plot_current_dst(minimap, map);
	}
}

static void	check_diagonals(t_minimap *minimap, t_map *map, int x)
{
	char	*dst1;
	char	*dst2;

	dst1 = NULL;
	dst2 = NULL;
	if (map->fmm.i - x >= 0 && map->fmm.i + x <= minimap->height - 2
		&& map->fmm.j - x >= 0 && map->fmm.j + x <= minimap->height - 2)
	{
		dst1 = minimap->addr + ((map->fmm.i - x)
				* minimap->line_len + (map->fmm.j - x) * (minimap->bpp / 8));
		dst2 = minimap->addr + ((map->fmm.i + x)
				* minimap->line_len + (map->fmm.j + x) * (minimap->bpp / 8));
		if (is_visible(dst1) && is_visible(dst2))
			plot_current_dst(minimap, map);
	}
	if (map->fmm.i - x >= 0 && map->fmm.i + x <= minimap->height - 2
		&& map->fmm.j - x >= 0 && map->fmm.j + x <= minimap->height - 2)
	{
		dst1 = minimap->addr + ((map->fmm.i - x)
				* minimap->line_len + (map->fmm.j + x) * (minimap->bpp / 8));
		dst2 = minimap->addr + ((map->fmm.i + x)
				* minimap->line_len + (map->fmm.j - x) * (minimap->bpp / 8));
		if (is_visible(dst1) && is_visible(dst2))
			plot_current_dst(minimap, map);
	}
}

static void	color_copier(t_minimap *minimap, t_map *map)
{
	int		x;

	x = 0;
	while (++x <= minimap->block_height / 2)
	{
		check_horizontal_n_vertical(minimap, map, x);
		check_diagonals(minimap, map, x);
	}
}

void	cover_visible_area(t_minimap *minimap, t_map *map)
{
	map->fmm.i = minimap->height - 2;
	while (--map->fmm.i >= 0)
	{
		map->fmm.j = minimap->width - 2;
		while (--map->fmm.j >= 0)
			color_copier(minimap, map);
	}
}
