/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 14:42:30 by dkocob        #+#    #+#                 */
/*   Updated: 2021/05/26 17:33:26 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_arg(struct s_s *d)
{
	if (d->tp == 's')
		d->a = j(va_arg(d->ap, char *), "", 0);
	else if (d->tp == 'c')
		d->a = conv_c(d, va_arg(d->ap, int));
	else if (d->tp == '%')
		d->a = j("%", "", 0);
	else if (d->tp == 'd' || d->tp == 'i')
		get_int(d, va_arg(d->ap, int));
	else if (d->tp == 'u')
		d->a = ft_itoau(va_arg(d->ap, size_t));
	else if (d->tp == 'p')
		d->a = j("0x", ft_itoa16(va_arg(d->ap, unsigned long int)), 2);
	else if (d->tp == 'x')
		d->a = ft_itoa16(va_arg(d->ap, unsigned int));
	else if (d->tp == 'X')
		d->a = to_upper(ft_itoa16(va_arg(d->ap, unsigned int)));
	if (!d->a)
		return (-1);
	return (0);
}

static int	get_precision_spc(struct s_s *d, int i)
{
	char	*tmp;

	while (d->p[i] >= '0' && d->p[i] <= '9')
		i++;
	if (d->p[i] == '.')
	{
		d->pr = 0;
		i++;
		if (d->p[i] == '*')
		{
			tmp = ft_itoa(va_arg(d->ap, int));
			d->params_removed -= pos(tmp, '\0') - 1;
			d->p = ft_insert(d->p, tmp, i, i + 1);
			if (!d->p)
				return (-1);
		}
		if ((d->p[i] >= '0' && d->p[i] <= '9') || d->p[i] == '-')
			d->pr = get_val(&d->p[i]);
		while ((d->p[i] >= '0' && d->p[i] <= '9') || d->p[i] == '-')
			i++;
	}
	d->tp = d->p[i];
	free(d->p);
	return (i + 1);
}

static int	get_params(struct s_s *d, const char *s, int i)
{
	char	*tmp;

	d->p = j((char *)s + d->fend, "", 0);
	if (!d->p)
		return (-1);
	while (d->p[i] == '-' || d->p[i] == '0' || d->p[i] == '*')
	{
		if (d->p[i] == '*')
		{
			tmp = ft_itoa(va_arg(d->ap, int));
			d->params_removed -= pos(tmp, '\0') - 1;
			d->p = ft_insert(d->p, tmp, i, i + 1);
			i--;
			if (!d->p)
				return (-1);
		}
		if (d->p[i] == '-')
			d->leftal = 1;
		if (d->p[i] == '0')
			d->zeros = 1;
		i++;
	}
	d->mw = get_val(&d->p[i]);
	return (get_precision_spc(d, i));
}

int	ft_printf(const char *s, ...)
{
	struct s_s	d;

	d.diff_written = 0;
	d.total = pos((char *)s, '\0');
	d.fend = 0;
	va_start(d.ap, s);
	while (d.fend < d.total)
	{
		sinit(&d);
		while (s[d.fend] != '%' && d.fend < d.total)
			d.fend += write(1, &s[d.fend], 1);
		if (s[d.fend] == '%')
		{
			d.params_removed += get_params(&d, s, 1);
			d.fend += d.params_removed;
			if (d.params_removed == -1 || get_arg(&d) == -1)
				return (-1);
			conv_arg_edge(&d);
			if (conv_arg(&d) == -1 || !d.a)
				return (-1);
			d.diff_written += (putstr(&d) - d.params_removed);
		}
	}
	va_end(d.ap);
	return (d.fend + d.diff_written);
}
