/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:41:49 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/07 03:06:35 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(int argc, char *argv[])
{
	t_fill *list;

	argv = NULL;
	list = NULL;
	if (argc < 2)
	{
		list = ft_init(list);
		ft_parser(list);
	}
	return (0);
}
