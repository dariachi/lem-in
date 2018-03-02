/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:47:58 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 15:48:00 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_number(int num)
{
	int		i;

	i = 0;
	while (num / 10 != 0)
	{
		num /= 10;
		i++;
	}
	if (num < 0)
		i++;
	i += 2;
	return (i);
}

int			number_ants(t_all *all, char *str)
{
	int		l;

	all->ants = ft_atoi(str);
	all->index = 1;
	all->ants_str = ft_itoa(all->ants);
	l = ft_strcmp(all->ants_str, str);
	free(all->ants_str);
	if (l != 0 || all->ants == 0 || all->ants < 0 || all->ants > INT)
		return (0);
	return (1);
}

int			cheak_repeats(t_all *all, int x, int y)
{
	all->room2 = all->room1;
	while (all->room2->next)
	{
		all->room2 = all->room2->next;
		if (x == all->room2->x && y == all->room2->y)
		{
			free(all->room3->name);
			free(all->room3);
			return (0);
		}
		if (ft_strcmp(all->room2->name, all->room3->name) == 0)
		{
			free(all->room3->name);
			free(all->room3);
			return (0);
		}
	}
	return (1);
}

void		creat_two_str(char *str, char *s1, char *s2, int i)
{
	int		h;

	while (str[i] != ' ')
		i++;
	i++;
	h = 0;
	while (str[i] != ' ')
	{
		s1[h] = str[i];
		h++;
		i++;
	}
	s1[h] = '\0';
	h = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		s2[h] = str[i];
		h++;
		i++;
	}
	s2[h] = '\0';
}

int			cheak(char *str, int x, int y, int i)
{
	char	s1[ft_strlen(str)];
	char	s2[ft_strlen(str)];

	creat_two_str(str, s1, s2, i);
	if (y < 0)
	{
		if (ft_strchr(s2, '-') == NULL)
			return (0);
	}
	if (x < 0)
	{
		if (ft_strchr(s1, '-') == NULL)
			return (0);
	}
	return (1);
}
