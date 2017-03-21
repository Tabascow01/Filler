/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/17 23:42:45 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*reverse(char *str, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strnew(i);
	i -= 1;
	while (i >= 0)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	tmp[j] = '\0';
	ft_strdel(&str);
	str = tmp;
	return (str);
}

static char		*ft_itoa_next(char **str, int *num, int *base, int *neg)
{
	int i;

	i = 0;
	if ((*num) == 0)
	{
		(*str)[i++] = '0';
		(*str)[i] = '\0';
		return ((*str));
	}
	if ((*num) < 0 && (*base) == 10)
	{
		(*neg) = 1;
		(*num) = -(*num);
	}
	return ((*str));
}

char			*ft_itoa_base(int num, int base)
{
	char	*str;
	int		i;
	int		rem;
	int		negative;

	i = 0;
	negative = 0;
	str = ft_strnew(12);
	str = ft_itoa_next(&str, &num, &base, &negative);
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (str[0] == '0' && str[1] == '\0')
		return (str);
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	if (negative == 1)
		str[i++] = '-';
	str[i] = '\0';
	str = reverse(str, i);
	return (str);
}