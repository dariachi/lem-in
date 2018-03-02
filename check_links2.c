/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_links2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 17:22:25 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/08 17:22:27 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_malloc_truck(t_all *all, char *fir, char *sec)
{
	all->truck1 = malloc(sizeof(t_truck));
	all->truck1->next = NULL;
	all->truck1->f = malloc(sizeof(char) * ft_strlen(fir) + 1);
	all->truck1->s = malloc(sizeof(char) * ft_strlen(sec) + 1);
	all->truck2 = all->truck1;
	all->truck2->f = ft_strcpy(all->truck2->f, fir);
	all->truck2->s = ft_strcpy(all->truck2->s, sec);
}

void	ft_malloc_truck_2(t_all *all, char *ff, char *ss)
{
	all->truck3 = malloc(sizeof(t_truck));
	all->truck3->f = malloc(sizeof(char) + ft_strlen(ff) + 1);
	all->truck3->s = malloc(sizeof(char) + ft_strlen(ss) + 1);
	all->truck3->f = ft_strcpy(all->truck3->f, ff);
	all->truck3->s = ft_strcpy(all->truck3->s, ss);
	all->truck3->next = NULL;
}

void	truck_end2(t_all *all)
{
	while (all->truck2->next)
		all->truck2 = all->truck2->next;
	all->truck2->next = all->truck3;
}
