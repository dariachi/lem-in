/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 15:11:50 by dchirkin          #+#    #+#             */
/*   Updated: 2017/02/24 11:50:26 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		poss(char *str, char c, int g)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0' && (i < g))
		i++;
	if (str[i] == c && (i < g))
		return (i);
	else
		return (0);
}

int		kkk(char *rob, char *n, char **line)
{
	int		i;
	char	*nv;
	int		j;
	char *temp;

	j = 0;
	i = poss(rob, '\n', BUFF_SIZE);
	n++;
	nv = ft_strnew(BUFF_SIZE + 1);
	nv[BUFF_SIZE] = '\0';
	nv = ft_strncat(nv, rob, i);
	temp = *line;
	*line = ft_strjoin(temp, nv);
	free(temp);
	while (n[j] != '\0')
		j++;
	ft_memmove(rob, n, j + 1);
	ft_memset(rob + j + 1, '\0', BUFF_SIZE - j - 1);
	free(nv);
	return (1);
}

int		w(int ret, char **line, int fd, char *rob)
{
	char *nline;
	char *temp;

	nline = NULL;
	while ((rob[0] == '\0') || (ret == BUFF_SIZE))
	{
		ret = read(fd, rob, BUFF_SIZE);
		if (ret == 0)
		{
			if (rob[0] == '\0' && *line[0] == '\0')
				ft_strcpy(*line, rob);
			else
				return (1);
			return (0);
		}
		nline = ft_strchr(rob, '\n');
		if (nline == NULL)
		{
			temp = *line;
			*line = ft_strjoin(*line, rob);
			free(temp);
			ft_memset(rob, '\0', BUFF_SIZE);
		}
		else
			return (kkk(rob, nline, line));
	}
	return (1);
}

int		sear(char *rob, int fd, char **line)
{
	int		ret;
	char	*nline;
	char *temp;

	ret = 0;
	nline = NULL;
	if (rob[0] != '\0')
	{
		nline = ft_strchr(rob, '\n');
		if (nline != NULL)
			return (kkk(rob, nline, line));
		else
		{
			temp = *line;
			*line = ft_strjoin(*line, rob);
			free(temp);
			ft_memset(rob, '\0', BUFF_SIZE);
		}
	}
	ret = w(ret, line, fd, rob);
	{
		free(nline);
		return (ret);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char		*osn;
	int				num;

	if (!osn)
	{
		if (!(osn = malloc(BUFF_SIZE + 1)))
			return (-1);
		ft_memset(osn, '\0', BUFF_SIZE + 1);
	}
	num = 0;
	if (fd == -1 || (read(fd, NULL, 0) == -1) || fd == 1)
		return (-1);
	*line = ft_strnew(0);
	num = sear(osn, fd, line);
	return (num);
}
