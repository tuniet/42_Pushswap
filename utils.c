/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoniof <antoniof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:13:10 by antoniof          #+#    #+#             */
/*   Updated: 2025/02/10 10:43:41 by antoniof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*THIS FUNCTIONS HELP DURING THE EXECUTION*/

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

long int	ft_atoi(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

double	root(double x)
{
	double	b[7];
	int		i;
	double	ant;
	double	raiz;

	raiz = 0;
	i = 1;
	b[0] = 1.0;
	while (i < 7)
	{
		b[i] = b[i - 1] / 10;
		i++;
	}
	i = -1;
	while (++i < 7)
	{
		ant = -1;
		while ((raiz * raiz) <= x && raiz != ant)
		{
			ant = raiz;
			raiz += b[i];
		}
		raiz -= b[i];
	}
	return (raiz);
}
