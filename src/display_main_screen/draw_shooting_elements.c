/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shooting_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 01:17:49 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 15:42:46 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_shooting_lines(t_map *map)
{
	int	x;
	int	y;
	int	line_len;

	line_len = 6;
	x = SCREENWIDTH / 2 - line_len;
	y = SCREENHEIGHT / 2;
	while (x <= SCREENWIDTH / 2 + line_len)
		cub3d_mlx_pixel_put(map, x++, y, 0x009F9F9F);
	x = SCREENWIDTH / 2;
	y = SCREENHEIGHT / 2 - line_len;
	while (y <= SCREENHEIGHT / 2 + line_len)
		cub3d_mlx_pixel_put(map, x, y++, 0x009F9F9F);
}

void	put_portal_gun(t_map *map)
{
	__uint32_t	color;
	int			x;
	int			y;

	y = -1;
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		while (++x < SCREENWIDTH)
		{
			map->tex[map->portal_gun_index].tex_x
				= x * map->tex[map->portal_gun_index].tex_width
				/ SCREENWIDTH;
			map->tex[map->portal_gun_index].tex_y
				= y * map->tex[map->portal_gun_index].tex_height
				/ SCREENHEIGHT;
			color = choose_pixel_color(map, map->portal_gun_index);
			if (color & 0x00FFFFFF)
				cub3d_mlx_pixel_put(map, x, y, color);
		}
	}
}

void	draw_shooting_elements(t_map *map)
{
	draw_shooting_lines(map);
	put_portal_gun(map);
}
