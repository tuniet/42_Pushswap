/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:11:56 by antoniof          #+#    #+#             */
/*   Updated: 2025/04/01 11:24:21 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				target;
	struct s_stack	*next;
}	t_stack;

long		input_is_correct(char *av);
void		error_exit(t_stack **stack_a, t_stack **stack_b);
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
void		get_index(t_stack *stack_a, int stack_size);
t_stack		*stack_new(int value);
void		stack_add(t_stack **stack, t_stack *new);
t_stack		*get_bottom(t_stack *stack);
int			get_stack_size(t_stack	*stack);
int			is_sorted(t_stack *stack);
void		sort_three(t_stack **stack);
void		do_sa(t_stack **stack_a);
void		do_sa(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_putstr(char *str);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
t_stack		*before_bottom(t_stack *stack);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		sort(t_stack **stack_a, t_stack **stack_b);
void		get_target_position(t_stack **stack_a, t_stack **stack_b);
void		cost(t_stack **stack_a, t_stack **stack_b);
void		cheapest_move(t_stack **stack_a, t_stack **stack_b);
int			abs(int nb);
void		do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
int			position_lowest_index(t_stack **stack);
char		**ft_split(char const *s, char c);
void		get_numbers(char *av, t_stack **stack_a);
int			is_duplicate(t_stack *column);
size_t		ft_strlen(const char *s);
void		printstacks(t_stack *a, t_stack *b);
double		root(double x);
void		sort_five(t_stack **stack_a, t_stack **stack_b);
void		free_param(char **param, int i);
void		free_exit(char **param, int i,
				t_stack **stack_a, t_stack **stack_b);

#endif
