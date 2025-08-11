/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:28:58 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/15 21:11:54 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack->top;
	while (current)
	{
		index = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_position_in_stack(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		position;

	if (!stack || !node)
		return (-1);
	current = stack->top;
	position = 0;
	while (current)
	{
		if (current == node)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}
