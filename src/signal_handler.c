/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 18:00:44 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 18:04:39 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	interupt(int sig)
{
	if (sig == SIGINT)
		reset_term();
	exit(0);
}

void	handle_cont(int sig)
{
	if (sig == SIGCONT)
		term_init();
}

void	stop(int sig)
{
	char			*res;
	char			cp[2];
	char			*name;
	struct termios	term;

	if (sig == SIGTSTP)
	{
		name = getenv("TERM");
		tgetent(NULL, name);
		tcgetattr(0, &term);
		cp[0] = term.c_cc[VSUSP];
		cp[1] = 0;
		signal(SIGTSTP, SIG_DFL);
		ft_putstr_fd(tgetstr("te", NULL), g_fd);
		ft_putstr_fd(tgetstr("ve", NULL), g_fd);
		ioctl(0, TIOCSTI, cp);
	}
}
