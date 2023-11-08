/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:56:02 by hibouzid          #+#    #+#             */
/*   Updated: 2023/08/03 01:02:50 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (is_charset(charset, str[0]))
		count++;
	while (str[i])
	{
		if (is_charset(charset, str[i]) == 0
			&& is_charset(charset, str[i - 1]) != 0)
			count++;
		i++;
	}
	if (!is_charset(charset, str[i - 1]))
		count--;
	return (count);
}

char	**ft_alloc(char *str, char *charset, char **ptr, int e)
{
	int	i;
	int	j;

	j = -1;
	while (*str && j++ < e)
	{
		while (is_charset(charset, *str) == 0)
			str++;
		if (!*str)
			break ;
		i = 0;
		while (is_charset(charset, str[i]) && str[i])
			i++;
		ptr[j] = malloc(sizeof(char) * (i + 1));
		if (!ptr[j])
			return (NULL);
		ptr[j][i] = 0;
		i = 0;
		while (is_charset(charset, *str) && *str)
		{
			ptr[j][i++] = *str;
			str++;
		}
	}
	return (ptr);
}

char	**ft_split(char *str, char *charset)
{
	char	**ptr;
	int		i;
	int		e;

	if (!(*str))
	{
		ptr = malloc(sizeof(char *));
		ptr[0] = 0;
		return (ptr);
	}
	e = 0;
	i = ft_count(str, charset);
	ptr = malloc(sizeof(char *) * (i + 1));
	if (!ptr)
		return (NULL);
	ptr[i] = NULL;
	ft_alloc(str, charset, ptr, i);
	return (ptr);
}
/**
#include<unistd.h>
#include <stdio.h>
int main(int ac, char **av)
{

	char **tab;
	int i;
	int j;

	i = 0;
	(void)ac;
	printf("befor split\n");
	//tab = ft_split("   hello world  ", "");
	//tab = ft_split("", "- ");
	tab = ft_split(av[1], av[2]);
	//tab = ft_split("", "");
	//tab = ft_split("aaaabbbbbbccc", "ab");
	while (tab[i]) 
	{
		j = 0;
		while (tab[i][j])
			write(1, &tab[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
	
	//printf("%d\n", ft_count("  1337-de ben+   geruir   ", "-+ "));
}
*/
