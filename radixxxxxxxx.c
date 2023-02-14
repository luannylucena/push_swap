/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radixxxxxxxx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmedeiro <lmedeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:05:10 by lmedeiro          #+#    #+#             */
/*   Updated: 2023/02/13 21:12:28 by lmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

int	ft_lstsize(t_node *head) //qtos numeros tem na lista. pra tb saber qtas vezes loopar. 
{
	size_t		i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static int	get_max_bits(t_node **stack) //pega o maior numero da lsita em binário, pra saber qtos digitos tem e qtas vezes vai loopar. ex: 3 é 11 em binário, etnao vai loopar 2x. 
{
	t_node	*head; //auxiliar para stack a.
	int			max;
	int			max_bits;

	head = *stack; //mexo na stack com o auxiliar.
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_node **stack_a, t_node **stack_b)
{
	int			digit;
	int			i;
	int			j;
	t_node		*head_a;
	int			size;

	head_a = *stack_a;
	size = ft_lstsize(head_a); //qtos numeros tem na lista dada no terminal;
	digit = get_max_bits(stack_a); 
	i = 0;
	while (i < digit) //i muda a casa binária. 
	{
		j = 0;// faz iteração do numeros da lsita. muda de numer. 
		while (j++ < size) //o j é casa. o size é enquanto tiver numeros da lista.
		{
			head_a = *stack_a;
			if ((head_a->index >> i) & 1) //o i e a casa do numero binário. ele compara com 1 e se for verdaeiro, vai pro final da lista. se for zero, ele faz o push pra stack b.
				do_rotate(stack_a, 'a');// qdo for 1 ele dá o rotate ro final da lista na stack a. qdo for zero vai pra stack. 
			else
				do_push(stack_a, stack_b, 'a');
		}
		while (ft_lstsize(*stack_b) != 0)//aqui puxa do b pro a de volta. 
			do_push(stack_a, stack_b, 'b');
		i++; //
	}
}

#include "../includes/push_swap.h"

//aqui pega o index do menor numero para jogar pra stack B.  
static int	find_smallest_num_index(t_node **stack_a, int smallest_num)
{
	int			i;
	t_node	*aux;

	aux = *stack_a; //vao loopando a partir do primeiro numero da lista e vai procurando o menor numero, dai retorna a posição na lista do menor numero(index)
	i = 0; 
	while (aux)
	{
		if (aux->index == smallest_num)//se ekle achar o menro numero, para (break) e retorna o i. 
			break ;
		aux = aux->next;//se nao for, vai pro proximo.
		i++;
	}
	return (i); //retorna qtas vezes loopou (é o index =p)
}

void	sort_up_to_five(t_node **stack_a, t_node **stack_b,
		int stack_pos)
{
	int	curr_index; //index atual. o qu eto interando 
	int	smallest_num;
	int	middle; //
	int	total_pos; //qtos elemtnso tenho na lista. isso serv para eu saber onde ta o meio. 

	total_pos = stack_pos;
	smallest_num = 0;
	while (stack_pos > 3) 
	{
		curr_index = find_smallest_num_index(stack_a, smallest_num);
		middle = total_pos / 2; //ele vai mudando durante o looping. baseado no meio, vou saber se jogo pro final ou pro começo.
		while ((*stack_a)->index != smallest_num)
		{
			if (curr_index <= middle) //enquanto meu numero atual for menor ou igual ao meio, jogo ele pro final d alista a, pq depois ele vai subindo e ficar no começo, como tem que ser=p
				do_rotate(stack_a, 'a');
			else
				do_reverse_rotate(stack_a, 'a');//se o nu ero atual for maior que q meio, jogo ele no começo; 
		}
		do_push(stack_a, stack_b, 'a'); // qdo ele acha o mneor index, joga pra stack b aqui. 
		stack_pos--;
		smallest_num++; //passa pro proximo numero
	}
	sort_three(stack_a); //qdo tiver so 3 numeros, lee ordena esses tres e joga de volta os numeros do b pro a. 
	while (*stack_b)
		do_push(stack_a, stack_b, 'b');
}