/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_up_to_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:13:04 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 21:14:17 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

static int	find_smallest_num_index(t_node **stack_a, int smallest_num)
{
	int			i;
	t_node	*aux;

	aux = *stack_a;
	i = 0;
	while (aux)
	{
		if (aux->index == smallest_num)
			break ;
		aux = aux->next;
		i++;
	}
	return (i);
}

void	sort_up_to_five(t_node **stack_a, t_node **stack_b,
		int stack_pos)
{
	int	curr_index;
	int	smallest_num;
	int	middle;
	int	total_pos;

	total_pos = stack_pos;
	smallest_num = 0;
	while (stack_pos > 3)
	{
		curr_index = find_smallest_num_index(stack_a, smallest_num);
		middle = total_pos / 2;
		while ((*stack_a)->index != smallest_num)
		{
			if (curr_index <= middle)
				do_rotate(stack_a, 'a');
			else
				do_reverse_rotate(stack_a, 'a');
		}
		do_push(stack_a, stack_b, 'a');
		stack_pos--;
		smallest_num++;
	}
	sort_three(stack_a);
	while (*stack_b)
		do_push(stack_a, stack_b, 'b');
}