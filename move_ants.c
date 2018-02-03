#include "lemin.h"

int	embedded_loop(t_all *all, t_relations **z, t_tint *d, int *mas, int ant)
{
	//t_relations *d1, *d2;

	int found = 0;
	while (all->d1)
    {
        if (all->d1->r == ant)
        {
            printf("L%d-", ant);
            all->d1->r = 0;
            all->d1 = all->d1->next;
            all->d1->r = ant;
            printf("%s ", all->d1->rel);
            if (!ft_strcmp(all->d1->rel, all->en))
            {
                mas[ant - 1] = 0;
                all->d1->r = 0;
                }
            found = 1;
        }
        if (found)
            break;
        all->d1 = all->d1->next;
    }
    return found;
}

int	embedded_loop2(t_all *all, t_relations **z, t_tint *d, int *mas, int ant, int j)
{
	int o = 0;
	int found = 0;
	while (all->d1)
    {
        // printf("len %d\n", d[j].len);
        if (all->d1->r == 0 && o == 0 && ant <= all->ants && d[j].len - d[0].len < all->ants)
        {
            printf("L%d-%s ", ant, all->d1->rel);
            all->d1->r = ant;
            if (!ft_strcmp(all->d1->rel, all->en))
            {
                mas[ant - 1] = 0;
                all->d1->r = 0;
            }
        found = 1;
        }
        else if(all->d1->r != 0)
        {
            o = all->d1->r;
        }
        if (found == 1)
            break;
        all->d1 = all->d1->next;
    }
    return found;
}

void	embedded_cycle(t_all *all, t_relations **z, t_tint *d, int *mas)
{
	int ant = 1;
	int ch = 0;
    int j = 0;
    int found;
	while (ant - 1 < all->ants)
    {
        j = 0;
        found = 0;
        while(mas[ant - 1] == 0)
            ant++;
        while (d[j].i != -1)
        {
            all->d1 = z[d[j].i]->next;
            found = embedded_loop(all, z, d, mas, ant);
            if (found)
                break;
            j++;
        }
        if (found == 0)
        {
            j = 0;
            while (d[j].i != -1)
            {
                all->d1 = z[d[j].i]->next;
                found = embedded_loop2(all, z, d, mas, ant, j);
                if (found)
                    break;
                j++;
            }
        }
    	ant++;
    }
}

void	move_ants(t_all *all, t_relations **z, t_tint *d, int *mas)
{
	int u = 1;
	int x = 0;
    int len = 0;
    int y = 1;
    int c = 0;

    while(d[y].i != -1)
        y++;

    u = 1;
    x = d[0].i;
    len = d[0].len;
    c = 0;
    while(d[u].i != -1)
    {
        int k = 0;
        c = 0;
        while(d[k].i != -1)
        {
            x = d[c].i; 
            len = d[c].len;
            if(d[k].len < len)
            {
                d[c].len = d[k].len;
                d[k].len = len;
                d[c].i = d[k].i;
                d[k].i = x;
                c = k;
            }
            k++;
        }
        u++;
    }



    u = 0;
	while(are_there_any_ants(mas, all->ants))
	{
		embedded_cycle(all, z, d, mas);
		printf("\n");
    }
}