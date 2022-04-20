/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_elements_effects.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:04:59 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/15 20:16:30 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	sprite_minimap_exit(t_map *map)
{
	if (map->exit_is_open)
	{
		if (!map->fmm.exit_flag && map->fmm.exit_cnt == 5)
			map->fmm.exit_flag = 1;
		else if (map->fmm.exit_flag && map->fmm.exit_cnt == 5)
			map->fmm.exit_flag = 0;
		if (map->fmm.exit_cnt == 5)
			map->fmm.exit_cnt = 0;
		map->fmm.exit_cnt++;
	}
}
