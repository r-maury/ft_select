# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaury <rmaury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 17:47:23 by rmaury            #+#    #+#              #
#    Updated: 2015/06/09 18:05:22 by rmaury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
CCLIB = -lncurses
CCFLAGS =
SRCDIR = src
OBJDIR = obj
INCDIR = includes
LIBDIR = libft/libft.a

SRC +=	main.c
SRC +=	display_list.c
SRC +=	exit_select.c
SRC +=	get_key.c
SRC +=	reset_term.c
SRC +=	tab_setup.c
SRC +=	term_init.c
SRC +=	tools.c
SRC +=	delete_arg.c
SRC +=	signal_handler.c

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
INCS = $(addprefix -I , $(INCDIR))

all: $(NAME)
$(NAME): build $(OBJS)
	@make -C libft
	@gcc $(CCLIB) -o $(NAME) $(OBJS) $(LIBDIR)
	@echo "Compilation Over"
build:
	@mkdir -p $(OBJDIR)
clean:
	@make -C libft clean
	@rm -f $(OBJS)
fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -rf obj
re: fclean all

dev : all
	@./$(NAME)

.PHONY: clean fclean all

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@gcc -c -g $(CCFLAGS) $(INCS) -I includes/ -I libft/includes -o $@ $<