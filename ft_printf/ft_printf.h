/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:35:48 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/23 13:45:00 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int ft_checker(const char  *format, va_list args, int *i);
int	ft_putchar(char c);
int	ft_putnbr(int nb, int *counter);
int	ft_putstr(char *str);


#endif