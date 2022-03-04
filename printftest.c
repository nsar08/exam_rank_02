/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printftest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <marvin@42lausanne.ch>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:12:14 by nsar              #+#    #+#             */
/*   Updated: 2022/03/02 11:34:22 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putchar_count(char  *s, int *count)
{
	write(1, &s, 1);
	*count = *count + 1;
void ft_putstr_count(char *str, int *count)
{
	int i= 0;
	while(format[i])
	{
		ft_putchar(format[i], count);
		i++;
	}
}
void ft_putnbr_base(unsigned int nbr, unsigned int base, char *base_text, int *count)
{
	if (nbr >= base)
	{
	ft_putnbr_base(nbr/base, base, base_text, count);
	ft_putnbr_base(nbr%base, base, base_text, count);
	}
	else 
		ft_putchar_count(base_text[nbr], count);
}

void ft_if(char *format, int i, va_list arg, int *count)
{
	int nbr = 0;
	if(format[i + 1] = 's')
		ft_putstr_count(va_arg(arg, char *), count);
	else if(format[i + 1] = 'd')
	{
		nbr = va_arg(arg, int);
		if(nbr < 0)
		{
			nbr *= -1;
			ft_putchar_count('-', count);
		}
		ft_putnbr_base(nbr, 10, "0123456789", count);
	}
	else if (fomrat[i+1] = 'x')
	{
		nbr = va_arg(nbr, unsigned int);
		ft_putnbr_base(nbr, 16, "0123456789abcdef", count);
	}
}
int ft_printf(char *fomrat, ...)
{
	int i;
	int count;
	va_list arg;
	va_start (arg, format);

	while(format[i])
	{
		if (format == '%')
		{
			ft_if(format, i, arg, &count);
			i += 2;
		}
		else
		{
			ft_putchar_count(format[i], count);
			i++;
		}
		va_end(arg);
		return(count);
	}
}

