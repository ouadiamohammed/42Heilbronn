/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:10:25 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/09 15:36:15 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len == 0)
		return (0);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && needle[j])
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && needle[j] && len > i + j)
			j++;
		if (needle[j] == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
