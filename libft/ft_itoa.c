/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yozcan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:11:26 by yozcan            #+#    #+#             */
/*   Updated: 2022/10/26 18:21:52 by yozcan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static long	digit(long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		i++;
	while (num)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		j;
	long	nb;

	nb = n;
	j = digit(nb);
	str = (char *)malloc(j + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	str[j] = '\0';
	j--;
	while ((n < 0) <= j)
	{
		str[j] = (nb % 10) + 48;
		nb /= 10;
		j--;
	}
	return (str);
}
