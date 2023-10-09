/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:44:02 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/09 11:37:36 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>


int	ft_atoi(char *s);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isdigit(int	c);
int	ft_isprint(int c);

/*str function*/
int	ft_strlen(char *s);
char	*ft_strchr(const char *s, int c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


/*mem Functions*/












#endif