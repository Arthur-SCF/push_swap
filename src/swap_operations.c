/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:28:54 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/15 17:10:51 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stack_a, int doubled)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = stack_a->top->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	if (doubled == 0)
		ft_printf("sa\n");
}

void	sb(t_stack *stack_b, int doubled)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = stack_b->top->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	if (doubled == 0)
		ft_printf("sb\n");
}
