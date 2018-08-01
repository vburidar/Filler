/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_middle_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:50:46 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/22 14:40:57 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coord	ft_middle_tab(int **tab, t_lst *start)
{
	t_coord	ret;

	ret.x = 0;
	ret.y = 0;
	while (tab[ret.x])
		ret.x++;
	while (tab[0][ret.y] >= 0)
		ret.y++;
	if (ret.x / 2 > start->x)
		ret.x = start->x + ret.x / 2;
	else
		ret.x = start->x - ret.x / 2;
	if (ret.y / 2 > start->y)
		ret.y = start->y + ret.y / 2;
	else
		ret.y = start->y - ret.y / 2;
	return (ret);
}
