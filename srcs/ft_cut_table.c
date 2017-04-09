/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 04:27:10 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/07 04:59:06 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_cut_table(char **line)
{
	int		i;
	int		size;
	char	*tmp;
	char	*strtmp;

	i = 0;

	size = ft_strlen((*line));
	strtmp = ft_strnew(size);
	tmp = ft_strnew(size);
	while ((*line)[size] == '*' && (*line)[size] == '.')
	{
		tmp[i] = (*line)[size];
		size--;
	}
	tmp[i] = '\0';
	tmp = ft_strrev(tmp, i);
	tmp = ft_reallocf(tmp, 0);
	strtmp = ft_strcpy(strtmp, (*line));
	ft_strdel(&(*line));
	(*line) = ft_strnew(size);
	(*line) = ft_strncpy((*line), strtmp, size);
	(*line) = ft_reallocf((*line), 0);
	return (tmp);
}
