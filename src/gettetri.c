/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettetri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrandria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:13:57 by nrandria          #+#    #+#             */
/*   Updated: 2016/02/15 19:25:23 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			check3(char *s, int pos)
{
	int i;
	int nbh;

	i = -1;
	nbh = 0;
	while (nbh <= pos)
	{
		i++;
		if (s[i] == '#')
			nbh++;
	}
	if (s[i - 5] != '#' && s[i + 1] != '#')
		error();
}

void			check2(char *s)
{
	int			i;
	t_point		p;
	t_point		p2;

	i = 0;
	p.y = 0;
	p.x = 0;
	while (++i < 4)
	{
		p2 = next_pos_tetr(p, s, i);
		if (p.y - p2.y == -1 && (p.x - p2.x == 1 || p.x - p2.x == 2))
			check3(s, i);
		if (p.x == p2.x && p.y == p2.y)
			error();
		p = p2;
	}
}

char			*check_tetri(char *s)
{
	int			i;
	int			nbh;
	int			diag;

	i = -1;
	nbh = 0;
	diag = 0;
	while (++i < 21)
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n' && s[i] != '\0')
			error();
		if (s[i] == '#')
		{
			diag += check4(s, i);
			nbh++;
		}
		(i % 5 == 4 && s[i] != '\n') ? error() : 0;
		(i == 20 && (s[i] != '\n' && s[i] != '\0')) ? error() : 0;
	}
	if (diag < 2)
		error();
	if (nbh != 4)
		error();
	check2(s);
	return (s);
}

t_tetri			*new_tetri(char *piece, char letter)
{
	t_tetri		*tetri;

	tetri = (t_tetri *)malloc(sizeof(t_tetri));
	if (!(tetri->piece = (char *)malloc(ft_strlen(piece) + 1)))
		return (NULL);
	tetri->letter = letter;
	ft_strcpy(tetri->piece, piece);
	ft_bzero(piece, 21);
	tetri->placed = 0;
	return (tetri);
}

t_tetri			*get_tetri(char *s)
{
	char		buf[21];
	char		letter;
	int			fd;
	t_tetri		*tetri;
	t_tetri		*tmp;

	letter = 'B';
	if ((fd = open(s, O_RDONLY)) <= 0)
		error();
	ft_bzero(buf, 21);
	read(fd, buf, 21);
	tetri = new_tetri(check_tetri(buf), 'A');
	tmp = tetri;
	while (read(fd, buf, 21))
	{
		tmp->next = new_tetri(check_tetri(buf), letter);
		tmp = tmp->next;
		letter++;
		(letter > 90) ? error() : 0;
	}
	tmp->next = NULL;
	if (tmp->piece[20] != 0)
		error();
	close(fd);
	return (tetri);
}
