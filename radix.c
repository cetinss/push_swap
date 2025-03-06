/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:32:47 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/06 21:05:28 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int max_bits;
	int max;

	max_bits = 0;
	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		size = ft_stacksize(*stack_a);
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			ft_pa(stack_a, stack_b);
		i++;
	}
}
