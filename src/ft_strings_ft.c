/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strings_ft.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 20:58:31 by dkocob        #+#    #+#                 */
/*   Updated: 2021/05/24 18:42:39 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	pos(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	if (!src)
		return (0);
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

char	*j(char *s1, char *s2, int f)
{
	char	*t;

	t = (void *) 0;
	if (!s1)
		s1 = "(null)";
	if (!s2)
		s2 = "(null)";
	t = malloc(
			sizeof(char) * (pos(s1, '\0') + pos(s2, '\0') + 1));
	if (!t)
		return ((void *) 0);
	ft_strlcpy(t, s1, pos(s1, '\0') + 1);
	ft_strlcpy(t + pos(s1, '\0'), s2, pos(s2, '\0') + 1);
	if (f == 1 || f == 3)
		free(s1);
	if (f == 2 || f == 3)
		free(s2);
	return (t);
}

char	*ft_insert(char *orig, char *s, size_t start, size_t end)
{
	char	*after;

	if (!orig || !s)
		return ((void *)0);
	after = j("", orig + end, 0);
	if (!after)
		return ((void *)0);
	orig[start] = '\0';
	orig = j(orig, s, 3);
	if (!orig)
		return ((void *)0);
	orig = j(orig, after, 3);
	if (!orig)
		return ((void *)0);
	return (orig);
}
