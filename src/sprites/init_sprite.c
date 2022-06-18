/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:04:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 18:32:36 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	sprite_height(t_map *map, int i)
{
	choose_sprite_height(map, i);
	map->sc.draw_start_y = -map->sc.sprite_height / 2 + SCREENHEIGHT / 2
		+ map->sc.move;
	if (map->sc.draw_start_y < 0)
		map->sc.draw_start_y = 0;
	map->sc.draw_end_y = map->sc.sprite_height / 2 + SCREENHEIGHT / 2
		+ map->sc.move;
	if (map->sc.draw_end_y >= SCREENHEIGHT)
		map->sc.draw_end_y = SCREENHEIGHT - 1;
}

static void	sprite_width(t_map *map, int i)
{
	choose_moving_sprite_width(map, i);
	choose_fixed_sprite_width(map, i);
	map->sc.draw_start_x = -map->sc.sprite_width / 2 + map->sc.sprite_screen_x;
	if (map->sc.draw_start_x < 0)
		map->sc.draw_start_x = 0;
	map->sc.draw_end_x = map->sc.sprite_width / 2 + map->sc.sprite_screen_x;
	if (map->sc.draw_end_x >= SCREENWIDTH)
		map->sc.draw_end_x = SCREENWIDTH - 1;
}

static void	sprite_pos(t_map *map, int i)
{
	map->sc.sprite_x = map->sprite[map->sprite_order[i]].x - map->pos_x;
	map->sc.sprite_y = map->sprite[map->sprite_order[i]].y - map->pos_y;
	map->sc.invdet = 1.0 / (map->plane_x * map->dir_y
			- map->dir_x * map->plane_y);
	map->sc.transform_x = map->sc.invdet
		* (map->dir_y * map->sc.sprite_x - map->dir_x * map->sc.sprite_y);
	map->sc.transform_y = map->sc.invdet
		* (-map->plane_y * map->sc.sprite_x + map->plane_x * map->sc.sprite_y);
	choos_sprite_pos(map, i);
	map->sc.sprite_screen_x = (int)((SCREENWIDTH / 2)
			* (1 + map->sc.transform_x / map->sc.transform_y));
}

void	init_sprite(t_map *map, int i)
{
	sprite_pos(map, i);
	sprite_height(map, i);
	sprite_width(map, i);
}
