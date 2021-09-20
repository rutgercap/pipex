/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokens.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/17 17:00:03 by rutgercappe   #+#    #+#                 */
/*   Updated: 2021/09/20 10:58:40 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	**get_pointer(int i)
{
	char	**ptr;
	
	ptr = ft_calloc(i + 2, sizeof(char *));
	if (!ptr)
		exit_error(7, "Malloc failure");
	return ptr;
}

static void	set_pointers(char **dest, char **old, const int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		dest[i] = old[i];
		i++;
	}
}

static void	add_arg(char **dest, char *arg)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	if (*arg == '-')
		arg++;
	dest[i] = ft_substr(arg, 0, ft_strlen(arg));
	if (!dest[i])
		exit_error(8, "Malloc failure");
}

void	save_token(char ***dest, char *arg)
{
	char	**old;
	char	**new;
	int		i;

	i = 0;
	old = *dest;
	while (old[i] != NULL)
		i++;
	new = get_pointer(i);
	set_pointers(new, old, i);
	add_arg(new, arg);
	free(*dest);
	*dest = new;
}
