/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhasan <dhasan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:03:24 by dhasan            #+#    #+#             */
/*   Updated: 2023/10/30 14:05:43 by dhasan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *prnt, ...);
int		ft_check_format(char specifier, va_list arg);

int		ft_print_chr(char c);
int		ft_print_str(char *str);

int		ft_print_int(long num);
char	*ft_itoa_2(long num);

int		ft_print_hex_low(unsigned long n);
int		ft_print_hex_up(unsigned long n);
int		ft_print_pointer(unsigned long pointer);

#endif
