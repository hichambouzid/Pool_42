/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:24:32 by hibouzid          #+#    #+#             */
/*   Updated: 2023/07/29 14:42:09 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_all(int size, char **strs, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j += ft_strlen(strs[i]);
		if (i < size - 1)
			j += ft_strlen(sep);
		i++;
	}
	return (j);
}

void	ft_concat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (src[i])
	{
		dest[i + j] = src[i];
		i++;
	}
	dest[i + j] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		j;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	j = count_all(size, strs, sep);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	j = 0;
	str[0] = 0;
	while (j < size)
	{
		ft_concat(str, strs[j]);
		if (j < size - 1)
			ft_concat(str, sep);
		j++;
	}
	return (str);
}
