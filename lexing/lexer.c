/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 13:35:34 by rutgercappe   #+#    #+#                 */
/*   Updated: 2021/09/20 10:45:44 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static t_cmd	*init_cmds(void)
{
	t_cmd	*cmds;

	cmds = ft_calloc(3, sizeof(t_cmd *));
	if (!cmds)
		exit_error(3, "Malloc failure");
	cmds[0].tokens = ft_calloc(1, sizeof(char **));
	cmds[1].tokens = ft_calloc(1, sizeof(char **));
	if (!cmds[0].tokens || !cmds[1].tokens)
		exit_error(4, "Malloc failure");
	return (cmds);
}

static t_bool	next_cmd(char *arg)
{
	if (arg[0] == '-')
		return FALSE;
	return TRUE;
}

t_cmd	*lexer(int argc, char **argv)
{
	t_cmd	*cmds;
	int		i;
	int		curr;

	cmds = init_cmds();
	curr = -1;
	i = 2;
	while (i < argc - 1)
	{
		if (next_cmd(argv[i]))
			curr++;
		if (curr == -1 || curr == 2)
			exit_error(5, "Invalid commands given");
		save_token(&cmds[curr].tokens, argv[i]);
		i++;
	}
	if (curr != 1)
		exit_error(6, "Invalid commands given");
	return (cmds);
}