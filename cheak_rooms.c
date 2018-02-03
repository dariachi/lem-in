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

int		ft_cycle(t_all *all, char *str,  char **s)
{
		if(str[0] == ' ' || str[0] == '\n' || str[0] == '\0')
			return 0;
		else if(ft_strcmp("##start", str) == 0)
		{
			all->room3 = malloc(sizeof(t_node));
			all->room3->next = NULL;
			if(start(all, str, s) == 0)
				return 0;
		}
		else if(ft_strcmp("##end", str) == 0 )
		{
			all->room3 = malloc(sizeof(t_node));
			all->room3->next = NULL;
			if(end(all, str, s) == 0 || all->start == 0)
				return 0;
		}
		return 1;
}

int		cheak_all_rooms(t_all *all, char *str, char **s)
{
	while(get_next_line(0, &str))
	{
		s[all->i] = ft_strdup(str);
		if(str[0] == '#' && str[1] != '#')
		{
			all->i++;
			continue;
		}
		else if(ft_cycle(all, str, s) == 0)
		{
			printf("error\n");
			return 0;
		}
		else if(str[0] != '#')
		{
			all->room3 = malloc(sizeof(t_node));
			all->room3->next = NULL;
			int t = check_rooms(str, all);
			if(t == -1)
				break;
			if(t == 0)
			{
				printf("error\n");
				free(all->room3);
				return 0; 
			}
		}
		else if(str[0] == '#' && ft_strcmp("##start", str) != 0 && ft_strcmp("##end", str) != 0)
		{
			all->i++;
			continue ;
		}
		while(all->room2->next)
			all->room2 = all->room2->next;
		all->room2->next = all->room3;
		all->room2 = all->room2->next;
		all->i++;
	}
	return 1;
}
