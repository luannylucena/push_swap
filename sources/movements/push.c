/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:30:48 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:32:00 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*aux;

	if (*src == NULL)
		return ;
	aux = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = aux;
}

void    do_push(t_node **stack_a, t_node **stack_b, char c)
{
	if (c == 'a')
	{
		push(stack_a, stack_b);
		ft_putstr_fd("pa\n", STDOUT_FILENO);
	}
	if (c == 'b')
	{
		push(stack_b, stack_a);
		ft_putstr_fd("pb\n", STDOUT_FILENO);
	}
}