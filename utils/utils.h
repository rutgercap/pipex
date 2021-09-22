/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rutgercappendijk <rutgercappendijk@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 10:32:16 by rcappend      #+#    #+#                 */
/*   Updated: 2021/09/22 14:39:29 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

# include <stdlib.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

char				*ft_substr(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char const *s1, char const *s2);

char				**ft_split(char const *s, char c);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

size_t				ft_strlen(const char *str);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, void *src, size_t n);

void				*ft_calloc(size_t count, size_t size);

char				*ft_strdup(const char *s1);

void				free_grid(char **grid);

#endif
