/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:44:52 by hibouzid          #+#    #+#             */
/*   Updated: 2023/07/21 22:57:02 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr(long nb, char *base)
{
	if (nb < ft_strlen(base))
		ft_putchar(base[nb]);
	else
	{
		ft_putnbr(nb / ft_strlen(base), base);
		ft_putnbr(nb % ft_strlen(base), base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;

	nb = (long)nbr;
	if (ft_check(base))
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		ft_putnbr(nb, base);
	}
}
