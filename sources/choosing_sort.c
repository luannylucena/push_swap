/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choosing_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:46:58 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 21:18:15 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	choosing_sort(t_node**stack_a, t_node**stack_b, int stack_pos)
{
	if (stack_pos == 2)
		do_swap(stack_a, 'a');
	else if (stack_pos == 3)
		sort_three(stack_a);
	else if (3 < stack_pos && stack_pos <= 5)
		sort_up_to_five(stack_a, stack_b, stack_pos);
	else
		radix(stack_a, stack_b, stack_pos);
}