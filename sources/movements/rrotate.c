/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:36:20 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:34:14 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rrotate(t_node **stack)
{
	t_node	*aux;
	t_node	*last;

	aux = *stack;
	while (aux->next->next)
		aux = aux->next;
	last = ft_get_last_node(*stack);
	last->next = *stack;
	*stack = last;
	aux->next = NULL;
}

void	do_reverse_rotate(t_node **stack, char c)
{
	if (c == 'a')
	{
		rrotate(stack);
		ft_putstr_fd("rra\n", STDOUT_FILENO);
	}
	if (c == 'b')
	{
		rrotate(stack);
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
	}
}
