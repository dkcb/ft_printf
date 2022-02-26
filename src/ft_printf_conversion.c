/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_conversion.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 21:01:11 by dkocob        #+#    #+#                 */
/*   Updated: 2021/05/26 16:48:23 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	conv_arg_edge(struct s_s *d)
{
	if (d->tp == 'p' && d->a[0] == '0' && d->a[1] == 'x'
		&& d->a[2] == '0' && d->pr == 0)
	{
		d->a[2] = '\0';
	}
	if (d->pr == 0 && d->tp != '%')
		d->zeros = 0;
	if ((d->tp == 'd' || d->tp == 'i' || d->tp == 'u' || d->tp == 'x'
			|| d->tp == 'X') && d->a[0] == '0' && d->pr == 0)
		d->a[0] = '\0';
	return (0);
}

int	conv_arg(struct s_s *d)
{
	if (d->tp != 'c' && d->tp != 's' && d->tp != 'p' && d->tp != '%')
		d->a = j(get_c(d->pr - pos(d->a, '\0'), "0"), d->a, 3);
	if (d->pr >= 0 && (d->tp == 's'))
		d->a[d->pr] = '\0';
	if (d->tp != 's' && d->tp != 'c')
	{
		if (d->leftal == 0 && d->zeros > 0 && (d->pr < 1 || d->tp == '%'))
			d->a = j(get_c(d->mw - (d->i < 0) - pos(d->a, '\0'), "0"), d->a, 3);
		if (d->i < 0)
			d->a = j("-", d->a, 2);
		if (d->leftal == 0 && d->zeros > 0)
			d->a = j(get_c(d->mw - pos(d->a, '\0'), " "), d->a, 3);
		if (d->leftal > 0)
			d->a = j(d->a, get_c(d->mw - pos(d->a, '\0'), " "), 3);
		if (d->leftal == 0 && d->zeros == 0)
			d->a = j(get_c(d->mw - pos(d->a, '\0'), " "), d->a, 3);
		return (0);
	}
	if (d->leftal == 0)
		d->a = j(get_c(d->mw - pos(d->a - (d->a[0] == '\0'
							&& d->tp != 's'), '\0'), " "), d->a, 3);
	if (d->leftal > 0)
		d->a = j(d->a, get_c(d->mw - pos(d->a, '\0')
					- (d->a[0] == '\0' && d->tp != 's'), " "), 3);
	return (0);
}
