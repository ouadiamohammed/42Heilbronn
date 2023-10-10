/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:51:04 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/10 12:30:43 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst1;
	unsigned char	*src1;
	size_t			i;

	dst1 = (unsigned char *)dst;
	src1 = (unsigned char *)src;
	i = 0;
	if (dst1 == 0 && src1 == 0)
		return (0);
	if (dst1 >= src1)
	{
		i = len;
		while (i-- > 0)
		{
			dst1[i] = src1[i];
		}
	}
	while (i < len)
	{
		dst1[i] = src1[i];
		i++;
	}
	return (dst);
}
