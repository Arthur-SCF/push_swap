/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:27:45 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/16 22:37:46 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	chunk_greedy_sort(t_stack *stack_a, t_stack *stack_b)
{
	push_all_chunks_to_b(stack_a, stack_b);
	greedy_sort_back_to_a(stack_a, stack_b);
}

static int	initialize_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = init_stack();
	*stack_b = init_stack();
	if (!*stack_a || !*stack_b)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	if (!is_valid_input(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!initialize_stacks(&stack_a, &stack_b))
		return (1);
	parse_and_fill_stack(argc, argv, stack_a);
	assign_indices(stack_a);
	if (is_sorted(stack_a))
		return (free_stack(stack_a), free_stack(stack_b), 0);
	if (stack_a->size <= 5)
		small_sort(stack_a, stack_b);
	else
		chunk_greedy_sort(stack_a, stack_b);
	return (free_stack(stack_a), free_stack(stack_b), 0);
}
