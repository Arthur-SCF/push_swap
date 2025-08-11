/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 01:40:00 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/20 19:32:01 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Calculates the cost of rotating a stack to bring a target node to the top.
** Returns the minimum number of rotations needed (forward or reverse).
** Used to determine the most efficient way to access an element.
*/
int	calculate_rotation_cost(t_stack *stack, t_node *target)
{
	int	position;
	int	size;

	position = find_position_in_stack(stack, target);
	size = stack->size;
	if (position == -1)
		return (1000);
	if (position <= size / 2)
		return (position);
	else
		return (size - position);
}

/*
** Finds the position after the maximum value in stack A.
** Used when no number greater than target exists in stack A.
*/
static int	find_position_after_max(t_stack *stack_a)
{
	t_node	*current;
	int		max_value;
	int		position;

	current = stack_a->top;
	max_value = INT_MIN;
	position = 0;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	current = stack_a->top;
	position = 0;
	while (current)
	{
		if (current->value == max_value)
			return ((position + 1) % stack_a->size);
		current = current->next;
		position++;
	}
	return (0);
}

/*
** Finds the optimal position in stack A where
** a node from stack B should be inserted.
** Looks for the smallest number greater than the target value.
** If no such number exists, places it after 
** the maximum value for correct ordering.
*/
int	find_target_pos_in_a(t_stack *stack_a, t_node *node_b)
{
	t_node	*current;
	int		target_pos;
	int		min_bigger;
	int		position;

	if (!stack_a || !stack_a->top)
		return (0);
	current = stack_a->top;
	target_pos = 0;
	min_bigger = INT_MAX;
	position = 0;
	while (current)
	{
		if (current->value > node_b->value && current->value < min_bigger)
		{
			min_bigger = current->value;
			target_pos = position;
		}
		current = current->next;
		position++;
	}
	if (min_bigger == INT_MAX)
		return (find_position_after_max(stack_a));
	return (target_pos);
}

/*
** Finds the most cost-effective element in stack B to move next.
** Calculates total cost as: rotation cost + element's index (priority).
** Lower indexed elements (pushed later) have higher priority.
*/
t_node	*find_cheapest_in_b(t_stack *stack_b)
{
	t_node	*current;
	t_node	*cheapest;
	int		min_cost;
	int		cost;

	if (!stack_b || !stack_b->top)
		return (NULL);
	current = stack_b->top;
	cheapest = current;
	min_cost = 1000;
	while (current)
	{
		cost = calculate_rotation_cost(stack_b, current) + current->index;
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = current;
		}
		current = current->next;
	}
	return (cheapest);
}
