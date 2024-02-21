/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpiana <erpiana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:19:32 by erpiana           #+#    #+#             */
/*   Updated: 2024/02/20 04:39:51 by erpiana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_putchar(int c);
int	ft_putstr(const char *str);
int	ft_put_un_nbr(unsigned int nbr);
int	ft_putnumber(int nbr);
int	ft_printf(const char *format, ...);
int	ft_print_format(int c, va_list ap);
int	ft_puthexa(unsigned long long hexa, int n);

#endif
