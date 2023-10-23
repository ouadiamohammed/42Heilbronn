/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:35:48 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 20:48:15 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char	*format, ...);
void	ft_checker(const char	*format, va_list args, int *counter);
void	ft_putchar(char c, int *counter);
void	ft_putnbr(int nb, int *counter);
void	ft_putstr(char *str, int *counter);
void	ft_putunsigned_int(unsigned int nb, int *counter);
void	ft_put_x(unsigned int nb, int *len);
void	ft_put_HEX(unsigned int nb, int *counter);

#endif
