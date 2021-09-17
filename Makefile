# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcappend <rcappend@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/17 08:39:07 by rcappend      #+#    #+#                  #
#    Updated: 2021/09/17 09:00:39 by rcappend      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

SRCS		=	main.c
OBJS		=	$(SRCS:.c=.o)
CC			=	gcc

CFLAGS		= 	-Wall  -Wextra -fsanitize=address -g3 # cleanup -Werror

all:		$(NAME)
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME)

re: fclean all

phony:
	all clean fclean re dtest test