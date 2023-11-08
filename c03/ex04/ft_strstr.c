/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 11:58:17 by hibouzid          #+#    #+#             */
/*   Updated: 2023/07/19 18:47:32 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return (str);
	while (*str)
	{
		if (*str == to_find[0])
		{
			i = 0;
			while ((to_find[i] == str[i]) && str[i] && to_find[i])
				i++;
			if (i == ft_strlen(to_find))
				return (str);
		}
		str++;
	}
	return (0);
}
