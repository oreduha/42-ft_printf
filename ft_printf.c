/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:01:39 by otelliog          #+#    #+#             */
/*   Updated: 2022/06/05 12:05:23 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Değişkenin türünü ayıkıyor.
 *
 * @param ag ',' sonra verilen değişkenlerin listesi
 * @param c printf fonksiyonu içerisindeki % işaretinden sonraki harf
 * @return int printf fonksiyonun arkaplanda döndüğü uzunluk için
 * ekrana basılan karakter sayısı return ediliyor.
 */
static int	ft_check(va_list ag, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(ag, int));
	else if (c == 's')
		len += ft_putchar_s(va_arg(ag, char *));
	else if (c == 'p')
		len += ft_putchar_p(va_arg(ag, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_putchar_d(va_arg(ag, int));
	else if (c == 'u')
		len += ft_putchar_u(va_arg(ag, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_putchar_x(va_arg(ag, unsigned int), c);
	else if (c == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(c);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	ag;

	va_start(ag, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_check(ag, str[i]);
			i++;
		}
		else
			len += ft_putchar(str[i++]);
	}
	va_end(ag);
	return (len);
}
