/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 08:40:36 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/20 08:51:14 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H


// testing
// -------------------
#include <stdio.h>
// -------------------

#include <unistd.h>
#include <fcntl.h>
#include "utils/utils.h"

typedef struct s_cmd {
	char	**tokens;
}			t_cmd;

/*
**	General
*/

void	exit_error(int error_code, char *msg);

// lexing

t_cmd	*lexer(int argc, char **argv);

void	save_token(char ***dest, char *arg);

#endif