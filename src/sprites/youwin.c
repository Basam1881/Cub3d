/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   youwin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:57 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 18:33:01 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_youwin(t_map *map)
{
	int					x;
	int					y;
	int					color;
	int					index;

	index = map->youwin_index;
	map->img = mlx_new_image(map->mlx, SCREENWIDTH, SCREENHEIGHT);
	map->addr = mlx_get_data_addr(map->img, &map->bpp,
			&map->line_len, &map->endian);
	y = -1;
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		map->tex[index].tex_y = y * map->tex[index].tex_height / SCREENHEIGHT;
		while (++x < SCREENWIDTH)
		{
			map->tex[index].tex_x = x * map->tex[index].tex_width / SCREENWIDTH;
			color = choose_pixel_color(map, index);
			cub3d_mlx_pixel_put(map, x, y, color);
		}
	}
	moving_youwin_sprites(map);
}
