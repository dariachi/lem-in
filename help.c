#include "lemin.h"
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "get_next_line.h"


int     ft_number(int num)
{
    int             i;

    i = 0;
    while (num / 10 > 0)
    {
            num /= 10;
            i++;
    }
    i += 2;
    return (i);
}

int 	number_ants(t_all *all, char *str)
{
	int l;

	all->ants = ft_atoi(str);
	all->index = 1;
	all->ants_str = ft_itoa(all->ants);
	l = ft_strcmp(all->ants_str, str);
	free(all->ants_str);
	if(l != 0 || all->ants == 0 || all->ants < 0 || all->ants > INT)
	{
		printf("error\n");
		return 0;
	}
	return 1;
}

int 	cheak_repeats(t_all *all, int u, int x, int y)
{
	char s[u + 1];
	ft_strcpy(s, all->room3->name);
	all->room2 = all->room1;

	while(all->room2->next)
	{
		all->room2 = all->room2->next;
		if(x == all->room2->x && y == all->room2->y)
		{
			free(all->room3->name);
			free(all->room3);
			return 0;
		}
		if(ft_strcmp(all->room2->name, s) == 0)
		{
			free(all->room3->name);
			free(all->room3);
			return 0;
		}
	}
	return 1;
}

int 	check_rooms(char *str, t_all *all)
{
	char s[ft_strlen(str)];
	int i = 0;
	all->room3->name = malloc(ft_strlen(str) + 2);


	while(str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	if(str[i] == '\0' || str[i] == '\n')
	{
		s[i] = '\0';
		free(all->room3);
		if(ft_strchr(s, '-') == NULL)
			return 0;
		return -1;
	}
	s[i] = '\0';


	if(ft_strchr(s, '-') != NULL || s[0] == 'L')
	{
		free(all->room3);
		return 0;
	}
	all->room3->name = ft_strcpy(all->room3->name, s);
	int x = valid_num(&str[i]);
	int q = ft_number(x);
	if(str[i + q] != ' ')
	{
		free(all->room3->name);
		free(all->room3);
		return 0;
	}
	int y = valid_num(&str[i + q]);
	q += ft_number(y);
	if(ft_strcmp(&str[i + q], "") != 0)
	{
		free(all->room3->name);
		free(all->room3);
		return 0;
	}
	all->room3->x = x;
	all->room3->y = y;
	all->room3->count = -1;
	return(cheak_repeats(all, ft_strlen(all->room3->name), x, y));
}

int		ft_serch_ants(t_all *all, char *str, char **s)
{
	while(get_next_line(0, &str))
	{
		s[all->i] = ft_strdup(str);
		if(str[0] == ' ' || str[0] == '\n' || str[0] == '\0')
		{
			free(str);
			return 0;
		}
		else if(str[0] == '#' && str[1] != '#')
		{
			all->i++;
			free(str);
			continue ;
		}
		else if(all->index == 0)
		{
			if(number_ants(all, str) == 0)
			{
				free(str);
				return 0;
			}
		}
		if(all->ants != 0)
		{
			free(str);
			break ;
		}
		all->i++;
		free(str);
	}
	return 1;
}