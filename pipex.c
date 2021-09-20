/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:40:25 by rcappend          #+#    #+#             */
/*   Updated: 2021/09/17 16:51:12 by rutgercappe      ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_cmd	*cmd;
	
	if (argc < 5)
		exit_error(1, "Usage: ./pipex file1 cmd1 cmd2 file2");
	cmd = lexer(argc, argv);
	return (0);
}