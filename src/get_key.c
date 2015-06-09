/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:25:13 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 17:39:11 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	right_left(char *b, int *pos, t_tab **arg)
{
	int col;

	col = (*arg)->pos_max / (*arg)->row;
	if (RIGHT(b))
	{
		if ((*pos) + (*arg)->row - 1 > (*arg)->pos_max)
			(*pos) = (*pos) - ((*arg)->row - 1) * col;
		else
			(*pos) += (*arg)->row - 1;
	}
	if (LEFT(b))
	{
		if ((*pos) - (*arg)->row - 1 < 0)
		{
			if (col * ((*arg)->row - 1) + (*pos) > (*arg)->pos_max)
				(*pos) = (*arg)->pos_max;
			else
				(*pos) = col * ((*arg)->row - 1) + (*pos);
		}
		else
			(*pos) -= (*arg)->row - 1;
	}
}

void		get_key(char *b, int *pos, t_tab **arg)
{
	if (UP(b))
		(*pos)--;
	else if (DOWN(b))
		(*pos)++;
	if (SPACE(b))
	{
		(*arg)->select[*pos] = ((*arg)->select[*pos] == 0) ? 1 : 0;
		(*pos) += ((*arg)->select[*pos] == 1) ? 1 : 0;
	}
	if (RETURN(b) || ESC(b))
		exit_select(*arg, b);
	if (DELETE(b) || BACKSPACE(b))
		delete_arg(arg, pos);
	right_left(b, pos, arg);
}
