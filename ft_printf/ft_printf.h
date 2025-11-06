/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouamarko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:38:09 by ouamarko          #+#    #+#             */
/*   Updated: 2025/05/17 16:26:56 by ouamarko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putnbr_hexa(unsigned long n);
int		ft_putchar_pointer(void *ptr);
int		ft_putnbr_hexa(unsigned long n);
int		ft_hexa_upper(unsigned long n);

#endif
