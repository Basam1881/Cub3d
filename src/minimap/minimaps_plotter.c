/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimaps_plotter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:05:15 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/17 14:03:03 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	bring_color(int flag)
{
	int	color;

	color = 0;
	if (flag == 1)
		color = INVISIBLEWALLCOLOR;
	else if (flag == 0)
		color = INVISIBLEEMPTYCOLOR;
	else if (flag == -11)
		color = INVISIBLECOINCOLOR;
	else if (flag == -12)
		color = INVISIBLEEXITCOLOR;
	else if (flag == -13)
		color = INVISIBLESPRITESCOLOR;
	else if (flag >= 4 && flag <= 11)
		color = INVISIBLECLOSEDDOORCOLOR;
	else if (flag == 3)
		color = INVISIBLEOPENEDDOORCOLOR;
	else if (flag == 20 || flag == 21)
		color = INVISIBLEPORTALCOLOR;
	else if (flag == -2)
		color = INVISIBLEPLAYERCOLOR;
	else if (flag == -1)
		color = INVISIBLENOTHINGCOLOR;
	return (color);
}

void	draw_minimap_pixel(t_minimap *minimap, int x, int y, int flag)
{
	char	*dst;
	int		color;

	color = bring_color(flag);
	if (x < SCREENWIDTH && y < SCREENHEIGHT && x >= 0 && y >= 0)
	{
		dst = minimap->addr + (y * minimap->line_len + x * (minimap->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
