/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 16:38:05 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/05 12:25:24 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief hexadecimale çevrim yapan fonksiyon.
 *
 * @param a
 */
void	ft_puthex(unsigned long long a)
{
	if (a >= 16)
	{
		ft_puthex(a / 16);
		ft_puthex(a % 16);
	}
	else
	{
		if (a <= 9)
			ft_putchar(a + '0');
		else
			ft_putchar((a - 10) + 'a');
	}
}
