/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:40:55 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/09 23:34:27 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_store_piece_next(t_fill *list, char *line)
{
	char	*str;

	if (list->piece == NULL)
	{
		list->piece = ft_strnew(ft_strlen(line) + 1);
		list->piece = ft_strcpy(list->piece, line);
		list->piece[ft_strlen(list->piece) + 1] = '\0';
		ft_strdel(&line);
	}
	else
	{
		str = ft_strnew(ft_strlen(line) + ft_strlen(list->piece) + 1);
		list->piece[ft_strlen(list->piece)] = '\n';
		str = ft_strjoin(list->piece, line);
		ft_strdel(&line);
		ft_strdel(&list->piece);
		list->piece = ft_reallocf(str , 0);
	}
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Piece:\n", 2);
	ft_putstr_fd(list->piece, 2);
	return (0);
}

static int		ft_store_piece(t_fill *list, char *line)
{
	int		i;
	int		count;
	char	*str;

	count = 0;
	i = 0;
	str = ft_strnew(ft_strlen(line));
	while(line[i] && (line[i] != '*' || line[i] != '.'))
	{
		if (ft_isdigit(line[i]))
		{
			if (line[i - 1] == ' ' && count == 0)
			{
				list->py = ft_atoi(&line[i]);
				count++;
			}
			else if (line[i - 1] == ' ' && count == 1)
			{
				list->px = ft_atoi(&line[i]);
				count++;
			}
		}
		i++;
	}
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Piece size: ", 2);
	ft_putnbr_fd(list->py, 2);
	ft_putstr_fd(" | ", 2);
	ft_putnbr_fd(list->px, 2);
	return (0);
}

static int		ft_store_table(t_fill *list, char *line)
{
	if (ft_isdigit(line[0]) || ft_isspace(line[0]))
	{
		if (list->table == 0)
			list->table = ft_strnew(ft_strlen(line));
		list->table = ft_reallocf(list->table, ft_strlen(line));
		list->table = ft_strcpy(list->table, line);
		list->table = ft_reallocf(list->table, 0);
		ft_putchar_fd('\n', 2);
		ft_putstr_fd("Table:", 2);
		ft_putstr_fd(list->table, 2);
	}
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
	ft_putstr_fd("Size: ", 2);
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
	ft_putstr_fd("Playernum: ", 2);
	ft_putchar_fd(list->playernum, 2);
	ft_putchar_fd('\n', 2);
	i = 0;
	while (str[i - 1] != '[' && str[i])
		i++;
	while (str[i] != ']' && str[i])
		tmp[j++] = str[i++];
	ft_strdel(&str);
	list->playername = ft_reallocf(tmp, 0);
	ft_putstr_fd("Playername: ", 2);
	ft_putstr_fd(list->playername, 2);
	ft_putchar_fd('\n', 2);
	return (1);
}

static void		ft_parsing(t_fill *list, int fd)
{
	char	*line;
	int		i;
	int		res;

	i = 0;
	res = 0;
	line = NULL;
	while ((res = ft_get_next_line(fd, &line)) > 0)
	{
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
		else if (i <= list->taby + 2)
		{
			ft_store_table(list, line);
			ft_strdel(&line);
		}
		else if (i > list->taby + 2 && i < list->taby + 4)
		{
			ft_store_piece(list, line);
			ft_strdel(&line);
		}
		else
			ft_store_piece_next(list, line);
		i++;
	}
}

int				ft_parser(t_fill *list)
{
	int		fd;

	fd = 0;
	ft_parsing(list, fd);
	ft_putchar_fd('\n', 2);
	return (0);
}
