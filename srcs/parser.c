/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:40:55 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/07 05:00:46 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*ft_store_piece(t_fill *list, char *line)
{
	int		i;
	int		count;
	char	*str;

	i = 0;
	count = 0;
	str = ft_cut_table(&line);// ERREUR C'EST UNE LIGNE PAS VRAIMENT TOUT LE TABLEAU !!
	while (str[i] && count < 2)
	{
		if (ft_isdigit(str[i]) && str[i - 1] == ' ' && count == 0)
		{
			count++;
			list->py = ft_atoi(&str[i]);
		}
		else if (ft_isdigit(str[i]) && str[i - 1] == ' ' && count == 1)
		{
			count++;
			list->px = ft_atoi(&str[i]);
		}
		i++;
	}
	ft_putstr_fd(str, 2);
	return (0);
}

static int		ft_store_table(t_fill *list, char *line)
{
	line = ft_store_piece(list, line);
	ft_putstr_fd(line ,2);
	if (list->table == 0)
		list->table = ft_strnew(ft_strlen(line));
	list->table = ft_reallocf(list->table, ft_strlen(line));
	list->table = ft_strcpy(list->table, line);
	list->table = ft_reallocf(list->table, 0);
	ft_putstr_fd(list->table, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

static int		ft_store_tabledata(t_fill *list, char *line)
{
	int		i;
	int		j;
	int		count;

	j = 0;
	i = 0;
	count = 0;
	while (line[i] && line[i] != ':')
	{
		if (ft_isdigit(line[i]) && line[i - 1] == ' ' && count == 0)
		{
			count++;
			list->taby = ft_atoi(&line[i]);
		}
		else if (ft_isdigit(line[i]) && line[i - 1] == ' ' && count == 1)
		{
			count++;
			list->tabx = ft_atoi(&line[i]);
		}
		i++;
	}
	ft_putchar_fd('\n', 2);
	ft_putnbr_fd(list->taby, 2);
	ft_putchar_fd(' ', 2);
	ft_putchar_fd('|', 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(list->tabx, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

static int		ft_store_playerdata(t_fill *list, char *line)
{
	int		i;
	int		j;
	size_t	size;
	char	*str;
	char	*tmp;

	j = 0;
	i = 0;
	size = ft_strlen(line);
	tmp = ft_strnew(size);
	str = ft_strnew(size);
	str = ft_strcpy(str,line);
	list->playernum = str[10];
	ft_putchar_fd(list->playernum, 2);
	ft_putchar_fd('\n', 2);
	i = 0;
	while (str[i - 1] != '[' && str[i])
		i++;
	while (str[i] != ']' && str[i])
		tmp[j++] = str[i++];
	ft_strdel(&str);
	list->playername = ft_reallocf(tmp, 0);
	ft_putstr_fd(list->playername, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

static void		ft_parse_first(t_fill *list, int fd)
{
	char	*line;
	int		i;
	int		res;

	i = 0;
	res = 0;
	line = NULL;
	while ((res = ft_get_next_line(fd, &line)) > 0)
	{
		ft_putstr_fd("res: ", 2);
		ft_putnbr_fd(res, 2);
		ft_putchar_fd('\n', 2);
		if (i < 1)
		{
			ft_store_playerdata(list ,line);
			ft_strdel(&line);
		}
		else if (i < 2)
		{
			ft_store_tabledata(list, line);
			ft_strdel(&line);
		}
		else
		{
			ft_store_table(list, line);
			ft_strdel(&line);
		}
		ft_putstr_fd("i: ", 2);
		ft_putnbr_fd(i, 2);
		ft_putchar_fd('\n', 2);
		i++;
	}
	ft_putstr_fd("res: ", 2);
	ft_putnbr_fd(res, 2);
	ft_putchar_fd('\n', 2);
}

int				ft_parser(t_fill *list)
{
	int		fd;

	fd = 0;
	ft_parse_first(list, fd);
	return (0);
}
