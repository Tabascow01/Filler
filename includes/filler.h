/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:27:17 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/07 04:59:05 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../ft_printf/includes/ft_printf.h"

typedef struct		s_fill
{
	int		playernum;
	char	*playername;
	int		tabx;
	int		taby;
	char	*table;
	int		px;
	int		py;
	char	*piece;
	
}					t_fill;

char		*ft_cut_table(char **line);
t_fill		*ft_init(t_fill *list);
int			ft_parser(t_fill *list);

#endif
