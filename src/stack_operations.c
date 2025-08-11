/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:28:50 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/14 02:34:51 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->target_pos = -1;
	new_node->next = NULL;
	return (new_node);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void	push_to_stack(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

t_node	*pop_from_stack(t_stack *stack)
{
	t_node	*node_to_remove;

	if (!stack || !stack->top)
		return (NULL);
	node_to_remove = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	node_to_remove->next = NULL;
	return (node_to_remove);
}
