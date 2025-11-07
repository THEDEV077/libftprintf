/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysahnoun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:12:52 by ysahnoun          #+#    #+#             */
/*   Updated: 2025/11/05 18:15:04 by ysahnoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(char *s);
int	ft_putchar_count(char x);
int	ft_putstr_count(char *s);
int	ft_putnbr_count(int n);
int	ft_putnbr_b(unsigned long n, char *base);

#endif
