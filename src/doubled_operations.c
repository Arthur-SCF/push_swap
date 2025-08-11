/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubled_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:29:46 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/16 21:44:23 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_printf("ss\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	printf("rr\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	printf("rrr\n");
}
