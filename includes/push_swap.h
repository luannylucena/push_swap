/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:05:26 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 21:02:51 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

void	ft_fiding_index(t_node *a);
void	do_swap(t_node **list, char c);
void	do_push(t_node **stack_a, t_node **stack_b, char c);
void	do_rotate(t_node **list, char c);
void	do_reverse_rotate(t_node **list, char c);
void	choosing_sort(t_node **stack_a, t_node **stack_b, int stack_pos);
void	sort_three(t_node **stack_a);
void	sort_up_to_five(t_node **stack_a, t_node **stack_b, int stack_pos);
void	free_stack(t_node **stack);
void	radix(t_node **stack_a, t_node **stack_b, int stack_pos);
int     writing_error(void);

#endif