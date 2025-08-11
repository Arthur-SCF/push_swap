/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:28:18 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/14 02:49:13 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_to_move;

	if (!stack_b || !stack_b->top)
		return ;
	node_to_move = pop_from_stack(stack_b);
	push_to_stack(stack_a, node_to_move);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node_to_move;

	if (!stack_a || !stack_a->top)
		return ;
	node_to_move = pop_from_stack(stack_a);
	push_to_stack(stack_b, node_to_move);
	ft_printf("pb\n");
}
