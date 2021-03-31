/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:58 by lbertran          #+#    #+#             */
/*   Updated: 2021/03/31 13:32:15 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"


typedef struct	s_stack
{
	int			capacity;
	int			head;
	int			*content;
}				t_stack;

typedef struct	s_game
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			verbose;
}				t_game;


void	exit_error(char *message);
void	print_error(char *message);

t_stack	*new_stack(int capacity);
int		stack_size(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
void	stack_push(t_stack *stack, int val);
int		stack_peek(t_stack *stack);
int		stack_pop(t_stack *stack);
t_stack	*stack_copy(t_stack *stack);
void	print_stack(t_stack *stack);
int		is_stack_sorted(t_stack *stack);
void	reverse_stack(t_stack *tmp, t_stack *stack);
int		stack_smallest(t_stack *stack);
int		stack_biggest(t_stack *stack);
int		stack_smallest_index(t_stack *stack);
int		stack_biggest_index(t_stack *stack);
int		stack_get(t_stack *stack, int head);
void	push_to_top_a(t_stack *stack, int index);
void	push_to_top_b(t_stack *stack, int index);
int		find_next_bigger(t_stack *stack, int current);
int		find_next_smaller(t_stack *stack, int current);
int		find_next(t_stack *stack, int current);

void	ps_push(t_stack *origin, t_stack *destination, char *msg);
void	ps_rotate(t_stack *stack, char *msg);
void	ps_rr(t_stack *stack_a, t_stack *stack_b);
void	ps_swap(t_stack *stack, char *msg);
void	ps_ss(t_stack *stack_a, t_stack *stack_b);
void	ps_rrotate(t_stack *stack, char *msg);
void	ps_rrr(t_stack *stack_a, t_stack *stack_b);
void	print_game(t_game *game);
int		stack_get(t_stack *stack, int head);
void	sort_3(t_stack *stack);
void	sort_5(t_game *game);
void	sort(t_game *game);
void	newsort(t_game *game);
int		actions_to_top(t_stack *stack, int index);


/*
** Parsing
*/

void	parse_normal_input(int ac, char **av, t_game *game);
void	parse_char_input(int ac, char **av, t_game *game);
void	parse_input(int ac, char **av, t_game *game);


/*
** Utils
*/

int		splitlen(char **split);

#endif
