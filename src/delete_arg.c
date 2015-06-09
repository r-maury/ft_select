/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 17:01:54 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 17:29:32 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_arg(t_tab **arg, int *pos)
{
	int	i;

	if (ft_tabline_count((*arg)->list) == 1)
	{
		reset_term();
		exit(0);
	}
	free((*arg)->list[*pos]);
	(*arg)->list = ft_tabline_del((*arg)->list, *pos);
	i = (*pos);
	while (i < (*arg)->pos_max)
	{
		(*arg)->select[i] = (*arg)->select[i + 1];
		i++;
	}
	(*arg)->pos_max--;
}
