/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:00:03 by rutgercappe       #+#    #+#             */
/*   Updated: 2021/09/17 17:08:47 by rutgercappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	save_token(char **dest, char *arg)
{
	char	*tokens;
	int		i;

	i = 0;
	while (dest[i] != NULL)
		i++;
	if (*arg == '-')
		arg++;
	
}