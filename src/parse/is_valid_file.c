/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:10:09 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 22:22:00 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_file(char *s, int flag, t_map *map)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	i -= 4;
	if (!s)
		error(5, map);
	if (!flag && ft_strncmp(&s[i], ".cub", 4))
		error(6, map);
	if (flag && ft_strncmp(&s[i], ".xpm", 4))
		error(6, NULL);
	map->fd = open(s, O_RDWR);
	if (map->fd < 1)
	{
		if (!flag)
			error(6, NULL);
		else
			error(7, map);
	}
}
