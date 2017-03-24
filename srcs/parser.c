/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:40:55 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 23:41:22 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_parser(void)
{
	char	*str;
	int		fd;

	fd = 0;
	while (ft_get_next_line(fd, &str) > 0)
		ft_printf("str[%s]\n",str);
	return (0);
}
