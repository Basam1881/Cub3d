/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fm_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:07:18 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/18 17:36:39 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_visible_area(char *dst)
{
	if (*(unsigned int *)dst == INVISIBLEWALLCOLOR)
		*(unsigned int *)dst = VISIBLEWALLCOLOR;
	else if (*(unsigned int *)dst == INVISIBLEEMPTYCOLOR)
		*(unsigned int *)dst = VISIBLEEMPTYCOLOR;
	else if (*(unsigned int *)dst == INVISIBLECOINCOLOR)
		*(unsigned int *)dst = VISIBLECOINCOLOR;
	else if (*(unsigned int *)dst == INVISIBLECLOSEDDOORCOLOR)
		*(unsigned int *)dst = VISIBLECLOSEDDOORCOLOR;
	else if (*(unsigned int *)dst == INVISIBLEOPENEDDOORCOLOR)
		*(unsigned int *)dst = VISIBLEOPENEDDOORCOLOR;
	else if (*(unsigned int *)dst == INVISIBLEPORTALCOLOR)
		*(unsigned int *)dst = VISIBLEPORTALCOLOR;
	else if (*(unsigned int *)dst == INVISIBLEEXITCOLOR)
		*(unsigned int *)dst = VISIBLEEXITCOLOR;
	else if (*(unsigned int *)dst == INVISIBLESPRITESCOLOR)
		*(unsigned int *)dst = VISIBLESPRITESCOLOR;
}

int	is_visible(char *dst)
{
	if (!dst)
		return (0);
	if (*(unsigned int *)dst == VISIBLEWALLCOLOR)
		return (1);
	else if (*(unsigned int *)dst == VISIBLEEMPTYCOLOR)
		return (1);
	else if (*(unsigned int *)dst == VISIBLECOINCOLOR)
		return (1);
	else if (*(unsigned int *)dst == VISIBLECLOSEDDOORCOLOR)
		return (1);
	else if (*(unsigned int *)dst == VISIBLEPORTALCOLOR)
		return (1);
	else if (*(unsigned int *)dst == VISIBLEOPENEDDOORCOLOR)
		return (1);
	else if (*(unsigned int *)dst == VISIBLEEXITCOLOR)
		return (1);
	else if (*(unsigned int *)dst == VISIBLESPRITESCOLOR)
		return (1);
	return (0);
}

int	print_visibal_rays(t_minimap *minimap, char *dst, t_map *map)
{
	if (*(unsigned int *)dst == INVISIBLEWALLCOLOR
		|| *(unsigned int *)dst == INVISIBLEPORTALCOLOR
		|| *(unsigned int *)dst == INVISIBLECLOSEDDOORCOLOR)
		return (0);
	dst = minimap->addr + (map->fmm.i * minimap->line_len
			+ map->fmm.j * (minimap->bpp / 8));
	print_visible_area(dst);
	return (1);
}
