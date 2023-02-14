#include "../includes/push_swap.h"

//idea do double sort

void    ft_fiding_index(t_node *a)
{
	t_node  *i;
	t_node  *j;
	int     counter;

	i = a;
	while (i)
	{
		j = a;
		counter = 0;
		while (j)
		{
			if (i->content < j->content)
				j->index++;
			else if (i->content == j->content)
			{
				counter++;
				if (counter == 2)//verificação dos numeros iguais.
					writing_error();
			}
			j = j->next;
		}
		i = i->next;
	}
}