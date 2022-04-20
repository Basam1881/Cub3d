/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites_specs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:32:48 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 17:10:17 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	choose_sprite_height(t_map *map, int i)
{
	if (map->sprite[map->sprite_order[i]].type == 'C')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ COIN_HEIGHT_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'T')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ TREE_HEIGHT_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'K')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ SKELETON_HEIGHT_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'V')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ TOMBSTONE_HEIGHT_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'B')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ DEADBUSH_HEIGHT_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'L')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ LEFTARROWSIGN_HEIGHT_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'R')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ RIGHTARROWSIGN_HEIGHT_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'G')
		map->sc.sprite_height = abs((int)(SCREENHEIGHT / (map->sc.transform_y)))
			/ EXIT_HEIGHT_SCALER;
}

void	choose_moving_sprite_width(t_map *map, int i)
{
	if (map->sprite[map->sprite_order[i]].texture == map->coin_first_ind + 3)
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (COIN_WIDTH_SCALER + 7);
	else if (map->sprite[map->sprite_order[i]].texture
		== map->coin_first_ind + 2
		|| map->sprite[map->sprite_order[i]].texture
		== map->coin_first_ind + 4)
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (COIN_WIDTH_SCALER + 2);
	else if (map->sprite[map->sprite_order[i]].texture == map->coin_first_ind
		|| map->sprite[map->sprite_order[i]].texture == map->coin_first_ind + 1
		|| map->sprite[map->sprite_order[i]].texture == map->coin_first_ind + 5)
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / COIN_WIDTH_SCALER;
	else if (map->sprite[map->sprite_order[i]].type == 'G')
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (EXIT_WIDTH_SCALER);
}

void	choose_fixed_sprite_width(t_map *map, int i)
{
	if (map->sprite[map->sprite_order[i]].type == 'T')
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (TREE_WIDTH_SCALER);
	else if (map->sprite[map->sprite_order[i]].type == 'K')
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (SKELETON_WIDTH_SCALER);
	else if (map->sprite[map->sprite_order[i]].type == 'V')
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (TOMBSTONE_WIDTH_SCALER);
	else if (map->sprite[map->sprite_order[i]].type == 'B')
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (DEADBUSH_WIDTH_SCALER);
	else if (map->sprite[map->sprite_order[i]].type == 'L')
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (LEFTARROWSIGN_WIDTH_SCALER);
	else if (map->sprite[map->sprite_order[i]].type == 'R')
		map->sc.sprite_width = abs((int)(SCREENHEIGHT
					/ (map->sc.transform_y))) / (RIGHTARROWSIGN_WIDTH_SCALER);
}

void	choos_sprite_pos(t_map *map, int i)
{
	if (map->sprite[map->sprite_order[i]].type == 'C')
		map->sc.move = (int)(COIN_MOV / map->sc.transform_y);
	else if (map->sprite[map->sprite_order[i]].type == 'T')
		map->sc.move = (int)(TREE_MOV / map->sc.transform_y);
	else if (map->sprite[map->sprite_order[i]].type == 'K')
		map->sc.move = (int)(SKELETON_MOV / map->sc.transform_y);
	else if (map->sprite[map->sprite_order[i]].type == 'V')
		map->sc.move = (int)(TOMBSTONE_MOV / map->sc.transform_y);
	else if (map->sprite[map->sprite_order[i]].type == 'B')
		map->sc.move = (int)(DEADBUSH_MOV / map->sc.transform_y);
	else if (map->sprite[map->sprite_order[i]].type == 'L')
		map->sc.move = (int)(LEFTARROWSIGN_MOV / map->sc.transform_y);
	else if (map->sprite[map->sprite_order[i]].type == 'R')
		map->sc.move = (int)(RIGHTARROWSIGN_MOV / map->sc.transform_y);
	else if (map->sprite[map->sprite_order[i]].type == 'G')
		map->sc.move = (int)(EXIT_MOV / map->sc.transform_y);
}
