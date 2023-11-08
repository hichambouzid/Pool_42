/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 10:19:44 by hibouzid          #+#    #+#             */
/*   Updated: 2023/07/20 23:09:12 by hibouzid         ###   ########.fr       */
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
		if ((base[i] == 32) || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_strlen(char *str, char *base)
{
	int	i;
	int	f;
	int	save;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		save = res;
		f = 0;
		while (base[f])
		{
			if (base[f] == str[i])
				res++;
			f++;
		}
		if (save == res)
			break ;
		i++;
	}
	return (res - 1);
}

int	ft_index(char c, char *base)
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
	int	sing;
	int	f;

	f = 0;
	sing = 1;
	i = ft_check(base);
	if (ft_check(base) == 0)
		return (0);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sing *= -1;
		str++;
	}
	while (*str)
	{
		if (ft_index(*str, base) == -1)
			break ;
		f = (f * i) + ft_index(*str, base);
		str++;
	}
	return (f * sing);
}
