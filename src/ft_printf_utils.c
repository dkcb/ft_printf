/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 18:02:35 by dkocob        #+#    #+#                 */
/*   Updated: 2021/05/21 21:36:46 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	putstr(struct s_s *d)
{
	int	cnt;

	cnt = 0;
	while (d->a[cnt] != '\0')
	{
		if (d->a[cnt] == (char)255 && d->madness > 0)
			cnt += write(1, "\0", 1);
		else
			cnt += write(1, &d->a[cnt], 1);
	}
	free(d->a);
	d->a = (void *) 0;
	return (cnt);
}

char	*conv_c(struct s_s *d, char c)
{
	char	tmp[2];

	tmp[0] = c;
	if (tmp[0] == '\0')
	{	
		tmp[0] = (char)255;
		d->madness += 1;
	}
	tmp[1] = '\0';
	return (j("", tmp, 0));
}

void	sinit(struct s_s *d)
{
	d->mw = 0;
	d->pr = -1;
	d->i = 0;
	d->leftal = 0;
	d->zeros = 0;
	d->params_removed = 0;
	d->madness = 0;
}

char	*get_c(size_t ammount, char *add)
{
	char	*tmp;

	tmp = j("", "", 0);
	while ((int)ammount > 0)
	{
		tmp = j(add, tmp, 2);
		ammount--;
	}
	return (tmp);
}

char	*to_upper(char *c)
{
	size_t	i;

	i = 0;
	while (c[i])
	{
		if (c[i] >= 'a' && c[i] <= 'z')
			c[i] -= 32;
		i++;
	}
	return (c);
}
