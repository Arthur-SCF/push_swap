/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:27:40 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/20 21:59:33 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_chunk_size(int stack_size)
{
	if (stack_size <= 10)
		return (3);
	if (stack_size <= 50)
		return (5);
	if (stack_size <= 100)
		return (40);
	if (stack_size <= 500)
		return (50);
	return (60);
}

static int	count_elements_in_chunk(t_stack *stack_a, int min_idx, int max_idx)
{
	t_node	*current;
	int		count;

	count = 0;
	current = stack_a->top;
	while (current)
	{
		if (current->index >= min_idx && current->index <= max_idx)
			count++;
		current = current->next;
	}
	return (count);
}

static void	rotate_to_chunk_element(t_stack *stack_a, int min_idx, int max_idx)
{
	int	rotations;

	rotations = 0;
	while (stack_a->top && rotations < stack_a->size)
	{
		if (stack_a->top->index >= min_idx && stack_a->top->index <= max_idx)
			break ;
		ra(stack_a, 0);
		rotations++;
	}
}

static void	push_chunk(t_stack *stack_a, t_stack *stack_b, int min_i, int max_i)
{
	int	total_to_push;
	int	pushed_count;

	total_to_push = count_elements_in_chunk(stack_a, min_i, max_i);
	pushed_count = 0;
	while (pushed_count < total_to_push && stack_a->size > 0)
	{
		if (stack_a->top->index >= min_i && stack_a->top->index <= max_i)
		{
			pb(stack_a, stack_b);
			if (stack_b->size > 1 && stack_b->top->index < min_i + 3)
				rb(stack_b, 0);
			pushed_count++;
		}
		else
			rotate_to_chunk_element(stack_a, min_i, max_i);
	}
}

void	push_all_chunks_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	current_idx_min;
	int	current_idx_max;
	int	total_size;

	total_size = stack_a->size;
	chunk_size = get_chunk_size(total_size);
	current_idx_min = 0;
	while (current_idx_min < total_size)
	{
		current_idx_max = current_idx_min + chunk_size - 1;
		if (current_idx_max >= total_size)
			current_idx_max = total_size - 1;
		push_chunk(stack_a, stack_b, current_idx_min, current_idx_max);
		current_idx_min += chunk_size;
	}
}
