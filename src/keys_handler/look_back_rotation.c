/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_back_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:12:54 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 17:59:31 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

static void	set_rot_2_front_off(t_map *map)
{
	map->dir_x = map->org_dir_x;
	map->dir_y = map->org_dir_y;
	map->plane_x = map->org_plane_x;
	map->plane_y = map->org_plane_y;
	map->rot_front = 0;
	map->rotate_to_back = 1;
	map->look_back_key_prev = 0;
	map->angle = ANGLE;
	map->look_back_is_active = 0;
}

static void	set_rot_2_back_off(t_map *map)
{
	map->dir_x = map->opp_dir_x;
	map->dir_y = map->opp_dir_y;
	map->plane_x = map->opp_plane_x;
	map->plane_y = map->opp_plane_y;
	map->rot_back = 0;
	map->rotate_to_back = 1;
}

static void	rot_back_manager(t_map *map)
{
	map->rot_back = 1;
	map->rot_front = 0;
	if (map->region == 1 && ((get_region(map, 1) == 1
				&& map->opp_dir_x >= map->dir_x)
			|| get_region(map, 1) == 2))
		set_rot_2_back_off(map);
	else if (map->region == 2 && ((get_region(map, 1) == 2
				&& map->opp_dir_y >= map->dir_y)
			|| get_region(map, 1) == 3))
		set_rot_2_back_off(map);
	else if (map->region == 3 && ((get_region(map, 1) == 3
				&& map->opp_dir_x <= map->dir_x)
			|| get_region(map, 1) == 4))
		set_rot_2_back_off(map);
	else if (map->region == 4 && ((get_region(map, 1) == 4
				&& map->opp_dir_y <= map->dir_y)
			|| get_region(map, 1) == 1))
		set_rot_2_back_off(map);
}

static void	rot_front_manager(t_map *map)
{
	map->rot_front = 1;
	map->rot_back = 0;
	if (map->region == 1 && ((get_region(map, 2) == 3
				&& map->org_dir_x >= map->dir_x)
			|| get_region(map, 2) == 2))
		set_rot_2_front_off(map);
	else if (map->region == 2 && ((get_region(map, 2) == 4
				&& map->org_dir_y >= map->dir_y)
			|| get_region(map, 2) == 3))
		set_rot_2_front_off(map);
	else if (map->region == 3 && ((get_region(map, 2) == 3
				&& map->org_dir_x <= map->dir_x)
			|| get_region(map, 2) == 4))
		set_rot_2_front_off(map);
	else if (map->region == 4 && ((get_region(map, 2) == 4
				&& map->org_dir_y <= map->dir_y)
			|| get_region(map, 2) == 1))
		set_rot_2_front_off(map);
}

void	rot_180(t_map *map, char flag)
{
	map->angle = ANGLE * 7;
	if (flag == 'R')
		rot_back_manager(map);
	else if (flag == 'L')
		rot_front_manager(map);
}
