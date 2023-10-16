/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:07:48 by chanson           #+#    #+#             */
/*   Updated: 2023/01/03 16:07:49 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*case_1(int n)
{
	char	*result;
	int		i;

	if (n == -2147483648)
	{
		result = (char *)malloc(sizeof(char) * 12);
		result[0] = '-';
		i = 10;
		while (n)
		{
			result[i] = '0' + (n % 10) * (-1);
			n /= 10;
			i--;
		}
		result[11] = '\0';
	}
	else
	{
		result = (char *)malloc(sizeof(char) * 2);
		result[0] = '0';
		result[1] = '\0';
	}
	return (result);
}

static char	*case_2(int n, int i, char *result)
{
	result[i--] = '\0';
	while (n)
	{
		result[i--] = '0' + (n % 10);
		n /= 10;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int			i;
	int			x;
	char		*result;

	x = n;
	i = 0;
	if (n == -2147483648 || n == 0)
		return (case_1(n));
	while (x)
	{
		x /= 10;
		i++;
	}
	if (n > 0)
		result = (char *)malloc(sizeof(char) * (i + 1));
	else
	{
		result = (char *)malloc(sizeof(char) * (i + 2));
		result[0] = '-';
		n *= -1;
		i++;
	}
	return (case_2(n, i, result));
}
