/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkocob <dkocob@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/14 14:53:12 by dkocob        #+#    #+#                 */
/*   Updated: 2021/05/26 16:40:04 by dkocob        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_s
{
	va_list	ap;
	int		fend;
	int		mw;
	int		pr;
	int		leftal;
	int		zeros;
	int		params_removed;
	int		diff_written;
	int		total;
	int		i;
	int		madness;
	char	tp;
	char	*p;
	char	*a;
}t_s;

int		conv_arg(struct s_s *d);
int		conv_arg_edge(struct s_s *d);
int		putstr(struct s_s *d);
void	sinit(struct s_s *d);
int		ft_printf(const char *s, ...);
int		get_int(struct s_s *d, int i);
char	*get_c(size_t amount, char *add);
char	*ft_insert(char *orig, char *s, size_t start, size_t size);
int		get_val(char *s);
size_t	pos(char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*j(char *s1, char *s2, int f);
char	*ft_itoa(int in);
char	*ft_itoau(unsigned int in);
char	*ft_itoa16(unsigned long int in);
char	*to_upper(char *c);
char	*conv_c(struct s_s *d, char c);
#endif
