/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:35:34 by rutgercappe       #+#    #+#             */
/*   Updated: 2021/09/17 17:04:42 by rutgercappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static t_cmd	*init_cmds(void)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)malloc(sizeof(t_cmd) * 2);
	if (!cmds)
		exit_error(3, "Malloc failure");
	cmds[0].tokens = (char *)malloc(sizeof(char *));
	cmds[1].tokens = (char *)malloc(sizeof(char *));
	if (!cmds[0].tokens || !cmds[1].tokens)
		exit_error(4, "Malloc failure");
	return (cmds);
}

static t_bool	next_cmd(char *arg)
{
	if (arg[0] == '-')
		return TRUE;
	return FALSE;
}

t_cmd	*lexer(int argc, char **argv)
{
	t_cmd	*cmds;
	int		i;
	int		curr;

	cmds = init_cmds();
	curr = 0;
	i = 2;
	while (i < argc - 1)
	{
		if (next_cmd(argv[i]))
			curr++;
			// save token
		i++;
	}
	return (cmds);
}