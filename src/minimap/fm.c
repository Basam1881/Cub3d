/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:08:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/15 20:08:10 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_focused_minimap(t_minimap *minimap, t_map *map)
{
	int	scale;

	scale = SCREENHEIGHT / 3;
	minimap->mlx = map->mlx;
	minimap->win = map->win;
	minimap->pos_x = map->pos_x;
	minimap->pos_y = map->pos_y;
	minimap->width = scale;
	minimap->height = scale;
	minimap->block_height = minimap->height / FOCUSED_MINIMAP_SIZE;
	minimap->block_width = minimap->block_height;
	minimap->p_pos_x = minimap->width / 2 - minimap->block_width / 2;
	minimap->p_pos_y = minimap->height / 2 - minimap->block_height / 2;
	minimap->img = mlx_new_image(minimap->mlx, minimap->width, minimap->height);
	minimap->addr = mlx_get_data_addr(minimap->img, &minimap->bpp,
			&minimap->line_len, &minimap->endian);
}

t_minimap	use_focused_minimap(t_map *map)
{
	t_minimap	minimap;

	init_focused_minimap(&minimap, map);
	draw_focused_minimap(&minimap, map);
	draw_fm_player(&minimap);
	draw_player_vision(&minimap, map);
	cover_visible_area(&minimap, map);
	map->map_xy_cnt = 0;
	return (minimap);
}
