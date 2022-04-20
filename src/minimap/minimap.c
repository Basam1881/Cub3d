/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:04 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 18:35:05 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_minimap(t_minimap *minimap, t_map *map)
{
	int	scale;

	if (map->width >= map->height)
		scale = SCREENWIDTH / map->width * 0.5;
	else
		scale = SCREENHEIGHT / map->height * 0.5;
	minimap->mlx = map->mlx;
	minimap->win = map->win;
	minimap->pos_x = map->pos_x;
	minimap->pos_y = map->pos_y;
	minimap->width = map->width * scale * 2;
	minimap->height = map->height * scale * 2;
	minimap->map_width = map->width;
	minimap->map_height = map->height;
	minimap->block_height = minimap->height / minimap->map_height;
	minimap->block_width = minimap->block_height;
	minimap->img = mlx_new_image(minimap->mlx, SCREENWIDTH, SCREENHEIGHT);
	minimap->addr = mlx_get_data_addr(minimap->img, &minimap->bpp,
			&minimap->line_len, &minimap->endian);
}

static void	get_color_flag(t_minimap *minimap, t_map *map, int i, int j)
{
	int	k;

	minimap->flag = map->level[j][i];
	k = 0;
	while (k < map->sprite_cnt)
	{
		if (i == (int)map->sprite[k].x && j == (int)map->sprite[k].y)
		{
			if (map->sprite[k].type == 'C')
				minimap->flag = -11;
			else if (map->sprite[k].type == 'G')
			{
				if (!map->fmm.exit_flag)
					minimap->flag = -12;
				else
					minimap->flag = 0;
			}
			else
				minimap->flag = -13;
		}
		k++;
	}
}

static void	draw_block(t_minimap *minimap, int i, int j)
{
	int	k;
	int	l;

	k = -1;
	while (++k < minimap->block_height)
	{
		l = -1;
		while (++l < minimap->block_width)
		{
			draw_minimap_pixel(minimap, (i * minimap->block_width) + l
				+ (SCREENWIDTH / 2 - minimap->width / 2),
				(j * minimap->block_height) + k + (SCREENHEIGHT / 2
					- minimap->height / 2), minimap->flag);
		}
	}
}

static void	draw_minimap(t_minimap *minimap, t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < SCREENHEIGHT)
	{
		i = -1;
		while (++i < SCREENWIDTH)
			draw_minimap_pixel(minimap, i, j, -1);
	}
	sprite_minimap_exit(map);
	j = -1;
	while (++j < minimap->map_height)
	{
		i = -1;
		while (++i < minimap->map_width)
		{	
			get_color_flag(minimap, map, i, j);
			draw_block(minimap, i, j);
		}
	}
}

t_minimap	use_minimap(t_map *map)
{
	t_minimap	minimap;

	init_minimap(&minimap, map);
	draw_minimap(&minimap, map);
	init_player(&minimap);
	draw_player(&minimap);
	return (minimap);
}
