/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:48:31 by antoniof          #+#    #+#             */
/*   Updated: 2025/03/20 19:28:10 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_param(char **params, int i)
{
	while (params && params[i])
	{
		free(params[i]);
		i++;
	}
	free(params);
}

void	free_exit(char **params, int i, t_stack **stack_a, t_stack **stack_b)
{
	free_param(params, i);
	error_exit(stack_a, stack_b);
}
