/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmekky <mmekky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 07:20:37 by mmekky            #+#    #+#             */
/*   Updated: 2022/04/20 16:29:03 by mmekky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_portal(t_map *map, int x, int y)
{
	int				ind;
	unsigned int	color;
	double			wall_x;

	if (map->level[map->map_y][map->map_x] == 20)
	{
		ind = map->blue_portal_index;
		wall_x = map->blue.wall_x;
	}
	else
	{
		ind = map->orange_portal_index;
		wall_x = map->orange.wall_x;
	}
	map->tex[ind].tex_x = round((wall_x - (int)wall_x)
			* (double)map->tex[ind].tex_width);
	map->tex[ind].tex_y = 1.0 * (y - map->draw_start)
		/ (map->draw_end - map->draw_start) * map->tex[ind].tex_height;
	color = choose_pixel_color(map, ind);
	if (color != 1)
		cub3d_mlx_pixel_put(map, x, y, color);
}

void	init_dir_vector(t_map *map)
{
	map->dir_vector[NORTH][0] = 0;
	map->dir_vector[NORTH][1] = 1;
	map->dir_vector[SOUTH][0] = 0;
	map->dir_vector[SOUTH][1] = -1;
	map->dir_vector[EAST][0] = -1;
	map->dir_vector[EAST][1] = 0;
	map->dir_vector[WEST][0] = 1;
	map->dir_vector[WEST][1] = 0;
}

void	place_portal(t_map *map, t_portal *portal, int flag, int flag2)
{
	if (portal->active != 1)
	{
		if (valid_portal(map, portal))
		{
			portal->active = 1;
			if (map->level[portal->center_y][portal->center_x] == flag2)
			{
				if (flag == 20)
					map->orange.active = 0;
				else
					map->blue.active = 0;
			}
			map->level[portal->center_y][portal->center_x] = flag;
			portal->pos_x = portal->center_x;
			portal->pos_y = portal->center_y;
			portal->wall_tex = map->portal_wall;
		}
	}
	else if (map->level[portal->center_y][portal->center_x] == flag)
	{
		portal->active = 0;
		map->level[portal->center_y][portal->center_x] = 1;
	}
}

int	portal(int key, int x, int y, t_map *map)
{
	(void)x;
	(void)y;
	init_dir_vector(map);
	if (key == 1)
		place_portal(map, &(map->blue), 20, 21);
	else if (key == 2)
		place_portal(map, &(map->orange), 21, 20);
	if (map->blue.active && map->orange.active)
		map->portal_active = 1;
	else
		map->portal_active = 0;
	return (0);
}
