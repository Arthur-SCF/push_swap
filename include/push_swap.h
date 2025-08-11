/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:32:26 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/20 19:48:11 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../ft_printf/includes/ft_printf.h"

/* ************************************************************************** */
/*                                STRUCTURES                                  */
/* ************************************************************************** */

typedef struct s_node
{
	int				value;
	int				index;
	int				target_pos;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}	t_stack;

/* ************************************************************************** */
/*                              PARSING FUNCTIONS                             */
/* ************************************************************************** */

// parsing.c
int		ft_atoi(const char *str);
int		is_valid_number(const char *str);
int		has_duplicates(t_stack *stack);
int		is_valid_input(int argc, char **argv);
void	parse_and_fill_stack(int argc, char **argv, t_stack *stack_a);

/* ************************************************************************** */
/*                            STACK OPERATIONS                                */
/* ************************************************************************** */

// stack_operations.c
t_node	*create_node(int value);
void	push_to_stack(t_stack *stack, t_node *node);
t_node	*pop_from_stack(t_stack *stack);
void	free_stack(t_stack *stack);
t_stack	*init_stack(void);

/* ************************************************************************** */
/*                            BASIC OPERATIONS                                */
/* ************************************************************************** */

// swap_operations.c
void	sa(t_stack *stack_a, int doubled);
void	sb(t_stack *stack_b, int doubled);

// push_operations.c
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

// rotate_operations.c
void	ra(t_stack *stack_a, int doubled);
void	rb(t_stack *stack_b, int doubled);
void	rra(t_stack *stack_a, int doubled);
void	rrb(t_stack *stack_b, int doubled);

/* ************************************************************************** */
/*                           DOUBLED OPERATIONS                               */
/* ************************************************************************** */

// doubled_operations.c
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                             SORTING ALGORITHMS                             */
/* ************************************************************************** */

// small_sort.c
void	sort_three_with_offset(t_stack *stack_a, int offset);
void	small_sort(t_stack *stack_a, t_stack *stack_b);

// small_sort_2.c
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

// chunk_sort.c
void	push_all_chunks_to_b(t_stack *stack_a, t_stack *stack_b);

// greedy_utils.c
int		calculate_rotation_cost(t_stack *stack, t_node *target);
int		find_target_pos_in_a(t_stack *stack_a, t_node *node_b);
t_node	*find_cheapest_in_b(t_stack *stack_b);

// greedy_sort.c
void	greedy_sort_back_to_a(t_stack *stack_a, t_stack *stack_b);

/* ************************************************************************** */
/*                              UTILITY FUNCTIONS                             */
/* ************************************************************************** */

// utils.c
void	assign_indices(t_stack *stack);
int		is_sorted(t_stack *stack);
int		find_position_in_stack(t_stack *stack, t_node *node);

#endif //PUSH_SWAP_H