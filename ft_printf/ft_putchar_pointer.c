/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:19:45 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/17 19:25:06 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count = count + write(1, "(nil)", 5);
		return (count);
	}
	count = count + write(1, "0x", 2);
	count = count + ft_putnbr_hexa((unsigned long)ptr);
	return (count);
}
