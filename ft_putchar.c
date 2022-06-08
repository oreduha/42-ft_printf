/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otelliog <otelliog@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:42:08 by otokluog          #+#    #+#             */
/*   Updated: 2022/06/05 12:24:21 by otelliog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * @brief char karakteri ekrana basar.
 *
 * @param c
 * @return int
 */
int	ft_putchar(int c)
{
	int	len;

	len = 1;
	write (1, &c, 1);
	return (len);
}
