/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:06:10 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/19 22:24:18 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	elements_checker(t_map *map, int i, int *j)
{
	if (!(ft_strncmp(&map->map[i][*j], "NO", 2)))
		return (3);
	else if (!(ft_strncmp(&map->map[i][*j], "SO", 2)))
		return (4);
	else if (!(ft_strncmp(&map->map[i][*j], "WE", 2)))
		return (5);
	else if (!(ft_strncmp(&map->map[i][*j], "EA", 2)))
		return (6);
	else if (!(ft_strncmp(&map->map[i][*j], "FT", 2)))
		return (7);
	else if (!(ft_strncmp(&map->map[i][*j], "CT", 2)))
		return (8);
	else if (map->map[i][*j] == 'F')
		return (1);
	else if (map->map[i][*j] == 'C')
		return (2);
	return (0);
}

void	is_newline(char *m, int *j, int *i)
{
	(*i)++;
	while (m[*i] == 32 || m[*i] == 9
		|| m[*i] == 11 || m[*i] == 12 || m[*i] == 13)
		(*i)++;
	while (m[*i] == '1')
	{
		(*i)++;
		while (m[*i] == 32 || m[*i] == 9
			|| m[*i] == 11 || m[*i] == 12 || m[*i] == 13)
			(*i)++;
		if (m[*i] == '\n')
		{
			*j = 1;
			(*i)++;
		}
	}
}

int	check_map_lines(char *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(m) && m[i] != '\0')
	{
		if (m[i] == '\n')
			is_newline(m, &j, &i);
		if (j && i && m[i - 1] == '\n' && m[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	is_it_invalid(t_map *map, int i, int j)
{
	if ((map->level[0][j] != 1 && map->level[0][j] != -1)
		|| (map->level[i][0] != 1 && map->level[i][0] != -1)
		|| (map->level[map->height - 1][j] != 1
		&& map->level[map->height - 1][j] != -1)
		|| (map->level[i][map->width - 1] != 1
		&& map->level[i][map->width - 1] != -1)
		|| (map->level[i][j] == -1
			&& ((i && ((map->level[i - 1][j] != 1
			&& map->level[i - 1][j] != -1)
		|| (j && (map->level[i - 1][j - 1] != 1
		&& map->level[i - 1][j - 1] != -1))
			|| (j != map->width - 1 && (map->level[i - 1][j + 1] != 1
			&& map->level[i - 1][j + 1] != -1))))
			|| (i != map->height - 1 && ((map->level[i + 1][j] != 1
			&& map->level[i + 1][j] != -1)
			|| (j && (map->level[i + 1][j - 1] != 1
			&& map->level[i + 1][j - 1] != -1))
			|| (j != map->width - 1 && (map->level[i + 1][j + 1] != 1
			&& map->level[i + 1][j + 1] != -1))))
			|| (j && (map->level[i][j - 1] != 1
			&& map->level[i][j - 1] != -1))
			|| (j != map->width - 1 && (map->level[i][j + 1] != 1
			&& map->level[i][j + 1] != -1)))))
		return (1);
	return (0);
}

void	map_checker(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (is_it_invalid(map, i, j))
			{
				map->parse_error_row = i;
				map->parse_error_col = j;
				error(15, map);
			}
			j++;
		}
		i++;
	}
}
