/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 10:03:31 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/05 12:10:21 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief Gelen sayının basamak sayısını bulan fonksiyon
 *
 * @param a
 * @return int
 */
static int	ft_count(long a)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	if (a < 0)
		a = -a;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

/**
 * @brief write fonksiyonu ile int değerleri direkt ekrana basamadığımız için
 * her bir basamak değerini rakam olarak ekrana basan fonksiyon.
 *
 * @param n ekrana basılması istenen sayı.
 * @return int printf için ekrana basıkan karakter sayısını döner.
 */
int	ft_putchar_d(int n)
{
	int	len;

	len = ft_count(n);
	if (n == -2147483648)
	{
		len += ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		n = n * -1;
		len += ft_putchar('-');
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		return (len);
	}
	else
	{
		ft_putchar_d(n / 10);
	}
	ft_putchar_d(n % 10);
	return (len);
}
