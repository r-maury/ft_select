/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 17:22:03 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 17:44:01 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	reset_term(void)
{
	struct termios	term;
	char			*name;

	name = getenv("TERM");
	tgetent(NULL, name);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	tcsetattr(0, TCSADRAIN, &term);
	ft_putstr_fd(tgetstr("cl", NULL), g_fd);
	ft_putstr_fd(tgetstr("te", NULL), g_fd);
	ft_putstr_fd(tgetstr("ve", NULL), g_fd);
}
