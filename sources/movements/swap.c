/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:22:29 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:36:06 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(t_node **stack)
{
	t_node	*aux;

	if (*stack != NULL && (*stack)->next != NULL) // Verifico se tem pelo menos 2 elementos
	{
		aux = (*stack)->next;
		(*stack)->next = (*stack)->next->next;
		aux->next = *stack;
		*stack= aux;		
	}
}

void	do_swap(t_node **stack, char c)
{
	if (c == 'a')
	{
		ft_swap(stack);
		ft_putstr_fd("sa\n", STDOUT_FILENO);
	}
	if (c == 'b')
	{
		ft_swap(stack);
		ft_putstr_fd("sb\n", STDOUT_FILENO);
	}
}
