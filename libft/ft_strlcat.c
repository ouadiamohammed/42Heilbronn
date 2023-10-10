/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:46:46 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/10 15:06:06 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;

	i = 0;
	j = ft_strlen(dst);
	k = ft_strlen(src) + j;
	len = (dstsize - j - 1);
	if (dst == 0 && dstsize == 0)
		return (0);
	if (j >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < len)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (k);
}
