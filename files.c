/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   files.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 08:46:18 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 14:31:30 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	read_infile(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error(2, "Failure reading infile");
	return (fd);
}

static int	read_outfile(char *path)
{
	int	fd;

	fd = open(path, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		exit_error(2, "Failure reading outfile");
	return (fd);
}

void	read_files(int *fd_in, int *fd_out, char *path_in, char *path_out)
{
	*fd_in = read_infile(path_in);
	*fd_out = read_outfile(path_out);
}
