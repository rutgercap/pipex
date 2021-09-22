/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_grid.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 13:02:00 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 14:29:51 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_grid(char **grid)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
