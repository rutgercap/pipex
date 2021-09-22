/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 13:00:22 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 14:33:50 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_command(t_cmd cmd, char **envp)
{
	char	*full_cmd;

	full_cmd = get_full_command(cmd, envp);
	if (!full_cmd)
		return (exit_error(8, "Command can't be found"));
	if (execve(full_cmd, cmd.args, envp) == ERROR)
		return (perror("Execve"));
	exit_error(666, "Failure to execute command");
}

static void	firstborn(int end[2], int fd_in, t_cmd cmd, char **envp)
{	
	if (dup2(fd_in, STDIN_FILENO) == ERROR)
		return (perror("Dup2 #1"));
	if (dup2(end[WRITE], STDOUT_FILENO) == ERROR)
		return (perror("Dup2 #2"));
	close(fd_in);
	close(end[READ]);
	execute_command(cmd, envp);
}

static void	secondborn(int end[2], int fd_out, t_cmd cmd, char **envp)
{
	if (dup2(end[READ], STDIN_FILENO) == ERROR)
		return (perror("Dup2 #1"));
	if (dup2(fd_out, STDOUT_FILENO) == ERROR)
		return (perror("Dup2 #2"));
	close(fd_out);
	close(end[WRITE]);
	execute_command(cmd, envp);
}

static void	parent_process(int end[2], pid_t pid_1, pid_t pid_2)
{
	int		status;

	close(end[READ]);
	close(end[WRITE]);
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
}

void	pipex(int fd_in, int fd_out, t_cmd cmd[2], char **envp)
{
	int		end[2];
	pid_t	pid_1;
	pid_t	pid_2;

	if (pipe(end) == ERROR)
		return (perror("Pipe"));
	pid_1 = fork();
	if (pid_1 == ERROR)
		return (perror("Fork #1"));
	else if (pid_1 == CHILD)
		firstborn(end, fd_in, cmd[0], envp);
	pid_2 = fork();
	if (pid_2 == ERROR)
		return (perror("Fork #2"));
	else if (pid_2 == CHILD)
		secondborn(end, fd_out, cmd[1], envp);
	parent_process(end, pid_1, pid_2);
}
