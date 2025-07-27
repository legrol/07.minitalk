/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 08:45:26 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/06/08 23:54:44 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h> // para macros va_list, va_start, va_end y va_arg
# include <stdlib.h> //para typedef, malloc
# include <unistd.h> // para write
# include <stdint.h> // para tipo uintptr_t

// funciones principales
int		ft_printf(char const *format, ...);

//funciones auxiliares
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_puthex(unsigned long long nb, char checker);
int		ft_putptr(uintptr_t ptr);
int		ft_putnbr_uns(unsigned int nb);

// funciones de bonus

#endif