/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:05:10 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 21:01:51 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	ft_lstsize(t_node *stack)
{
	size_t		i;
	t_node	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	get_the_digit(int max_index)
{
	int	digits;

	digits = 0;
	while (max_index)
	{
		max_index /= 2;
		digits++;
	}
	return (digits);
}

void	radix(t_node **stack_a, t_node **stack_b, int stack_pos)
{
	int			digit;
	int			i;
	int			j;
	t_node	*aux;
	int			size;

	aux = *stack_a;
	size = ft_lstsize(aux);
	digit = get_the_digit(stack_pos);
	i = 0;
	while (i < digit)
	{
		j = 0;
		while (j++ < size)
		{
			aux = *stack_a;
			if ((aux->index >> i) & 1)
				do_rotate(stack_a, 'a');
			else
				do_push(stack_a, stack_b, 'a');
		}
		while (ft_lstsize(*stack_b) != 0)
			do_push(stack_a, stack_b, 'b');
		i++;
	}
}