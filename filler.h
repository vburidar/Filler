/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:18:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/23 17:07:16 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct		s_lst
{
	int				x;
	int				y;
	struct s_lst	*nxt;
}					t_lst;

typedef struct		s_coord
{
	int				x;
	int				y;
	int				n_p;
}					t_coord;

typedef struct		s_pos
{
	t_coord			vec;
	int				best;
}					t_pos;

typedef struct		s_valid
{
	t_coord			curs;
	t_coord			max;
}					t_valid;

int					get_next_line(int fd, char **line);
int					**ft_get_data(int **tab, t_lst *piece);
t_coord				ft_resize_piece(t_lst *piece, t_coord min);
t_lst				*ft_add_position(t_lst *position, t_coord cursor);
int					ft_best_position(int **t, t_lst *s, t_coord m, t_lst *p);
void				ft_free_tab(int **tab);
void				ft_free_piece(t_lst *piece);
int					ft_free_tapi(int **tab, t_lst *piece);
void				ft_print_tab(int **tab);
t_coord				ft_middle_tab(int **tab, t_lst *start);
void				ft_print_result(int a, int b, t_lst *start);
#endif
