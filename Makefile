# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rutgercappendijk <rutgercappendijk@stud      +#+                      #
#                                                    +#+                       #
#    Created: 2021/09/17 08:39:07 by rcappend      #+#    #+#                  #
#    Updated: 2021/09/22 14:29:25 by rcappend      ########   odam.nl          #
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
				utils/ft_strdup.c \
				utils/free_grid.c
OBJS		=	$(SRCS:.c=.o)
CC			=	gcc

CFLAGS		= 	-Wall  -Wextra -Werror

INFILE		=	utils/
OUTFILE		=	testfiles/out
CMD1		=	testfiles/testprogram
CMD2		=	wc -l

all:		$(NAME)
$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

run: all
	./$(NAME) $(INFILE) "$(CMD1)" "$(CMD2)" $(OUTFILE)

compare:
	< $(INFILE) $(CMD1) | $(CMD2) > $(OUTFILE)

re: fclean all

phony:
	all clean fclean re dtest test
