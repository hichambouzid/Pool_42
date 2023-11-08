/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 09:41:45 by hibouzid          #+#    #+#             */
/*   Updated: 2023/07/17 22:00:57 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexa(char c)
{
	unsigned char	lc;

	lc = (unsigned char)c;
	ft_putchar('\\');
	ft_putchar("0123456789abcdef"[lc / 16]);
	ft_putchar("0123456789abcdef"[lc % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			ft_hexa(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
}
