/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 21:34:35 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/17 15:25:34 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			min_size(t_tetri *tetri)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	while (tetri)
	{
		tetri = tetri->next;
		i++;
	}
	i *= 4;
	while (j * j < i)
		j++;
	return (j);
}

char		**make_square(int size)
{
	char	**map;
	int		i;

	if (!(map = (char **)malloc(sizeof(char *) * (size + 1))))
		error();
	i = -1;
	while (++i < size)
	{
		if (!(map[i] = (char *)malloc(size + 2)))
			error();
		ft_memset(map[i], '.', size);
		map[i][size] = '\n';
		map[i][size + 1] = '\0';
	}
	map[i] = NULL;
	return (map);
}

void		print_map(char **map)
{
	int		i;
	int		size;

	size = ft_strlen(map[0]) - 2;
	i = -1;
	while (++i <= size)
		ft_putstr(map[i]);
}
