/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:40:00 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/17 01:53:52 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Rotates stack B to bring the target element to the top.
** Uses the most efficient rotation direction (forward or reverse).
*/
static void	rotate_stack_b_to_target(t_stack *stack_b, int pos_in_b)
{
	if (pos_in_b <= stack_b->size / 2)
	{
		while (pos_in_b-- > 0)
			rb(stack_b, 0);
	}
	else
	{
		while (pos_in_b++ < stack_b->size)
			rrb(stack_b, 0);
	}
}

/*
** Rotates stack A to the correct insertion position.
** Prepares stack A to receive the element from stack B in sorted order.
*/
static void	rotate_stack_a_to_target(t_stack *stack_a, int target_pos_in_a)
{
	if (target_pos_in_a <= stack_a->size / 2)
	{
		while (target_pos_in_a-- > 0)
			ra(stack_a, 0);
	}
	else
	{
		while (target_pos_in_a++ < stack_a->size)
			rra(stack_a, 0);
	}
}

/*
** Executes the complete move operation for the cheapest element.
** Rotates both stacks to optimal positions, then pushes from B to A.
*/
static void	cheapest_move(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
	int	pos_in_b;
	int	target_pos_in_a;

	pos_in_b = find_position_in_stack(stack_b, cheapest);
	target_pos_in_a = find_target_pos_in_a(stack_a, cheapest);
	rotate_stack_b_to_target(stack_b, pos_in_b);
	rotate_stack_a_to_target(stack_a, target_pos_in_a);
	pa(stack_a, stack_b);
}

/*
** Main greedy sorting algorithm that moves all elements from B back to A.
** Repeatedly finds and moves the cheapest element until B is empty.
** Finally ensures A is properly sorted with minimal element on top.
*/
void	greedy_sort_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_b && stack_b->size > 0)
	{
		cheapest = find_cheapest_in_b(stack_b);
		if (!cheapest)
			break ;
		cheapest_move(stack_a, stack_b, cheapest);
	}
	while (!is_sorted(stack_a))
	{
		if (find_position_in_stack(stack_a, stack_a->top) <= stack_a->size / 2)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}
