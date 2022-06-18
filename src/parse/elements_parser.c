/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:06:02 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 22:23:27 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	store(t_map *map, int flag, int *tmp)
{
	if (flag == 1)
	{
		map->fr = tmp[0];
		map->fg = tmp[1];
		map->fb = tmp[2];
	}
	else if (flag == 2)
	{
		map->cr = tmp[0];
		map->cg = tmp[1];
		map->cb = tmp[2];
	}
}

static void	store_rgb(t_map *map, int i, int *j, int flag)
{
	int	tmp[3];
	int	k;

	k = -1;
	while (++k < 3)
	{
		tmp[k] = ft_file_pos_atoi(&map->map[i][*j]);
		if (tmp[k] < 0)
			error(4, map);
		skipper(map, i, j, 2);
		skipper(map, i, j, 1);
		if (k != 2 && map->map[i][*j] == ',')
			(*j)++;
		else if (k != 2 && map->map[i][*j] != ',')
			error(4, map);
		if (k != 2)
			skipper(map, i, j, 1);
	}
	store(map, flag, tmp);
}

static void	store_elements(t_map *map, int i, int *j, int flag)
{
	if (flag == 1)
		store_rgb(map, i, j, 1);
	else if (flag == 2)
		store_rgb(map, i, j, 2);
	else
	{
		check_file(&map->map[i][*j], 1, map);
		if (flag == 3 && !map->fixed_files[0])
			map->fixed_files[0] = ft_strdup_2_space(&map->map[i][*j]);
		else if (flag == 4 && !map->fixed_files[1])
			map->fixed_files[1] = ft_strdup_2_space(&map->map[i][*j]);
		else if (flag == 5 && !map->fixed_files[2])
			map->fixed_files[2] = ft_strdup_2_space(&map->map[i][*j]);
		else if (flag == 6 && !map->fixed_files[3])
			map->fixed_files[3] = ft_strdup_2_space(&map->map[i][*j]);
		else if (flag == 7 && !map->fixed_files[4])
			map->fixed_files[4] = ft_strdup_2_space(&map->map[i][*j]);
		else if (flag == 8 && !map->fixed_files[5])
			map->fixed_files[5] = ft_strdup_2_space(&map->map[i][*j]);
		else
			error(4, map);
	}
}

static void	elements_line_looper(t_map *map, int i, int *tmp)
{
	int	j;

	j = 0;
	skipper(map, i, &j, 1);
	if (!map->map[i][j])
		error(4, map);
	*tmp = elements_checker(map, i, &j);
	if (*tmp >= 3)
		j += 2;
	else if (*tmp == 1 || *tmp == 2)
		j++;
	skipper(map, i, &j, 1);
	if (!(map->map[i][j - 1] == 32
		|| (map->map[i][j - 1] >= 9 && map->map[i][j - 1] <= 13)))
		error(4, map);
	store_elements(map, i, &j, *tmp);
	skipper(map, i, &j, 0);
	skipper(map, i, &j, 1);
	if (map->map[i][j])
		error(4, map);
}

void	elements_parser(t_map *map)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (map->map[i] && i < N_ELEMENTS)
	{
		elements_line_looper(map, i, &tmp);
		i++;
	}
	if (i != N_ELEMENTS)
		error(4, map);
}
