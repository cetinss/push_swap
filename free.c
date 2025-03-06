/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:21:08 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/06 21:02:17 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	free(stack);
}

void	error_exit(char **splitted)
{
	ft_free_str(splitted);
	write(2, "Error\n", 6);
	exit (1);
}
