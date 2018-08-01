/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:17:26 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/23 17:06:05 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

void	ft_free_tab(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_piece(t_lst *piece)
{
	t_lst *tmp;

	while (piece)
	{
		tmp = piece->nxt;
		free(piece);
		piece = tmp;
	}
}

int		ft_free_tapi(int **tab, t_lst *piece)
{
	if (tab)
		ft_free_tab(tab);
	ft_free_piece(piece);
	return (0);
}
