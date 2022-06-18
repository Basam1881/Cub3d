/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:17:37 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 17:59:36 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

void	init_look_back(t_map *map)
{
	map->look_back_is_active = 1;
	map->look_back_key_prev = 1;
	map->rotate_to_back = 0;
	map->org_dir_x = map->dir_x;
	map->org_dir_y = map->dir_y;
	map->org_plane_x = map->plane_x;
	map->org_plane_y = map->plane_y;
	map->opp_dir_x = map->dir_x * -1;
	map->opp_dir_y = map->dir_y * -1;
	map->opp_plane_x = map->plane_x * -1;
	map->opp_plane_y = map->plane_y * -1;
}

void	look_back(t_map *map)
{
	if (map->look_back_key)
	{
		if (map->look_back_is_active && map->rot_front)
			map->rotate_to_back = 0;
		else
			if (map->look_back_key_prev == 0)
				init_look_back(map);
		map->region = get_region(map, 0);
		if (!map->rotate_to_back)
			rot_180(map, 'R');
	}
	if ((!map->look_back_key || map->rot_front) && map->look_back_key_prev)
		rot_180(map, 'L');
}
