/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:18:45 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 18:20:38 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*aux;

	aux = *stack;
	while (*stack)
	{
		aux = *stack;
		*stack = (*stack)->next;
		free(aux);
	}
	stack = NULL;
}
