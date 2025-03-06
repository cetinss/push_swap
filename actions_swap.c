/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:38:19 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/06 21:02:04 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	t_stack *first;
	t_stack *second;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	write(1, "ss\n", 3);
}
