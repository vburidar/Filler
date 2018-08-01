/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:14:08 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/23 16:09:57 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "LIBFT/libft.h"
#include "filler.h"

int		ft_valid_spot(int **tab, t_valid val, int n_p, t_lst *piece)
{
	int		overlap;

	overlap = 0;
	while (piece)
	{
		if (val.curs.x + piece->x >= val.max.x
			|| val.curs.y + piece->y >= val.max.y
			|| tab[val.curs.x + piece->x][val.curs.y + piece->y]
			== 2 - (n_p / 2))
			return (0);
		if (tab[val.curs.x + piece->x][val.curs.y + piece->y] == n_p)
			overlap = overlap + 1;
		piece = piece->nxt;
	}
	if (overlap == 1)
		return (1);
	return (0);
}

t_coord	ft_get_max(int **tab)
{
	t_coord	cursor;
	t_coord	max;

	cursor.x = 0;
	cursor.y = 0;
	while (tab[cursor.x])
		cursor.x++;
	max.x = cursor.x;
	while (tab[0][cursor.y] >= 0)
		cursor.y++;
	max.y = cursor.y;
	return (max);
}

int		ft_find_spot(int **tab, t_lst *piece, t_coord min)
{
	t_valid	val;
	t_lst	*position;

	position = NULL;
	val.curs.x = 0;
	val.curs.y = 0;
	val.max = ft_get_max(tab);
	while (tab[val.curs.x])
	{
		while (tab[val.curs.x][val.curs.y] >= 0)
		{
			if (ft_valid_spot(tab, val, min.n_p, piece))
				position = ft_add_position(position, val.curs);
			val.curs.y++;
		}
		val.curs.y = 0;
		val.curs.x++;
	}
	if (ft_best_position(tab, position, min, piece) == 0)
		return (0);
	return (1);
}

int		ft_get_player(void)
{
	char	*player;
	int		nb_player;

	nb_player = 0;
	get_next_line(0, &player);
	if (ft_strlen(player) > 10)
		nb_player = ft_atoi(player + 10);
	free(player);
	return (nb_player);
}

int		main(void)
{
	t_lst	*piece;
	int		**tab;
	t_coord	min;

	min.n_p = ft_get_player();
	while (1 && min.n_p != 0)
	{
		if (!(piece = malloc(sizeof(t_lst))))
			return (0);
		piece->nxt = NULL;
		tab = NULL;
		piece->x = -99;
		if ((tab = ft_get_data(tab, piece)) == NULL)
			return (ft_free_tapi(tab, piece));
		min = ft_resize_piece(piece, min);
		if (ft_find_spot(tab, piece, min) == 0)
			return (ft_free_tapi(tab, piece));
		ft_free_tapi(tab, piece);
	}
	return (0);
}
