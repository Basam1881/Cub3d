/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_back_regions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 11:16:28 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 17:59:25 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/cub3d.h"

static int	get_next_dir_region(t_map *map, int flag)
{
	double	next_dir_x;
	double	next_dir_y;
	double	angle;

	angle = map->angle;
	if (flag == 2)
		angle *= -1;
	next_dir_x = map->dir_x * cos(angle) - map->dir_y * sin(angle);
	next_dir_y = map->dir_x * sin(angle) + map->dir_y * cos(angle);
	if (next_dir_x >= 0 && next_dir_y > 0)
		return (1);
	else if (next_dir_x < 0 && next_dir_y >= 0)
		return (2);
	else if (next_dir_x <= 0 && next_dir_y < 0)
		return (3);
	else if (next_dir_x > 0 && next_dir_y <= 0)
		return (4);
	return (0);
}

int	get_region(t_map *map, int flag)
{
	if (!flag)
	{
		if (map->opp_dir_x >= 0 && map->opp_dir_y > 0)
			return (1);
		else if (map->opp_dir_x < 0 && map->opp_dir_y >= 0)
			return (2);
		else if (map->opp_dir_x <= 0 && map->opp_dir_y < 0)
			return (3);
		else if (map->opp_dir_x > 0 && map->opp_dir_y <= 0)
			return (4);
	}
	if (flag == 1 || flag == 2)
		return (get_next_dir_region(map, flag));
	return (0);
}
