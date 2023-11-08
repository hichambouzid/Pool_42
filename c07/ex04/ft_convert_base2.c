/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:49:53 by hibouzid          #+#    #+#             */
/*   Updated: 2023/07/31 11:56:09 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<stdio.h>

int	ft_check(char *base);
int	ft_index(char *base, char c);
int	ft_atoi_base(char *str, char *base);
int	ft_count(int nbr, int len);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	int		i;
	char	*rt;

	if (ft_check(base_from) == 0 || ft_check(base_to) == 0)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	i = ft_count(nb, ft_check(base_to));
	rt = malloc(sizeof(char) * (i + 1));
	if (!rt)
		return (NULL);
	rt[i--] = 0;
	if (nb < 0)
	{
		nb *= -1;
		rt[0] = '-';
	}
	while (nb >= ft_check(base_to))
	{
		rt[i--] = base_to[nb % ft_check(base_to)];
		nb /= ft_check(base_to);
	}
	rt[i] = base_to[nb];
	return (rt);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	printf("the convert of number is :%s\n", ft_convert_base(av[1], av[2], av[3]));
}
*/
