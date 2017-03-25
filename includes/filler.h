/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:27:17 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 23:41:41 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../ft_printf/includes/ft_printf.h"

typedef struct		s_fill
{
	char	playernum;
	char	playername;
	char	*table;
}					t_fill;

int		ft_parser(void);

#endif
