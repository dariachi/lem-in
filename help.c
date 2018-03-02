/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:10:48 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 15:10:50 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		cheak_coord(t_all *all, char *str, char *s, int i)
{
	if (ft_strchr(s, '-') != NULL || s[0] == 'L')
		return (0);
	ft_strcpy(all->room3->name, s);
	if (ft_strcmp(&str[i + 1], "-0123456789") < 0)
	{
		if (ft_isdigit(str[i + 1]) == 0)
			return (0);
	}
	all->cof.x = valid_num(&str[i]);
	all->q = ft_number(all->cof.x);
	if (str[i + all->q] != ' ')
		return (more_than_need_star_end(str));
	all->cof.y = valid_num(&str[i + all->q]);
	all->q += ft_number(all->cof.y);
	if (ft_strcmp(&str[i + all->q], "") != 0 ||
		cheak(str, all->cof.x, all->cof.y, 0) == 0)
	{
		free(all->room3->name);
		free(all->room3);
		return (0);
	}
	all->room3->x = all->cof.x;
	return (1);
}

int		creat_name(t_all *all, char *str, char *s, int i)
{
	if (str[i] == '\0' || str[i] == '\n')
	{
		s[i] = '\0';
		free(all->room3->name);
		free(all->room3);
		if (ft_strchr(s, '-') == NULL)
		{
			if (str[0] != '#')
				free(str);
			return (0);
		}
		return (-1);
	}
	s[i] = '\0';
	return (2);
}

int		check_rooms(char *str, t_all *all)
{
	char	s[ft_strlen(str)];
	int		i;
	int		x;

	i = 0;
	all->room3->name = malloc(ft_strlen(str) + 2);
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	x = creat_name(all, str, s, i);
	if (x != 2)
		return (x);
	if (cheak_coord(all, str, s, i) == 0)
		return (0);
	all->room3->y = all->cof.y;
	all->room3->count = -1;
	if (cheak_repeats(all, all->cof.x, all->cof.y) == 0)
	{
		free(str);
		return (0);
	}
	return (1);
}

int		ft_serch_ants2(t_all *all, char *str)
{
	if (str[0] == ' ' || str[0] == '\n' || str[0] == '\0')
	{
		free(str);
		return (0);
	}
	else if (str[0] == '#' && str[1] != '#')
	{
		all->i++;
		free(str);
		return (-1);
	}
	else if (all->index == 0)
	{
		if (number_ants(all, str) == 0)
		{
			free(str);
			return (0);
		}
	}
	return (1);
}

int		ft_serch_ants(t_all *all, char *str, char **s)
{
	all->ants = 0;
	while (get_next_line(0, &str))
	{
		if (str == NULL)
			return (0);
		s[all->i] = ft_strdup(str);
		all->tt = ft_serch_ants2(all, str);
		if (all->tt == 0)
			return (0);
		if (all->tt == -1)
			continue;
		if (all->ants != 0)
		{
			free(str);
			break ;
		}
		all->i++;
		free(str);
	}
	if (all->ants == 0)
	{
		free(str);
		return (0);
	}
	return (1);
}
