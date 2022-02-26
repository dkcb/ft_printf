/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digits.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/21 20:46:31 by dkocob        #+#    #+#                 */
/*   Updated: 2021/05/21 21:35:55 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_int(struct s_s *d, int i)
{
	d->i = i;
	if (i < 0)
		i *= -1;
	d->a = ft_itoau((size_t)i);
	return (0);
}

int	get_val(char *s)
{
	int	i;
	int	pwr;
	int	res;
	int	neg;

	neg = 1;
	i = 0;
	res = 0;
	pwr = 1;
	while (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i])
		i++;
	i--;
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		res = res + (s[i] - '0') * pwr;
		pwr = pwr * 10;
		i--;
	}
	return (res * neg);
}

char	*ft_itoa(int n)
{
	char	str[14];
	int		i;
	int		positive;

	if (n == -2147483648)
		return (j("-2147483648", "", 0));
	if (n == 0)
		return (j("0", "", 0));
	i = 12;
	str[i + 1] = '\0';
	positive = n;
	if (positive < 0)
		positive = positive * -1;
	while (positive > 0)
	{
		str[i] = (positive % 10) + 48;
		positive = positive / 10;
		i--;
	}
	if (n < 0)
		str[i] = '-';
	return (j("", &str[i + (n > 0)], 0));
}

char	*ft_itoau(unsigned int n)
{
	char	str[14];
	int		i;

	if (n == 0)
		return (j("", "0", 0));
	i = 12;
	str[i + 1] = '\0';
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (j("", &str[i + 1], 0));
}

char	*ft_itoa16(unsigned long int n)
{
	char	str[14];
	int		i;

	if (n == 0)
		return (j("", "0", 0));
	i = 12;
	str[i + 1] = '\0';
	while (n > 0)
	{
		if ((n % 16) > 9)
			str[i] = (n % 16) - 10 + 'a';
		else
			str[i] = (n % 16) + '0';
		n = n / 16;
		i--;
	}
	return (j("", &str[i + 1], 0));
}
