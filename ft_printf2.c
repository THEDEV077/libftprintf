/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:36:08 by ysahnoun          #+#    #+#             */
/*   Updated: 2025/11/06 09:36:12 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar_count(char x)
{
	write(1, &x, 1);
	return (1);
}

int	ft_putstr_count(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (ft_putstr_count("(null)"));
	while (s[i])
	{
		count += ft_putchar_count(s[i]);
		i++;
	}
	return (count);
}

int	ft_putnbr_count(int n)
{
	long	nb;
	int		count;

	nb = (long)n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putchar_count('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		count += ft_putnbr_count(nb / 10);
		count += ft_putnbr_count(nb % 10);
	}
	else
		count += ft_putchar_count(nb + '0');
	return (count);
}

int	ft_putnbr_b(unsigned long n, char *base)
{
	unsigned long	len;
	int				count;

	len = ft_strlen(base);
	count = 0;
	if (n >= len)
	{
		count += ft_putnbr_b(n / len, base);
	}
	count += ft_putchar_count(base[n % len]);
	return (count);
}
