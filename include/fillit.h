/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbohmert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:14:30 by rbohmert          #+#    #+#             */
/*   Updated: 2016/02/15 19:23:32 by rbohmert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"

typedef struct		s_tetri
{
	char			*piece;
	char			letter;
	int				placed;
	struct s_tetri	*next;
}					t_tetri;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

t_tetri				*new_tetri(char *piece, char letter);
t_tetri				*get_tetri(char *s);
int					min_size(t_tetri *tetri);
char				**make_square(int size);
int					place_tetriminos(char **map, t_tetri *tetri, t_point p,
					int nbhash);
t_point				next_pos_tetr(t_point p, char *s, int nbhash);
int					isallplaced(t_tetri *tetri);
t_point				next_pos(char **map, t_point p, int size);
void				unplace_tetriminos(char **map, t_tetri *tetri, t_point p);
int					solve(char **map, t_tetri *tetri, t_point p, int j);
void				print_map(char **map);
int					check_pos(char **map, t_tetri *tetri, t_point p, int size);
void				error(void);
char				*check_tetri(char *s);
void				check2(char *s);
void				check3(char *s, int pos);
int					check4(char *s, int i);

#endif
