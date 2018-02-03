#include "lemin.h"
#include "get_next_line.h"

int 	valid_num(char *str)
{
	int k;
	char *u;

	k = ft_atoi(str);
	return k;
}

int 	ft_next_main(t_all *all, char **s, char *str)
{
	all->i = 0;
	if(ft_serch_ants(all, str, s) == 0)
		return 0;
	all->i++;
	if(cheak_all_rooms(all, str, s) == 0)
		return 0;
	if(all->start != 1 || all->end != 1)
		return 0;
	return 1;
}


int		main(void)
{
	t_all all;
	char **s;
	all.start = 0;
	all.end = 0;

	char *str;
	int     maxLines;
	int     i;
	all.index = 0;

	maxLines = 9999;
	if((s = malloc(sizeof(char *) * maxLines)) == NULL)
		return 0;
	i = 0;
	while (i < maxLines)
		s[i++] = NULL;
	all.room1 = malloc(sizeof(t_node));
	all.room1->next = NULL;
	all.room2 = all.room1;

	if(ft_next_main(&all, s, str) == 0)
	{
		printf("ERROR\n");
		return 0;
	}
	if(next_next_main(&all, s, str) == 0)
	{
		printf("ERROR\n");
		return 0;
	}


	all.room2 = all.room1->next;
	while(all.room2)
	{
		all.room3 = all.room2;
		all.room2 = all.room2->next;
		free(all.room3);
	}
	free(all.room1);

	free(all.en);
	free(all.st);
	return 0;
}