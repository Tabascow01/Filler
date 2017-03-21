/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sshort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:22:51 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 20:12:55 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_sshort(t_flags *list, va_list args, char conv)
{
	int i;

	i = -1;
	if (conv == 'd' || conv == 'i')
		list->args = ft_itoa_base((char)va_arg(args, int), 10);
	else if (conv == 'o')
		list->args = ft_uctoa_base((unsigned char)va_arg(args, int), 8);
	else if (conv == 'O')
		list->args = ft_uitoa_base(va_arg(args, unsigned int), 8);
	else if (conv == 'x')
	{
		list->args = ft_uctoa_base((unsigned char)va_arg(args, int), 16);
		while (list->args[i++])
			list->args[i] = ft_tolower(list->args[i]);
	}
	else if (conv == 'X')
	{
		list->args = ft_uctoa_base((unsigned char)va_arg(args, int), 16);
		while (list->args[i++])
			list->args[i] = ft_toupper(list->args[i]);
	}
	else if (conv == 'u')
		list->args = ft_uctoa_base((unsigned char)va_arg(args, int), 10);
	else if (conv == 'U')
		list->args = ft_uitoa_base(va_arg(args, unsigned int), 10);
}
