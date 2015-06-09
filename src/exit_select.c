/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 20:27:38 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 18:08:53 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	exit_select(t_tab *arg, char *b)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	reset_term();
	if (RETURN(b))
	{
		while (arg->list[i])
		{
			if (arg->select[i] == 1)
			{
				ret = 1;
				if (ft_strncmp("\033[3", arg->list[i], 3) == 0)
					ft_putstr(arg->list[i] + 5);
				else
					ft_putstr(arg->list[i]);
				ft_putchar(' ');
			}
			i++;
		}
		if (ret == 1)
			ft_putstr("\n");
	}
	exit(0);
}
