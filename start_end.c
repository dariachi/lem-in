#include "lemin.h"

int 	end(t_all *all, char *str, char **s)
{
	all->end++;
	//printf("STR                %s\n", str);
	if(get_next_line(0, &str) == 0)
		return 0;
	all->i++;
	s[all->i] = ft_strdup(str);
	if(all->end != 1 || check_rooms(str, all) < 0)
	{
		printf("error\n");
		return 0;
	}
	all->en = ft_strdup(all->room3->name);
	all->room3->count = 0;
	free(str);
	return 1;
}

int 	start(t_all *all, char *str, char **s)
{

	all->start++;
	if(get_next_line(0, &str) == 0)
		return 0;
	all->i++;

	s[all->i] = ft_strdup(str);
	if(all->start != 1 || check_rooms(str, all) < 1)
	{
		printf("error\n");
		return 0;
	}
	all->st = ft_strdup(all->room3->name);
	all->room3->count = 0;
	free(str);
	return (1);
}

int		search_first_truck(t_all *all, char *sr)
{
	all->truck2 = all->truck1;
	while(all->truck2)
	{
		//printf("i %d %s %s\n", all->j, all->truck2->f, all->truck2->s);
		if(ft_strcmp(all->truck2->f, sr) == 0)
		{
			all->room3 = all->room1->next;
			while(all->room3)
			{
				if(ft_strcmp(all->truck2->s, all->room3->name) == 0 && all->room3->count == -1)
					all->room3->count = all->j;
				all->room3 = all->room3->next;
			}
		}
		else if(ft_strcmp(all->truck2->s, sr) == 0)
		{
			all->room3 = all->room1->next;
			while(all->room3)
			{
				if(ft_strcmp(all->truck2->f, all->room3->name) == 0 && all->room3->count == -1)
					all->room3->count = all->j;
				all->room3 = all->room3->next;
			}
		}
		all->truck2 = all->truck2->next;
	}
	return 1;
}

int		serch_next_truck(t_all *all)
{
	int l = 0;


	all->room4 = all->room1->next;
	while(all->room4->next)
	{
		if(all->room4->count == all->j - 1)
		{
			search_first_truck(all, all->room4->name);
			l = 1;
		}
		all->room4 = all->room4->next;
	}
	return l;
}

int		ft_position_def(t_all *all)
{
	all->j = 1;
	all->room2 = all->room1->next;
	while(all->room2->next)
	{

		if(ft_strcmp(all->room2->name, all->st) == 0)
		{
			all->j = 1;
			search_first_truck(all, all->room2->name);
		}
		all->room2 = all->room2->next;
		all->j++;
	}
	all->j = 2;
	all->room2 = all->room1->next;
	while(all->room2->next)
	{
		serch_next_truck(all);
		all->room2 = all->room2->next;
		all->j++;
	}
	return 1;
}