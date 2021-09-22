/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmd.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 11:16:53 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 14:31:15 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

static char	**add_slash(char **env_paths)
{
	char	*temp;
	int		i;

	i = 0;
	while (env_paths[i])
	{
		temp = ft_strjoin(env_paths[i], "/");
		if (!temp)
			exit_error(100, "Strjoin failure");
		free(env_paths[i]);
		env_paths[i] = temp;
		i++;
	}
	return (env_paths);
}

static char	**get_env_paths(char **envp)
{
	char	**env_paths;
	char	*path;

	path = get_path(envp);
	if (!path)
		exit_error(5, "Failure finding path");
	env_paths = ft_split(path + 5, ':');
	if (!env_paths)
		exit_error(6, "Split failure");
	env_paths = add_slash(env_paths);
	return (env_paths);
}

static char	*try_paths(char **env_paths, t_cmd cmd)
{
	char	*to_try;
	int		i;

	i = 0;
	while (env_paths[i])
	{
		to_try = ft_strjoin(env_paths[i], cmd.file);
		if (!to_try)
			exit_error(7, "Strjoin failure");
		if (access(to_try, X_OK) == SUCCES)
			return (to_try);
		free(to_try);
		to_try = NULL;
		i++;
	}
	return (NULL);
}

char	*get_full_command(t_cmd cmd, char **envp)
{
	char	**env_paths;
	char	*full;

	if (access(cmd.file, X_OK) == SUCCES)
		return (cmd.file);
	env_paths = get_env_paths(envp);
	full = try_paths(env_paths, cmd);
	free_grid(env_paths);
	return (full);
}
