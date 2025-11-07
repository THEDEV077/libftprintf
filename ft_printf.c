/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 14:32:37 by ysahnoun          #+#    #+#             */
/*   Updated: 2025/11/07 10:53:02 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	fun(va_list args)
{
	unsigned long	ptr;
	int				count;

	count = 0;
	ptr = va_arg(args, unsigned long);
	if (!ptr)
		return (ft_putstr_count("(nil)"));
	count += ft_putstr_count("0x");
	count += ft_putnbr_b(ptr, "0123456789abcdef");
	return (count);
}

static int	ft_format(va_list args, char x)
{
	int	count;

	count = 0;
	if (x == 'c')
		count += ft_putchar_count(va_arg(args, int));
	else if (x == 's')
		count += ft_putstr_count(va_arg(args, char *));
	else if (x == 'i' || x == 'd')
		count += ft_putnbr_count(va_arg(args, int));
	else if (x == 'u')
		count += ft_putnbr_b(va_arg(args, unsigned int), "0123456789");
	else if (x == 'x')
		count += ft_putnbr_b(va_arg(args, unsigned int), "0123456789abcdef");
	else if (x == 'X')
		count += ft_putnbr_b(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (x == 'p')
		count += fun(args);
	else if (x == '%')
		count += ft_putchar_count('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, format);
	if (write(1, "", 0) == -1 || !format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			count += ft_format(args, format[i + 1]);
			i++;
		}
		else
			count += ft_putchar_count(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
