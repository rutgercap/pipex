/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 08:40:25 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 14:32:42 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_error(int error_code, char *msg)
{
	write(2, "Error!\n", 7);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(error_code);
}

int	main(int argc, char **argv, char **envp)
{	
	t_cmd	cmds[2];
	int		fd_in;
	int		fd_out;

	if (argc != 5)
		exit_error(1, "Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2");
	read_files(&fd_in, &fd_out, argv[1], argv[4]);
	arg_lexer(&cmds[0], &cmds[1], argv[2], argv[3]);
	pipex(fd_in, fd_out, cmds, envp);
	return (0);
}
