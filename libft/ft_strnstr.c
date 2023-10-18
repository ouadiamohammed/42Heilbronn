/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:10:25 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/18 19:34:47 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (haystack_len < len)
		len = haystack_len;
	if (!needle_len)
		return ((char *)haystack);
	while (len-- >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len))
			haystack++;
		else
			return ((char *)haystack);
	}
	return (0);
}
