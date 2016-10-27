/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:23:34 by nrandria          #+#    #+#             */
/*   Updated: 2016/02/15 19:24:53 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check4(char *s, int i)
{
	int cpt;

	cpt = 0;
	if ((s[i - 1]) && s[i - 1] == '#')
		cpt++;
	if ((s[i - 5]) && s[i - 5] == '#')
		cpt++;
	if ((s[i + 1]) && s[i + 1] == '#')
		cpt++;
	if ((s[i + 5]) && s[i + 5] == '#')
		cpt++;
	if (cpt < 1)
		error();
	if (cpt == 1)
		return (0);
	if (cpt == 2)
		return (1);
	if (cpt == 3)
		return (2);
	return (0);
}

void		error(void)
{
	ft_putstr("error");
	ft_putchar('\n');
	exit(2);
}

int			main(int ac, char **av)
{
	char	**map;
	int		size;
	t_tetri	*tetri;
	t_point	p;

	if (ac != 2)
		error();
	tetri = get_tetri(av[1]);
	size = min_size(tetri);
	map = make_square(size);
	p.x = 0;
	p.y = 0;
	while (!solve(map, tetri, p, size - 1))
	{
		size++;
		free(map);
		map = make_square(size);
	}
	print_map(map);
	return (0);
}
