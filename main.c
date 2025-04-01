/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:11:32 by antoniof          #+#    #+#             */
/*   Updated: 2025/04/01 11:23:00 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_all(t_stack **stack_a, t_stack **stack_b, int k)
{
	int	i;

	i = 1;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index <= i)
		{
			do_pb(stack_a, stack_b);
			if ((*stack_b)->next != NULL)
				do_rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index > i && (*stack_a)->index < (k + i))
		{
			do_pb(stack_a, stack_b);
			i++;
		}
		else
		{
			do_ra(stack_a);
		}
	}
	return (i);
}

int	calcmove(t_stack *stack_b, int i)
{
	int	pos;

	pos = 0;
	while (stack_b != NULL)
	{
		if (stack_b->index == i)
			break ;
		pos++;
		stack_b = stack_b->next;
	}
	if (pos > i / 2)
		pos = pos - i;
	return (pos);
}

void	sort_back(t_stack **stack_a, t_stack **stack_b, int i)
{
	int	move;

	while (i > 0)
	{
		move = calcmove(*stack_b, i);
		while (move != 0)
		{
			if (move > 0)
			{
				do_rb(stack_b);
				move--;
			}
			if (move < 0)
			{
				do_rrb(stack_b);
				move++;
			}
		}
		do_pa(stack_a, stack_b);
		i--;
	}
}

void	solve(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	k;

	if (size <= 3)
	{
		sort_three(stack_a);
	}
	else if (size <= 5)
	{
		sort_five(stack_a, stack_b);
	}
	else
	{
		if (!is_sorted(*stack_a))
		{
			k = root(size) + (0.4 * root(size));
			push_all(stack_a, stack_b, k);
			sort_back(stack_a, stack_b, size);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	int		i;

	i = 1;
	stack_b = NULL;
	stack_a = NULL;
	if (ac > 1)
	{
		while (i < ac)
			get_numbers(av[i++], &stack_a);
		if (!stack_a)
			exit(0);
		if (is_duplicate(stack_a))
			error_exit(&stack_a, NULL);
		stack_size = get_stack_size(stack_a);
		get_index(stack_a, stack_size + 1);
		solve(&stack_a, &stack_b, stack_size);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (0);
}
