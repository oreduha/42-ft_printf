/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:06:46 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/05 12:27:14 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief int değerin basamak sayısını bulan fonksiyon
 *
 * @param x
 * @return int basamak sayısı
 */
static int	ft_size(unsigned int x)
{
	unsigned int	i;

	i = 0;
	while (x)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

/**
 * @brief int to array
 * gelen int değişkeni stringe çeviren fonksiyon.
 *
 * @param a stringe çevrilmesi istenen int değer.
 * @return char* 
 */
char	*ft_uitoa(unsigned int a)
{
	char			*s;
	unsigned int	size;

	size = ft_size(a);
	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	s[size--] = '\0';
	while (a)
	{
		s[size] = (a % 10) + '0';
		a = a / 10;
		size--;
	}
	return (s);
}
