/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:36:42 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/15 21:48:17 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_min_to_b(t_stack *stack_a, t_stack *stack_b, int target_index)
{
	int		position;
	int		size;
	t_node	*current;

	position = 0;
	size = stack_a->size;
	current = stack_a->top;
	while (current && current->index != target_index)
	{
		current = current->next;
		position++;
	}
	if (position <= size / 2)
	{
		while (stack_a->top->index != target_index)
			ra(stack_a, 0);
	}
	else
	{
		while (stack_a->top->index != target_index)
			rra(stack_a, 0);
	}
	pb(stack_a, stack_b);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_b(stack_a, stack_b, 0);
	sort_three_with_offset(stack_a, 1);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	push_min_to_b(stack_a, stack_b, 0);
	push_min_to_b(stack_a, stack_b, 1);
	sort_three_with_offset(stack_a, 2);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
