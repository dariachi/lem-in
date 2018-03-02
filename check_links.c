/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:06:26 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 16:06:28 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			cheak_repeat(t_all *all)
{
	int		f;

	f = 0;
	all->truck2 = all->truck1;
	while (all->truck2)
	{
		all->room2 = all->room1->next;
		f = 0;
		while (all->room2)
		{
			if ((ft_strcmp(all->room2->name, all->truck2->f) == 0))
				f++;
			if (ft_strcmp(all->room2->name, all->truck2->s) == 0)
				f++;
			all->room2 = all->room2->next;
		}
		if (f < 2)
			return (0);
		all->truck2 = all->truck2->next;
	}
	return (1);
}

int			ft_add_links(t_all *all, char *str, int i, int h)
{
	char	ff[ft_strlen(str)];
	char	ss[ft_strlen(str)];

	while (str[i] != '-')
	{
		ff[i] = str[i];
		i++;
		if (str[i] == '\0')
		{
			free(str);
			return (0);
		}
	}
	ff[i] = '\0';
	h = i + 1;
	i = 0;
	while (str[h] != '\0')
	{
		ss[i] = str[h];
		i++;
		h++;
	}
	ss[i] = '\0';
	ft_malloc_truck_2(all, ff, ss);
	return (1);
}

void		ft_add_links2(char *str, t_all *all)
{
	char	fir[ft_strlen(str)];
	char	sec[ft_strlen(str)];
	int		i;

	i = 0;
	all->i++;
	while (*str != '-')
	{
		fir[i] = *str;
		i++;
		str++;
	}
	fir[i] = '\0';
	i = 0;
	str++;
	while (*str != '\0')
	{
		sec[i] = *str;
		i++;
		str++;
	}
	sec[i] = '\0';
	ft_malloc_truck(all, fir, sec);
}

int			check_links(char *str, t_all *all, char **s)
{
	ft_add_links2(str, all);
	while (get_next_line(0, &str))
	{
		s[all->i] = ft_strdup(str);
		all->i++;
		if ((str[0] == '#' && str[1] != '#') || str[0] == '\n')
		{
			free(str);
			continue ;
		}
		else
		{
			if (ft_add_links(all, str, 0, 0) == 0)
				return (0);
			truck_end2(all);
		}
		free(str);
	}
	if (str)
		free(str);
	if (cheak_repeat(all) == 0)
		return (0);
	return (1);
}
