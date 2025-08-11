/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asurcouf <asurcouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 18:27:53 by asurcouf          #+#    #+#             */
/*   Updated: 2025/07/16 22:41:53 by asurcouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	current = stack->top;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			if (current->value == compare->value)
				return (1);
			compare = compare->next;
		}
		current = current->next;
	}
	return (0);
}

int	is_valid_input(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	parse_and_fill_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		value;
	t_node	*new_node;

	i = argc - 1;
	while (i > 0)
	{
		value = ft_atoi(argv[i]);
		new_node = create_node(value);
		if (!new_node)
		{
			ft_printf("Error\n");
			exit(1);
		}
		push_to_stack(stack_a, new_node);
		i--;
	}
	if (has_duplicates(stack_a))
	{
		ft_printf("Error\n");
		free_stack(stack_a);
		exit(1);
	}
}
