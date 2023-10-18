/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:33:10 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/18 19:29:01 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checker(char const *set, char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed_str;
	char	*trim;
	int		len;

	len = ft_strlen(s1);
	while (*s1 && ft_checker(set, *s1))
	{
		s1++;
		len--;
	}
	while (len > 0 && ft_checker(set, s1[len - 1]))
		len--;
	trim = (char *)malloc(sizeof(char) * (len +1));
	if (!trim)
		return (NULL);
	trimed_str = trim;
	trim[len] = '\0';
	while (len-- > 0)
		*(trim++) = *(s1++);
	return (trimed_str);
}
