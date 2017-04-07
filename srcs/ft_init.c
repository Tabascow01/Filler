/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:10:48 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/07 04:30:40 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_fill		*ft_init(t_fill *list)
{
	t_fill *lst;

	lst = (t_fill *)ft_memalloc(sizeof(t_fill));
	lst->playername = 0;
	lst->playernum = 0;
	lst->table = 0;
	lst->taby = 0;
	lst->tabx = 0;
	lst->px = 0;
	lst->py = 0;
	lst->piece = 0;
	list = lst;
	return (list);
}
