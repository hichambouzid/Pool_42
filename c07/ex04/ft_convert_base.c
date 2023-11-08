/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 09:45:59 by hibouzid          #+#    #+#             */
/*   Updated: 2023/07/31 11:41:43 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

int	ft_count(int nbr, int len)
{
	long	nb;
	int		count;

	nb = (long)nbr;
	count = 0;
	if (nbr < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb >= len)
	{
		nb /= len;
		count++;
	}
	count++;
	return (count);
}

int	ft_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = ft_check(base);
	if (i == 0)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && ft_index(base, *str) != -1)
	{
		if (ft_index(base, *str) == -1)
			break ;
		res = (res * i) + ft_index(base, *str);
		str++;
	}
	return (res * sign);
}
