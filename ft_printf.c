/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:18:11 by nsar              #+#    #+#             */
/*   Updated: 2022/02/03 15:41:07 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_sc
{
	int len;
	int width;
}				t_sc;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int ft_strlen(const char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return(i);
}

char *ft_strchr(const char *s)
{
	while (*s)
	{
		if (*s == '%')
			return ((char*)s);
		s++;
	}
	if (!s)
		return((char *)s);
	return(NULL);
}

void ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		write(1, "-2147486348", 11);
		return;
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
int ft_intlen(int nb, char c)
{
	int i = 0;
	int number;
	int neg;

	if (!nb)
		return (1);
	if (nb < 0)
	{
		neg = 1;
		number = -nb;
	}
	else
	{
		neg = 0;
		number = nb;
	}

	if (c == 'd')
	{
		while (number)
		{
			number /= 10;
			i++;
		}
		return (i + neg);
	}
	if (c == 'x')
	{
		while (number)
		{
			number /= 16;
			i++;
		}
		return (i);
	}
	return(0);
}

void ft_printhexa(unsigned int x)
{
	char *hexa = "0123456789abcdef";
	int res[100];
	int i = 0;

	while (x >= 16)
	{
		res[i] = hexa[x % 16];
		x = x / 16;
		i++;
	}
	res[i] = hexa[x];
	while (i >= 0)
	{
		ft_putchar(res[i]);
		i--;
	}
}

const char *ft_search_arg(va_list arg, const char *format, t_sc *sc)
{
	if(*format == 'd')
	{
		int d = va_arg(arg, int);
		ft_putnbr(d);
		sc->len += ft_intlen(d, *format);
	}
	else if (*format == 's')
	{
		char *s = va_arg(arg, char *);
		if (!s)
		{
			write(1, "(null)", 6);
			sc->len += 6;
		}
		else
		{
			ft_putstr(s);
			sc->len += ft_strlen(s);
		}
	}
	else if (*format == 'x')
	{
		unsigned int x = va_arg(arg, unsigned int);
		ft_printhexa(x);
		sc->len += ft_intlen((int)x, *format);
	}
	else
		return(NULL);
	format++;
	return (format);
}

const char *ft_read_text(t_sc *sc, const char *format)
{
	char *next;

	next = ft_strchr(format);
	if (next)
		sc->width = next - format;
	else
		sc->width = ft_strlen(format);
	write(1, format, sc->width);
	sc->len += sc->width;
	while (*format && *format != '%')
		++format;
	return(format);
}
int ft_printf(const char *format, ...)
{
	va_list arg;
	va_start (arg, format);
	t_sc sc;
	sc.len = 0;
	sc.width = 0;

	while (*format)
	{
		if (*format == '%')
			format = ft_search_arg(arg, format + 1, &sc);
		else
			format = ft_read_text(&sc, format);
		if (!format)
		{
			write(1, "(null)", 6);
			va_end(arg);
			return (sc.len);
		}
	}
	va_end(arg);
	return (sc.len);
}

#include <stdio.h>

int main()
{
	int res= ft_printf("%f", 1.5);
	int res2 = printf("%f", 1.5);

	printf("\nres = %d\nres2 = %d\n", res, res2);
}
