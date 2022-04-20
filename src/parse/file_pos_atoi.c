/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pos_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:39:32 by bnaji             #+#    #+#             */
/*   Updated: 2022/04/15 22:04:51 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_file_pos_atoi(char *str)
{
	int						i;
	unsigned long long		nb;
	int						number_exist_flag;

	nb = 0;
	i = 0;
	number_exist_flag = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb > 255)
			return (-1);
		i++;
		number_exist_flag = 1;
	}
	if (!number_exist_flag)
		return (-1);
	return (nb);
}
