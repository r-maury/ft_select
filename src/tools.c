/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 15:35:45 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 17:46:00 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	**colorize(char **av, char **list)
{
	struct stat	type;
	int			i;

	i = 0;
	while (av[i])
	{
		lstat(av[i], &type);
		if (S_ISDIR(type.st_mode))
			list[i] = ft_strjoin("\033[36m", av[i]);
		else if (S_ISREG(type.st_mode))
			list[i] = ft_strjoin("\033[32m", av[i]);
		else if (S_ISLNK(type.st_mode))
			list[i] = ft_strjoin("\033[33m", av[i]);
		else
			list[i] = ft_strdup(av[i]);
		i++;
	}
	return (list);
}

void	order_list(t_tab *arg, int pos)
{
	int				i;
	int				len;
	struct winsize	ws;

	ioctl(0, TIOCGWINSZ, &ws);
	i = 1;
	arg->row = ws.ws_row;
	arg->col = ws.ws_col;
	arg->col_size = ft_strlen(arg->list[0]);
	while (arg->list[i])
	{
		len = ft_strlen(arg->list[i]);
		if (arg->col_size < len)
			arg->col_size = len;
		i++;
	}
	arg->col_size += 3;
	if (arg->pos_max + 5 > ws.ws_col / arg->col_size * ws.ws_row)
		ft_putendl_fd("\033[31mWindow too small, please enlarge.", g_fd);
	else
		display_list(arg, pos);
}
