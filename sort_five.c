/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:44:09 by antoniof          #+#    #+#             */
/*   Updated: 2025/03/10 16:15:11 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	settarget(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		if (stack_a->index > stack_b->index)
			break ;
		i++;
		stack_a = stack_a->next;
	}
	stack_b->target = i;
}

void	place_back(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	target;

	target = (*stack_b)->target;
	stack_size = get_stack_size(*stack_a);
	if (target == 2)
	{
		if (stack_size == 4)
			do_rra(stack_a);
		do_rra(stack_a);
	}
	else if ((target == 3 && stack_size == 4))
		do_rra(stack_a);
	do_pa(stack_a, stack_b);
	if (target == 1)
		do_sa(stack_a);
	else if ((target == 3 && stack_size == 3) || target == 4)
	{
		do_ra(stack_a);
	}
	else if (target == 2 || (target == 3 && stack_size == 4))
	{
		do_ra(stack_a);
		do_ra(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	if (!is_sorted(*stack_a))
	{
		stack_size = get_stack_size(*stack_a);
		if ((*stack_a)->index == 3)
			do_ra(stack_a);
		do_pb(stack_a, stack_b);
		if ((*stack_a)->index == 3)
			do_ra(stack_a);
		if (stack_size == 5)
			do_pb(stack_a, stack_b);
		sort_three(stack_a);
		settarget(*stack_a, *stack_b);
		place_back(stack_a, stack_b);
		if (stack_size == 5)
		{
			settarget(*stack_a, *stack_b);
			place_back(stack_a, stack_b);
		}
	}
}
