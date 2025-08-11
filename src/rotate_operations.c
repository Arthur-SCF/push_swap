/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:28:39 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/15 01:34:57 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *stack_a, int doubled)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	last = stack_a->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (doubled != 1)
		ft_printf("ra\n");
}

void	rb(t_stack *stack_b, int doubled)
{
	t_node	*first;
	t_node	*last;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;
	stack_b->top = first->next;
	last = stack_b->top;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	if (doubled != 1)
		ft_printf("rb\n");
}

void	rra(t_stack *stack_a, int doubled)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack_a || stack_a->size < 2)
		return ;
	last = stack_a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_a->top;
	stack_a->top = last;
	second_last->next = NULL;
	if (doubled != 1)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack_b, int doubled)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack_b || stack_b->size < 2)
		return ;
	last = stack_b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_b->top;
	stack_b->top = last;
	second_last->next = NULL;
	if (doubled != 1)
		ft_printf("rrb\n");
}
