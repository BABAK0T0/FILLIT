/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_unplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 18:03:24 by nrandria          #+#    #+#             */
/*   Updated: 2015/12/16 19:10:32 by nrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point		next_pos_tetr(t_point p, char *s, int nbhash)
{
	int		i;
	int		j;
	int		count;

	if (nbhash != 0)
	{
		i = -1;
		count = 0;
		while (count < nbhash)
		{
			i++;
			count += (s[i] == '#') ? 1 : 0;
		}
		j = i + 1;
		while (s[j] != '#')
			j++;
		p.x += (j - i == 1) ? 1 : 0;
		p.x -= (j - i == 3) ? 2 : 0;
		p.y += (j - i == 3) ? 1 : 0;
		p.x -= (j - i == 4) ? 1 : 0;
		p.y += (j - i == 4) ? 1 : 0;
		p.y += (j - i == 5) ? 1 : 0;
	}
	return (p);
}

int			place_tetriminos(char **map, t_tetri *tetri, t_point p, int nbhash)
{
	t_point	pnext;
	int		size;
	int		ret;

	map[p.y][p.x] = tetri->letter;
	if (nbhash == 4)
	{
		tetri->placed = 1;
		return (1);
	}
	ret = 0;
	size = ft_strlen(map[0]) - 2;
	pnext = next_pos_tetr(p, tetri->piece, nbhash);
	if (pnext.x <= size && pnext.y <= size && map[pnext.y][pnext.x] == '.')
	{
		nbhash += 1;
		if ((ret = place_tetriminos(map, tetri, pnext, nbhash)) > 0)
			return (1);
	}
	map[p.y][p.x] = '.';
	if (ret == -1)
		return (ret);
	return ((pnext.y > size) ? -1 : 0);
}

void		unplace_tetriminos(char **map, t_tetri *tetri, t_point p)
{
	int		i;

	i = 1;
	map[p.y][p.x] = '.';
	while (i != 4)
	{
		p = next_pos_tetr(p, tetri->piece, i);
		map[p.y][p.x] = '.';
		i++;
	}
	tetri->placed = 0;
}
