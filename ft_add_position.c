/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 17:51:18 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/23 17:06:46 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "filler.h"

t_lst	*ft_add_position(t_lst *position, t_coord cursor)
{
	t_lst	*init_position;

	if (position == NULL)
	{
		if (!(position = malloc(sizeof(t_lst))))
			return (NULL);
		init_position = position;
	}
	else
	{
		init_position = position;
		while (position->nxt)
			position = position->nxt;
		if (!(position->nxt = malloc(sizeof(t_lst))))
			return (NULL);
		position = position->nxt;
	}
	position->x = cursor.x;
	position->y = cursor.y;
	position->nxt = NULL;
	return (init_position);
}

int		ft_ray(int **tab, int nb_player, t_coord bit, t_pos *pos)
{
	int		compteur;
	int		nb_friend;

	compteur = 0;
	nb_friend = 0;
	while (bit.x >= 0 && bit.y >= 0
		&& tab[bit.x] && tab[bit.x][bit.y] >= 0
		&& compteur < (*pos).best && nb_friend < 2)
	{
		if (tab[bit.x][bit.y] == nb_player)
			nb_friend = nb_friend + 1;
		if (tab[bit.x][bit.y] == 2 - (nb_player / 2)
			&& compteur < (*pos).best)
			return (compteur);
		bit.x = bit.x + pos->vec.x;
		bit.y = bit.y + pos->vec.y;
		compteur++;
	}
	return (pos->best);
}

int		ft_find_ennemy(int **tab, int nb_player, t_lst *start, t_lst *piece)
{
	t_pos	pos;
	t_coord	bit_piece;

	pos.best = 999999;
	pos.vec.x = 1;
	pos.vec.y = 0;
	bit_piece.x = start->x + piece->y;
	bit_piece.y = start->y + piece->y;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	pos.vec.y = 1;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	pos.vec.y = -1;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	pos.vec.x = 0;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	pos.vec.y = 1;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	pos.vec.x = -1;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	pos.vec.y = 1;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	pos.vec.y = -1;
	pos.best = ft_ray(tab, nb_player, bit_piece, &pos);
	return (pos.best);
}

t_coord	ft_compare_score(int *distance, t_coord best, int score, t_lst *start)
{
	if (score < *distance)
	{
		*distance = score;
		best.x = start->x;
		best.y = start->y;
	}
	return (best);
}

int		ft_best_position(int **tab, t_lst *start, t_coord min, t_lst *piece)
{
	t_coord	best;
	int		score;
	int		distance;
	t_lst	*init_start;
	t_lst	*init_piece;

	init_start = start;
	init_piece = piece;
	distance = 999999999;
	if (start == NULL)
		return (0);
	while (start)
	{
		score = 0;
		piece = init_piece;
		while (piece)
		{
			score = score + ft_find_ennemy(tab, min.n_p, start, piece);
			piece = piece->nxt;
		}
		best = ft_compare_score(&distance, best, score, start);
		start = start->nxt;
	}
	ft_print_result(best.x - min.x, best.y - min.y, init_start);
	return (1);
}
