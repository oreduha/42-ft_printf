/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:14:10 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/05 12:17:27 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/**
 * @brief unsigned inti ekrana basan fonksiyon.
 *
 * @param a
 * @return int
 */
int	ft_putchar_u(unsigned int a)
{
	int		len;
	char	*num;

	len = 0;
	if (a == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	if (a < 0)
	{
		if ((int)a == -1)
			a = 4294967295;
		else
			a = 4294967295 + a;
	}
	num = ft_uitoa(a);
	len += ft_putchar_s(num);
	free(num);
	return (len);
}
