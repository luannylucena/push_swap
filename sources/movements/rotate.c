/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:32:56 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:32:18 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*aux;
	t_node	*last;

	last = ft_get_last_node(*stack);
	aux = *stack;
	last->next = aux;
	*stack = aux->next;
	aux->next = NULL;
}

void	do_rotate(t_node **stack, char c)
{
	if (c == 'a')
	{
		rotate(stack);
		ft_putstr_fd("ra\n", STDOUT_FILENO);
	}
	if (c == 'b')
	{
		rotate(stack);
		ft_putstr_fd("rb\n", STDOUT_FILENO);
	}
}
