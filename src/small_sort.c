/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:28:46 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/15 19:56:07 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_two(t_stack *stack_a)
{
	if (stack_a->top->index > stack_a->top->next->index)
		sa(stack_a, 0);
}

void	sort_three_with_offset(t_stack *stack_a, int offset)
{
	int	first;
	int	second;
	int	third;

	first = stack_a->top->index - offset;
	second = stack_a->top->next->index - offset;
	third = stack_a->top->next->next->index - offset;
	if (first == 0 && second == 2 && third == 1)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (first == 1 && second == 0 && third == 2)
		sa(stack_a, 0);
	else if (first == 1 && second == 2 && third == 0)
		rra(stack_a, 0);
	else if (first == 2 && second == 0 && third == 1)
		ra(stack_a, 0);
	else if (first == 2 && second == 1 && third == 0)
	{
		sa(stack_a, 0);
		rra(stack_a, 0);
	}
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		sort_two(stack_a);
	else if (stack_a->size == 3)
		sort_three_with_offset(stack_a, 0);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
}
