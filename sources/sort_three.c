/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:05:03 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 20:27:46 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//Meu objetivo é garantir que eu os classifique do menor para o maior em não mais do que duas ações
//Com cada caso, eu comparo de cima para o meio, do meio para baixo e de baixo para cima. Dependendo de 
//qual número é maior ou menor, afetará quais ações eu chamo.

void	sort_three(t_node **stack_a)
{
	int	frst;
	int	snd;
	int	thrd;

	frst = (*stack_a)->content;
	snd = (*stack_a)->next->content;
	thrd = (*stack_a)->next->next->content;
	if (frst < snd && frst < thrd && snd > thrd)
	{
		do_reverse_rotate(stack_a, 'a');
		do_swap(stack_a, 'a');
	}
	if (frst > snd && frst < thrd && snd < thrd)
		do_swap(stack_a, 'a');
	if (frst < snd && frst > thrd && snd > thrd)
		do_reverse_rotate(stack_a, 'a');
	if (frst > snd && frst > thrd && snd < thrd)
		do_rotate(stack_a, 'a');
	if (frst > snd && frst > thrd && snd > thrd)
	{
		do_rotate(stack_a, 'a');
		do_swap(stack_a, 'a');
	}
}
