/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:22:56 by dchirkin          #+#    #+#             */
/*   Updated: 2018/02/07 14:22:58 by dchirkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				valid_num(char *str)
{
	int			k;

	k = ft_atoi(str);
	return (k);
}

int				ft_next_main(t_all *all, char **s, char *str)
{
	all->start = 0;
	all->end = 0;
	all->i = 0;
	if (ft_serch_ants(all, str, s) == 0)
		return (0);
	all->i++;
	if (cheak_all_rooms(all, str, s) == 0)
		return (0);
	if (all->start != 1 || all->end != 1)
		return (0);
	return (1);
}

char			**ft_mall_s(t_all *all)
{
	char		**s;
	int			i;

	all->index = 0;
	all->max_lines = 9999;
	if ((s = malloc(sizeof(char *) * all->max_lines)) == NULL)
		return (NULL);
	i = 0;
	while (i < all->max_lines)
		s[i++] = NULL;
	all->room1 = malloc(sizeof(t_node));
	all->room1->next = NULL;
	all->room2 = all->room1;
	return (s);
}

int				main(void)
{
	t_all		all;
	char		**s;
	char		*str;

	s = ft_mall_s(&all);
	str = NULL;
	if (ft_next_main(&all, s, str) == 0)
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	all.j = next_next_main(&all, s, str);
	if (all.j == 0)
	{
		ft_putstr("ERROR\n");
		free(all.st);
		free(all.en);
		return (0);
	}
	else if (all.j == 1)
		return (0);
	free(s);
	free(all.en);
	free(all.st);
	return (0);
}
