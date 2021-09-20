# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rutgercappendijk <rutgercappendijk@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/17 08:39:07 by rcappend      #+#    #+#                  #
#    Updated: 2021/09/20 10:58:32 by rcappend      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS		=	pipex.c \
				lexing/lexer.c \
				lexing/tokens.c \
				utils/ft_strncmp.c \
				utils/ft_substr.c \
				utils/ft_memcpy.c \
				utils/ft_bzero.c \
				utils/ft_calloc.c \
				utils/ft_strlen.c
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
	./$(NAME) infile "ls -l" "wc -l" outfile

drun: all
	lldb $(NAME) -- infile "ls -l" "wc -l" outfile

re: fclean all

phony:
	all clean fclean re dtest test


	