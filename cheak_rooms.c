/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:49:59 by dchirkin          #+#    #+#             */
/*   Updated: 2018/01/31 14:50:01 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_cycle(t_all *all, char *str, char **s)
{
	if (str[0] == ' ' || str[0] == '\n' || str[0] == '\0')
	{
		free(str);
		return (0);
	}
	else if (ft_strcmp("##start", str) == 0)
	{
		malloc_room3(all);
		if (start(all, str, s) == 0)
		{
			free(str);
			return (0);
		}
	}
	else if (ft_strcmp("##end", str) == 0)
	{
		malloc_room3(all);
		if (end(all, str, s) == 0)
		{
			free(str);
			return (0);
		}
	}
	return (1);
}

void	stuct_room(char *str, t_all *all)
{
	while (all->room2->next)
		all->room2 = all->room2->next;
	all->room2->next = all->room3;
	all->room2 = all->room2->next;
	all->i++;
	free(str);
}

int		cheak_comments(t_all *all, char *str)
{
	if (str[0] == '#' && ft_strcmp("##start", str) != 0 &&
			ft_strcmp("##end", str) != 0)
	{
		all->i++;
		free(str);
		return (1);
	}
	return (2);
}

int		cheak_comment(t_all *all, char *str)
{
	if (str[0] == '#' && str[1] != '#')
	{
		all->i++;
		free(str);
		return (1);
	}
	return (2);
}

int		cheak_all_rooms(t_all *all, char *str, char **s)
{
	while (get_next_line(0, &str))
	{
		s[all->i] = ft_strdup(str);
		if (cheak_comment(all, str) == 1)
			continue;
		else if (ft_cycle(all, str, s) == 0)
			return (0);
		else if (str[0] != '#')
		{
			malloc_room3(all);
			all->tt = check_rooms(str, all);
			if (all->tt == -1)
				break ;
			if (all->tt == 0)
				return (0);
		}
		else if (cheak_comments(all, str) == 1)
			continue;
		stuct_room(str, all);
	}
	free(str);
	return (1);
}
