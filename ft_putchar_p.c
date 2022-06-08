/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:28:15 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/05 12:13:59 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief verilen sayının 16lık sayı sisteminde kaç basamaklı olacağını
 * bulan fonksiyon.
 *
 * @param a
 * @return int
 */
static int	ft_count(unsigned long long a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

/**
 * @brief adres bilgisini ekrana basan fonksiyon. (16lık sayı sistemi)
 *
 * @param a
 * @return int
 */
int	ft_putchar_p(unsigned long long a)
{
	int	len;

	len = 0;
	write (1, "0x", 2);
	len += 2;
	if (a == 0)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	else
		ft_puthex(a);
	len += ft_count(a);
	return (len);
}
