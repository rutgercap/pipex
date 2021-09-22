/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexing.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 08:57:21 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 15:08:56 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmd	init_cmd(void)
{
	t_cmd	cmd;

	cmd.file = NULL;
	cmd.args = NULL;
	return (cmd);
}

void	save_cmd_file(char **dest, char *args)
{
	int	i;

	i = 0;
	while (args[i] != ' ')
		i++;
	*dest = ft_substr(args, 0, i);
	if (!*dest)
		exit_error(3, "Substring failure");
}

t_cmd	lex_arg(char *args)
{
	t_cmd	cmd;

	cmd = init_cmd();
	save_cmd_file(&cmd.file, args);
	cmd.args = ft_split(args, ' ');
	if (!cmd.args)
		exit_error(4, "Split failure");
	return (cmd);
}

void	arg_lexer(t_cmd *cmd_1, t_cmd *cmd_2, char *arg_1, char *arg_2)
{
	*cmd_1 = lex_arg(arg_1);
	*cmd_2 = lex_arg(arg_2);
}
