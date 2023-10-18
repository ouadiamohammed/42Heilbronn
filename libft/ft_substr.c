/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:58:11 by mouadia           #+#    #+#             */
/*   Updated: 2023/10/18 19:57:58 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = ft_strlen(s);
	if (i <= start)
		len = 0;
	else
	{
		s += start;
		i -= start;
	}
	if (i < len)
		len = i;
	substr = (char *)malloc(sizeof(char) * (len +1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s, (len + 1));
	return (substr);
}
