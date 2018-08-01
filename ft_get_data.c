/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 14:54:39 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/23 17:00:24 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "LIBFT/libft.h"
#include "filler.h"

int		**ft_get_tab(int **tab, int j, char *line)
{
	int		i;

	i = 4;
	if (tab[j] == NULL)
	{
		if (!(tab[j] = malloc(ft_strlen(line) * sizeof(int))))
			return (NULL);
	}
	while (ft_strlen(line) > 4 && line[i])
	{
		if (line[i] == 'X' || line[i] == 'x')
			tab[j][i - 4] = 2;
		else if (line[i] == 'O' || line[i] == 'o')
			tab[j][i - 4] = 1;
		else if (line[i] == '.')
			tab[j][i - 4] = 0;
		tab[j][i - 3] = -1;
		i++;
	}
	return (tab);
}

t_lst	*ft_get_piece(char *line, int line_piece, t_lst *piece)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '*')
		{
			if (piece->x != -99)
			{
				if (!(piece->nxt = malloc(sizeof(t_lst))))
					return (NULL);
				piece = piece->nxt;
			}
			piece->nxt = NULL;
			piece->y = i;
			piece->x = line_piece;
		}
		i++;
	}
	return (piece);
}

int		**ft_modif_tab(char *line, int **tab, int *j)
{
	static int nline;

	if (line[0] == 'P' && line[1] == 'l' && ft_strlen(line) > 8)
	{
		if ((nline = ft_atoi(line + 7)) < 0)
			return (NULL);
		if (!(tab = malloc((nline + 10) * sizeof(int*))))
			return (NULL);
		ft_bnull((void**)tab, nline + 10);
	}
	if (line[0] >= '0' && line[0] <= '9' && line[3] == ' '
			&& tab != NULL && nline > *j)
	{
		tab = ft_get_tab(tab, *j, line);
		*j = *j + 1;
	}
	return (tab);
}

int		**ft_get_data(int **tab, t_lst *piece)
{
	char	*line;
	int		line_piece;
	int		j;
	int		max_ligne;

	max_ligne = 1000;
	j = 0;
	line_piece = 0;
	tab = NULL;
	while (get_next_line(0, &line) == 1 && line[0] != '\0')
	{
		tab = ft_modif_tab(line, tab, &j);
		if (line[0] == 'P' && line[1] == 'i' && ft_strlen(line) > 5)
			max_ligne = ft_atoi(line + 6);
		if (line[0] == '.' || line[0] == '*')
		{
			piece = ft_get_piece(line, line_piece, piece);
			line_piece++;
		}
		free(line);
		if (line_piece >= max_ligne && max_ligne > 0)
			return (tab);
	}
	free(line);
	return (NULL);
}
