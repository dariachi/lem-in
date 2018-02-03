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

int		check_links(char *str, t_all *all, char **s)
{
	s[all->i] = ft_strdup(str);
	all->i++;
	char fir[ft_strlen(str)];
	char sec[ft_strlen(str)];
	int i = 0;
	while(*str != '-')
	{
		fir[i] = *str;
		i++;
		str++;
	}
	fir[i] = '\0';
	i = 0;
	str++;
	while(*str != '\0')
	{
		sec[i] = *str;
		i++;
		str++;
	}
	sec[i] = '\0';
	ft_malloc_truck(all, fir, sec);
	while(get_next_line(0, &str))
	{
		s[all->i] = ft_strdup(str);
		all->i++;
		if(str[0] == '#' && str[1] != '#')
		{
			free(str);
			continue ;
		}
		else if(str[0] == '\n')
		{
			free(str);
			return 0;
		}
		else
		{
			char ff[ft_strlen(str)];
			char ss[ft_strlen(str)];
			i = 0;
			while(str[i] != '-')
			{
				ff[i] = str[i];
				i++;
				
				if(str[i] == '\0')
					return 0;
			}
			ff[i] = '\0';
			int h = i + 1;
			i = 0;
		
			while(str[h] != '\0')
			{
				ss[i] = str[h];
				i++;
				h++;
			}
			ss[i] = '\0';

			ft_malloc_truck_2(all, ff, ss);
			while(all->truck2->next)
				all->truck2 = all->truck2->next;
			all->truck2->next = all->truck3;
		}
		free(str);
	}
	free(str);
	int f = 0;
	all->truck2 = all->truck1;
	while(all->truck2)
	{
		all->room2 = all->room1->next;
		f = 0;
		while(all->room2)
		{
			if((ft_strcmp(all->room2->name, all->truck2->f) == 0))
				f++;
			if(ft_strcmp(all->room2->name, all->truck2->s) == 0)
				f++;
			all->room2 = all->room2->next;
		}
		if(f < 2)
			return 0;
		all->truck2 = all->truck2->next;
	}

	return 1;
}