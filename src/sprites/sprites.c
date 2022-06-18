/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:37 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 18:32:56 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sort_sprites_order(t_map *map)
{
	int			i;
	int			j;
	int			ord;
	double		dist;

	i = -1;
	while (++i < map->sprite_cnt)
	{
		j = i;
		while (++j < map->sprite_cnt)
		{
			if (map->sprite_distance[j] > map->sprite_distance[i])
			{
				ord = map->sprite_order[j];
				map->sprite_order[j] = map->sprite_order[i];
				map->sprite_order[i] = ord;
				dist = map->sprite_distance[j];
				map->sprite_distance[j] = map->sprite_distance[i];
				map->sprite_distance[i] = dist;
			}
		}
	}
}

void	sprite_order_manager(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->sprite_cnt)
	{
		map->sprite_order[i] = i;
		map->sprite_distance[i] = ((map->pos_x - map->sprite[i].x)
				* (map->pos_x - map->sprite[i].x)
				+ (map->pos_y - map->sprite[i].y)
				* (map->pos_y - map->sprite[i].y));
		i++;
	}
	sort_sprites_order(map);
}

void	plot_sprite_vertically(t_map *map, int stripe, int i)
{
	int	y;
	int	d;
	int	color;

	y = map->sc.draw_start_y;
	while (y < map->sc.draw_end_y)
	{
		d = (y - map->sc.move) * 256 - SCREENHEIGHT * 128
			+ map->sc.sprite_height * 128;
		map->tex[map->sprite[map->sprite_order[i]].texture].tex_y
			= ((d * map->tex[map->sprite[map->sprite_order[i]].texture]
					.tex_height) / map->sc.sprite_height) / 256;
		color = choose_pixel_color(map, map
				->sprite[map->sprite_order[i]].texture);
		if (((color & 0x00FFFFFF)
				&& map->sprite[map->sprite_order[i]].type != 'G')
			|| map->sprite[map->sprite_order[i]].type == 'G')
			cub3d_mlx_pixel_put(map, stripe, y, color);
		y++;
	}
}

void	draw_sprite(t_map *map, int i)
{
	int	stripe;

	stripe = map->sc.draw_start_x;
	while (stripe < map->sc.draw_end_x)
	{
		map->tex[map->sprite[map->sprite_order[i]].texture].tex_x
			= (int)(256 * (stripe - (-map->sc.sprite_width / 2
						+ map->sc.sprite_screen_x))
				* map->tex[map->sprite[map->sprite_order[i]].texture].tex_width
				/ map->sc.sprite_width) / 256;
		if (map->sc.transform_y > 0 && stripe > 0
			&& stripe < SCREENWIDTH
			&& map->sc.transform_y < map->zbuffer[stripe])
			plot_sprite_vertically(map, stripe, i);
		stripe++;
	}
}

void	create_sprites(t_map *map)
{
	int			i;

	sprite_order_manager(map);
	i = 0;
	while (i < map->sprite_cnt)
	{
		init_sprite(map, i);
		draw_sprite(map, i);
		i++;
	}
}
