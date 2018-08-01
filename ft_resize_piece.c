/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:14:31 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/22 21:33:51 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LIBFT/libft.h"
#include "filler.h"

t_coord		ft_resize_piece(t_lst *piece, t_coord min)
{
	t_lst	*init;

	min.x = piece->x;
	min.y = piece->y;
	init = piece;
	while (piece)
	{
		if (piece->x < min.x)
			min.x = piece->x;
		if (piece->y < min.y)
			min.y = piece->y;
		piece = piece->nxt;
	}
	while (init)
	{
		init->x = init->x - min.x;
		init->y = init->y - min.y;
		init = init->nxt;
	}
	return (min);
}
