/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 18:28:35 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 17:44:31 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_tab	*tab_setup(char **av, int ac)
{
	t_tab	*arg;
	int		i;

	i = 0;
	arg = (t_tab*)malloc(sizeof(t_tab));
	arg->pos_max = ac - 2;
	arg->list = (char**)malloc(sizeof(char*) * (ft_tabline_count(av) + 1));
	arg->list[ft_tabline_count(av)] = 0;
	arg->list = colorize(av, arg->list);
	arg->select = (int*)malloc(sizeof(int) * ac - 1);
	i = 0;
	while (i < ac - 1)
	{
		arg->select[i] = 0;
		i++;
	}
	return (arg);
}
