/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:01:56 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 19:01:58 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_if_search_first_truck(t_all *all)
{
	all->room3 = all->room1->next;
	while (all->room3)
	{
		if (ft_strcmp(all->truck2->s, all->room3->name) == 0
			&& all->room3->count == -1)
			all->room3->count = all->j;
		all->room3 = all->room3->next;
	}
}

int		search_first_truck(t_all *all, char *sr)
{
	all->truck2 = all->truck1;
	while (all->truck2)
	{
		if (ft_strcmp(all->truck2->f, sr) == 0)
			ft_if_search_first_truck(all);
		else if (ft_strcmp(all->truck2->s, sr) == 0)
		{
			all->room3 = all->room1->next;
			while (all->room3)
			{
				if (ft_strcmp(all->truck2->f, all->room3->name) == 0
					&& all->room3->count == -1)
					all->room3->count = all->j;
				all->room3 = all->room3->next;
			}
		}
		all->truck2 = all->truck2->next;
	}
	return (1);
}
