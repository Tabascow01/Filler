/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:44:18 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 22:13:48 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_free_hex(t_flags *list)
{
	ft_strdel(&list->args);
	list->args = ft_strnew(1);
	list->args[0] = '0';
}

void			ft_save_hex_low(t_flags *list, va_list args)
{
	char	*tmp;
	int		i;
	int		temp;

	i = -1;
	temp = 0;
	if (list->option != 0 || list->dbloption != 0)
		ft_process_option(list, args, 'x');
	else
	{
		temp = va_arg(args, unsigned int);
		if (temp < 0)
			tmp = ft_btoh(ft_itob(temp, 31));
		else
			tmp = ft_uitoa_base(temp, 16);
		while (tmp[i++])
			tmp[i] = ft_tolower(tmp[i]);
		list->args = ft_reallocf(tmp, 0);
		if (ft_atoi(list->args) == 0 && !ft_isalpha(list->args[0]))
			ft_free_hex(list);
	}
	list->conv = 'x';
	ft_argnull(list);
	ft_process_hex(list);
}

void			ft_save_hex_up(t_flags *list, va_list args)
{
	char	*tmp;
	int		temp;
	int		i;

	i = -1;
	temp = 0;
	if (list->option != 0 || list->dbloption != 0)
		ft_process_option(list, args, 'X');
	else
	{
		temp = va_arg(args, unsigned int);
		if (temp < 0)
			tmp = ft_btoh(ft_itob(temp, 31));
		else
			tmp = ft_itoa_base(temp, 16);
		while (tmp[i++])
			tmp[i] = ft_toupper(tmp[i]);
		list->args = ft_reallocf(tmp, 0);
	}
	if (ft_atoi(list->args) == 0 && !ft_isalpha(list->args[0]))
		ft_free_hex(list);
	list->conv = 'X';
	ft_argnull(list);
	ft_process_hex(list);
}

int				ft_verif_hex_up(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
				&& ft_isflag(list->format[idxtmp])
				&& list->format[idxtmp] == 'X')
		idxtmp++;
	if (list->format[idxtmp] == 'X')
		return (1);
	return (0);
}

int				ft_verif_hex_low(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
				&& ft_isflag(list->format[idxtmp])
				&& list->format[idxtmp] == 'x')
		idxtmp++;
	if (list->format[idxtmp] == 'x')
		return (1);
	return (0);
}