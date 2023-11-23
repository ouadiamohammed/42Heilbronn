/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouadia <mouadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:47:02 by mouadia           #+#    #+#             */
/*   Updated: 2023/11/23 23:28:38 by mouadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * ft_strlen: this function calculate the lenght of str
 * @str: string
 * 
 * Return: the lenghth of str
 */

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/**
 * ft_strchr: locates the first occurrence of a character
 * 				in the string.
 * @str: string
 * 
 * Return: pointer to the first occurrence of the character c in the str.
 */

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	c1;

	i = 0;
	c1 = (char)c;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c1)
			return ((char *)str + i);
		i++;
	}
	if (c1 == '\0')
		return ((char *)str + i);
	return (0);
}
/**
 * ft_strjoin: a Function that concatenates two strings.
 * @s1: string.
 * @s2: string.
 * 
 * Return: pointer to the newly created string.
 */

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str1)
	{
		str1 = malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!join)
		return (NULL);
	if (str1)
		while (str1[++i])
			join[i] = str1[i];
	while (str2[j])
		join[i++] = str2[j++];
	join[i] = '\0';
	free(str1);
	return (join);
}
