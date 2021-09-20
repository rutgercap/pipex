/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rutgercappendijk <rutgercappendijk@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:36:52 by rcappend          #+#    #+#             */
/*   Updated: 2021/09/17 13:15:24 by rutgercappe      ###   ########.fr       */

#include "utils.h"

static int	counter(int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		minus;

	minus = 0;
	if (n < 0)
		minus = 1;
	len = counter(n);
	ret = malloc(sizeof(unsigned char) * len + 1);
	if (!ret)
		return (NULL);
	ret[len] = '\0';
	while (len > minus)
	{
		len--;
		ret[len] = ft_abs((n % 10)) + '0';
		n = n / 10;
	}
	if (minus)
		ret[len - 1] = '-';
	return (ret);
}
