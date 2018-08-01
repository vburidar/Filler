/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vburidar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:15:01 by vburidar          #+#    #+#             */
/*   Updated: 2018/02/23 17:09:01 by vburidar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"
#include "LIBFT/libft.h"

void	ft_print_result(int a, int b, t_lst *start)
{
	char *x;
	char *y;

	x = ft_itoa_dec(a);
	y = ft_itoa_dec(b);
	ft_putstr(x);
	ft_putstr(" ");
	ft_putstr(y);
	ft_putstr("\n");
	free(x);
	free(y);
	ft_free_piece(start);
}
