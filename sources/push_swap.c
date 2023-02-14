/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:23:03 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:39:31 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_bool	is_sorted(t_node *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->content < stack_a->next->content)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

t_bool	stack_init(int argc, char **argv, int *stack_pos, t_node **stack_a)
{
	t_bool	error;

	--argc;
	*stack_a = ft_new_stack(ft_atoi_long(*++argv, &error), (*stack_pos)++); //pode dar algum erro nesse atoi
	if (error)
		return (writing_error());
	error = 1;
	while (--argc) //para tirar o ./push_swap.
	{
		ft_insert_node_back(stack_a, //cria leemento e vai jogando no final da lista e ficar na ordem.
			ft_new_stack(ft_atoi_long(*++argv, &error), (*stack_pos)++));
		if (error)
			return (writing_error());
		error = 1;
	}
	return (1);
}

int main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     stack_pos;

    stack_b = NULL;
    stack_pos = 0;
    if (argc < 3)
        return (1);
    if (!stack_init(argc, argv, &stack_pos, &stack_a))
    {
        free_stack(&stack_a);
        return(1);
    }
    ft_fiding_index(stack_a);
    if (!is_sorted(stack_a))
        choosing_sort(&stack_a, &stack_b, stack_pos);
    free_stack(&stack_a);
    return(0);
}
