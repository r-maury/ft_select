/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:50:12 by rmaury            #+#    #+#             */
/*   Updated: 2015/06/09 18:03:55 by rmaury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# define UP(b) ((b[0] == 27 && b[1] == 91 && b[2] == 65) ? 1 : 0)
# define DOWN(b) ((b[0] == 27 && b[1] == 91 && b[2] == 66) ? 1 : 0)
# define RIGHT(b) ((b[0] == 27 && b[1] == 91 && b[2] == 67) ? 1 : 0)
# define LEFT(b) ((b[0] == 27 && b[1] == 91 && b[2] == 68) ? 1 : 0)
# define SPACE(b) ((b[0] == 32 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define ESC(b) ((b[0] == 27 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define RETURN(b) ((b[0] == 10 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define DELETE(b) ((b[0] == 126 && b[1] == 0 && b[2] == 0) ? 1 : 0)
# define BACKSPACE(b) ((b[0] == 127 && b[1] == 0 && b[2] == 0) ? 1 : 0)

# include "libft.h"
# include <termcap.h>
# include <curses.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <fcntl.h>

typedef struct	s_tab
{
	int			pos_max;
	int			row;
	int			col;
	int			col_size;
	int			*select;
	char		**list;
}				t_tab;

int		g_fd;

void			term_init();
void			get_key(char *b, int *pos, t_tab **arg);
void			display_list(t_tab *arg, int pos);
t_tab			*tab_setup(char **av, int ac);
void			reset_term();
void			exit_select(t_tab *arg, char *b);
void			delete_arg(t_tab **arg, int *pos);
char			**colorize(char **av, char **list);
void			order_list(t_tab *arg, int pos);
void			interupt(int sig);
void			handle_cont(int sig);
void			stop(int sig);

#endif
