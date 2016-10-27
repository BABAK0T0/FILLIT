/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:23:03 by rbohmert          #+#    #+#             */
/*   Updated: 2016/02/05 04:23:24 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			isallplaced(t_tetri *tetri)
{
	while (tetri)
	{
		if (tetri->placed == 0)
			return (0);
		tetri = tetri->next;
	}
	return (1);
}

t_point		next_pos(char **map, t_point p, int size)
{
	p.x += 1;
	while (map[p.y][p.x] != '.')
	{
		p.x += 1;
		if (p.x > size)
		{
			p.x = 0;
			p.y += 1;
			if (p.y > size)
				return (p);
		}
	}
	return (p);
}

int			solve(char **map, t_tetri *tetri, t_point p, int size)
{
	t_tetri	*tmp;
	t_point pzero;

	pzero.x = 0;
	pzero.y = 0;
	if (isallplaced(tetri))
		return (1);
	if (map[p.y][p.x] != '.')
		p = next_pos(map, p, size);
	while ((p.x < size - 2 || p.y < size) && p.y <= size)
	{
		if (!tetri->placed && place_tetriminos(map, tetri, p, 1) > 0)
		{
			tmp = tetri;
			if (solve(map, tetri->next, pzero, size))
				return (1);
			unplace_tetriminos(map, tmp, p);
		}
		p = next_pos(map, p, size);
	}
	return (0);
}
