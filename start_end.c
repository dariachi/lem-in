/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:30:13 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/07 15:30:15 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		more_than_need_star_end(char *str)
{
	free(str);
	return (0);
}

int		end(t_all *all, char *str, char **s)
{
	all->end++;
	if (get_next_line(0, &str) == 0)
		return (more_than_need_star_end(str));
	all->i++;
	s[all->i] = ft_strdup(str);
	while (str[0] == '#' && str[1] != '#')
	{
		free(str);
		if (get_next_line(0, &str) == 0)
			return (0);
		all->i++;
		s[all->i] = ft_strdup(str);
	}
	if (check_rooms(str, all) <= 0)
		return (more_than_need_star_end(str));
	if (all->end != 1)
		return (more_than_need_star_end(str));
	all->en = ft_strdup(all->room3->name);
	all->room3->count = 0;
	free(str);
	return (1);
}

int		start(t_all *all, char *str, char **s)
{
	all->start++;
	if (get_next_line(0, &str) == 0)
		return (more_than_need_star_end(str));
	all->i++;
	s[all->i] = ft_strdup(str);
	while (str[0] == '#' && str[1] != '#')
	{
		free(str);
		if (get_next_line(0, &str) == 0)
			free(str);
		all->i++;
		s[all->i] = ft_strdup(str);
	}
	if (all->start != 1)
		return (more_than_need_star_end(str));
	if (str[0] == '#' && str[1] == '#')
		return (more_than_need_star_end(str));
	if (check_rooms(str, all) < 1)
		return (0);
	all->st = ft_strdup(all->room3->name);
	all->room3->count = 0;
	free(str);
	return (1);
}

int		serch_next_truck(t_all *all)
{
	int	l;

	l = 0;
	all->room4 = all->room1->next;
	while (all->room4)
	{
		if (all->room4->count == all->j - 1)
		{
			search_first_truck(all, all->room4->name);
			l = 1;
		}
		all->room4 = all->room4->next;
	}
	return (l);
}

int		ft_position_def(t_all *all)
{
	all->j = 1;
	all->room2 = all->room1->next;
	while (all->room2->next)
	{
		if (ft_strcmp(all->room2->name, all->st) == 0)
		{
			all->j = 1;
			search_first_truck(all, all->room2->name);
		}
		all->room2 = all->room2->next;
		all->j++;
	}
	all->j = 2;
	all->room2 = all->room1->next;
	while (all->room2->next)
	{
		serch_next_truck(all);
		all->room2 = all->room2->next;
		all->j++;
	}
	return (1);
}
