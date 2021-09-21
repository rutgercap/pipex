/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 13:00:22 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/21 16:26:50 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



static void	child_process(int pipe[2], int fd_in, t_cmd cmd, char **envp)
{
	char	*full_command;
	
	if (dup2(fd_in, STDIN_FILENO) == ERROR)
		return (perror("Dup2"));
	if (dup2(pipe[WRITE], STDOUT_FILENO) == ERROR)
		return (perror("Dup2"));
	close(pipe[READ]);
	close(fd_in);
	full_command = get_full_command(cmd, envp);
	printf("cmd: %s\n", full_command);
	if (!full_command)
		return exit_error(8, "Command can't be found");

	execve(full_command, cmd.args, envp);
}

static void	parent_process(int fd_out)
{
	printf("Parent\n");
}

void	pipex(int fd_in, int fd_out, t_cmd cmd[2], char **envp)
{
	int		end[2];
	pid_t	pid;
	
	if (pipe(end) == ERROR)
		exit_error(3, "Pipe failure");
	pid = fork();
	if (pid < 0)
		return (perror("Fork"));
	if (pid == CHILD)
		child_process(end, fd_in, cmd[0], envp);
	else
		parent_process(fd_out);
}