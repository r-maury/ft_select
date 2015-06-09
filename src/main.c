/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 13:43:42 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 18:17:58 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	check(char **av, char **env)
{
	if (!av[1])
		ft_putendl("Usage: ft_select arg1 arg2 arg3 ...");
	if (!env[0])
		ft_putendl("Environment Not Found");
	if (!av[1] || !env[0])
		exit(1);
}

static int	fixpos(int pos, int max, int min)
{
	if (pos < min)
		pos = max;
	else if (pos > max)
		pos = min;
	return (pos);
}

int			main(int ac, char **av, char **env)
{
	t_tab	*arg;
	char	*tty;
	char	b[3];
	int		pos;

	check(av, env);
	pos = 0;
	arg = tab_setup(av + 1, ac);
	tty = ttyname(0);
	g_fd = open(tty, O_WRONLY | O_NOCTTY);
	signal(SIGINT, interupt);
	signal(SIGTSTP, stop);
	signal(SIGCONT, handle_cont);
	term_init();
	while (1)
	{
		pos = fixpos(pos, arg->pos_max, 0);
		ft_putstr_fd(tgetstr("cl", NULL), g_fd);
		order_list(arg, pos);
		bzero(b, 3);
		read(0, b, 3);
		get_key(b, &pos, &arg);
	}
	return (0);
}
