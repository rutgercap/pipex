/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 08:40:36 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 14:40:09 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "utils/utils.h"

# define CHILD 0
# define ERROR -1
# define SUCCES 0
# define WRITE 1
# define READ 0

typedef struct s_cmd {
	char	*file;
	char	**args;
}	t_cmd;

void	exit_error(int error_code, char *msg);

void	read_files(int *fd_in, int *fd_out, char *path_in, char *path_out);

void	arg_lexer(t_cmd *cmd_1, t_cmd *cmd_2, char *arg_1, char *arg_2);

void	pipex(int fd_in, int fd_out, t_cmd cmd[2], char **envp);

char	*get_full_command(t_cmd cmd, char **envp);

#endif