/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:07:05 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/06 21:02:20 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*tmp;
	int		flag;

	min = NULL;
	tmp = *stack;
	flag = 1;
	while (tmp)
	{
		if (tmp->index == -1 && (flag || tmp->content < min->content))
		{
			min = tmp;
			flag = 0;
		}
		tmp = tmp->next;
	}
	return (min);
}

void	ft_index(t_stack **stack)
{
	t_stack	*min_node;
	int		i;

	i = 0;
	min_node = get_next_min(stack);
	while (min_node)
	{
		min_node->index = i;
		i++;
		min_node = get_next_min(stack);
	}
}
