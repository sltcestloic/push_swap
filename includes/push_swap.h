/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbertran <lbertran@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:40:58 by lbertran          #+#    #+#             */
/*   Updated: 2021/05/19 12:44:38 by lbertran         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int			capacity;
	int			head;
	int			*content;
}				t_stack;

typedef struct s_map
{
	int			*key;
	int			*value;
	int			index;
	int			capacity;
}				t_map;

typedef struct s_game
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_map		*map;
	int			verbose;
	int			color;
	int			biggest;
	int			smallest;
	int			median;
	int			chunk_size;
	int			step;
	int			pushed;
	int			pushed_nbr;
	int			swapped;
	int			swap_a;
	int			swap_b;
	int			rotated;
	int			rotated_nbr;
}				t_game;

typedef struct s_range
{
	int			min;
	int			max;
}				t_range;

/*
** Basic stack functions
*/

t_stack	*new_stack(int capacity);
int		stack_size(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
void	stack_push(t_stack *stack, int val);
int		stack_peek(t_stack *stack);
int		stack_pop(t_stack *stack);

/*
** Stack utils
*/

t_stack	*stack_copy(t_stack *stack);
int		is_stack_sorted(t_stack *stack);
void	reverse_stack(t_stack *tmp, t_stack *stack);
int		stack_smallest(t_stack *stack);
int		stack_biggest(t_stack *stack);
int		stack_smallest_index(t_stack *stack);
int		stack_biggest_index(t_stack *stack);
int		stack_get(t_stack *stack, int head);
void	print_stack(t_stack *stack);

/*
** Stack sorting utils
*/

void	push_to_top_a(t_game *game, t_stack *stack, int index);
void	push_to_top_b(t_game *game, t_stack *stack, int index);
void	push_to_top_silent(t_game *game, t_stack *stack, int index);
int		find_next_bigger(t_stack *stack, int current);
int		find_next_smaller(t_stack *stack, int current);
int		find_next(t_stack *stack, int current);
int		get_ideal_chunk_size(t_game *game, int biggest);
int		find_in_range(t_stack *stack, t_game *game);
int		find_median(t_stack *stack, int mid);
int		find_median_value(t_stack *stack, int mid);
int		stack_get(t_stack *stack, int head);
int		actions_to_top(t_stack *stack, int index, int head);

/*
** Push swap operations
*/

void	ps_push(t_game *game, t_stack *origin, t_stack *destination, char *msg);
void	ps_rotate(t_game *game, t_stack *stack, char *msg);
void	ps_rr(t_game *game, t_stack *stack_a, t_stack *stack_b);
void	ps_swap(t_game *game, t_stack *stack, char *msg);
void	ps_ss(t_game *game, t_stack *stack_a, t_stack *stack_b);
void	ps_rrotate(t_game *game, t_stack *stack, char *msg);
void	ps_rrr(t_game *game, t_stack *stack_a, t_stack *stack_b);

/*
** Push swap functions
*/

void	sort_3(t_game *game, t_stack *stack);
void	sort_5(t_game *game);
void	sort(t_game *game);
void	print_game(t_game *game);

/*
** Parsing
*/

void	parse_normal_input(int ac, char **av, t_game *game);
void	parse_char_input(char **av, t_game *game);
void	parse_input(int ac, char **av, t_game *game);

/*
** Utils
*/

int		splitlen(char **split);
int		ft_abs(int i);
char	*get_color(int val, t_game *game);

/*
** Errors
*/

void	exit_error(char *message);
void	print_error(char *message);

/*
** Map
*/

void	init_map(t_game *game);
void	map_put(t_game *game, int key, int value);
int		map_get(t_game *game, int key);
void	set_indexes(t_game *game);

#endif
