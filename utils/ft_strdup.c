/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:42:32 by rcappend          #+#    #+#             */
/*   Updated: 2021/09/17 13:15:24 by rutgercappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s1)
{
	char		*save;
	size_t		i;

	save = (char *)malloc(ft_strlen(s1) + 1);
	if (!save)
		return (NULL);
	i = 0;
	while (*s1)
	{
		save[i] = *s1;
		i++;
		s1++;
	}
	save[i] = '\0';
	return (save);
}
