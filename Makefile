# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rutgercappendijk <rutgercappendijk@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/17 08:39:07 by rcappend      #+#    #+#                  #
#    Updated: 2021/09/21 16:22:00 by rcappend      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex

SRCS		=	main.c \
				pipex.c \
				files.c \
				lexing.c \
				cmd.c \
				utils/ft_strlen.c \
				utils/ft_split.c \
				utils/ft_substr.c \
				utils/ft_calloc.c \
				utils/ft_memcpy.c \
				utils/ft_bzero.c \
				utils/ft_strncmp.c \
				utils/ft_strjoin.c \
				utils/ft_strdup.c
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
	./$(NAME) testfiles/in "ls -l" "wc -l" testfiles/out

drun: all
	lldb $(NAME) -- testfiles/in "ls -l" "wc -l" testfiles/out

re: fclean all

phony:
	all clean fclean re dtest test


	