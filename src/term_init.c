/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:12:24 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 17:45:33 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	term_init(void)
{
	char			*name;
	struct termios	term;

	if ((name = getenv("TERM")) == NULL)
	{
		ft_putendl("getenv error");
		exit(1);
	}
	if (tgetent(NULL, name) == ERR)
	{
		ft_putendl("tgetent error");
		exit(1);
	}
	if (tcgetattr(0, &term) == -1)
	{
		ft_putendl("tgetattr error");
		exit(1);
	}
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VTIME] = 1;
	term.c_cc[VMIN] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	ft_putstr_fd(tgetstr("vi", NULL), g_fd);
	ft_putstr_fd(tgetstr("ti", NULL), g_fd);
}