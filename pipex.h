/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 08:40:36 by rcappend          #+#    #+#             */
/*   Updated: 2021/09/17 16:33:24 by rutgercappe      ###   ########.fr       */
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

#endif