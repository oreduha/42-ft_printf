/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:43:49 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/05 12:22:39 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief gelen sayının 16lık sayı sisteminde kaç
 * basamaklı olacağını bulan fonksiyon.
 *
 * @param a
 * @return int oluşturulacak hexadecimal sayının basamak sayısı
 */
static int	ft_count(unsigned int a)
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
 * @brief 16lık sayı sistemine çevirirken harf kısmını basan bölüm
 * printf içerisinde verilen x X ayrımını da yapıyor.
 *
 * @param a
 * @param c ana fonksiyonda % den sora gelen harf
 */
static void	ft_uplow(unsigned int a, int c)
{
	if (c == 'X')
		ft_putchar((a - 10) + 'A');
	else
		ft_putchar((a - 10) + 'a');
}

/**
 * @brief hexadecimale çeviren fonksiyon
 * rakam kısımlarını kendi içerisinde harf basılacak kısımları harici
 * fonksiyonda ekrana basar
 *
 * @param x hexadecimale çevrilecek değişken
 * @param c ana fonksiyondan gelen %den sonraki harf.
 * @return int ana fonksiyon için
 */
int	ft_putchar_x(unsigned int x, int c)
{
	int	len;

	len = ft_count(x);
	if (x == 0)
	{
		write (1, "0", 1);
		return (len + 1);
	}
	else
	{
		if (x >= 16)
		{
			ft_putchar_x((x / 16), c);
			ft_putchar_x((x % 16), c);
		}
		else
		{
			if (x <= 9)
				ft_putchar(x + '0');
			else
				ft_uplow(x, c);
		}
	}
	return (len);
}
