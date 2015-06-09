/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 16:50:27 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 18:12:09 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print(t_tab *arg, int pos, int i)
{
	if (arg->select[i] == 1)
		ft_putstr_fd(tgetstr("mr", NULL), g_fd);
	if (i == pos)
		ft_putstr_fd(tgetstr("us", NULL), g_fd);
	ft_putendl_fd(arg->list[i], g_fd);
	ft_putstr_fd(tgetstr("me", NULL), g_fd);
}

void		display_list(t_tab *arg, int pos)
{
	int	i;
	int	row;
	int	n_col;

	i = 0;
	row = 0;
	n_col = 0;
	while (arg->list[i])
	{
		if ((row + 1) == arg->row)
		{
			row = 0;
			n_col += arg->col_size;
		}
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), n_col, row), g_fd);
		if (arg->select[i] == 1 || i == pos)
			print(arg, pos, i);
		else
			ft_putendl_fd(arg->list[i], g_fd);
		i++;
		row++;
	}
}
