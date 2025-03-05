/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sencetin <sencetin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:11:04 by sencetin          #+#    #+#             */
/*   Updated: 2025/03/05 14:36:14 by sencetin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_stack(t_stack *stack) // silinecek
{
	char	*str;

	while (stack)
	{
		ft_putstr_fd("Value: ", 1);
		str = ft_itoa(stack->content);
		ft_putstr_fd(str, 1);
		free(str);
		ft_putstr_fd(", Index: ", 1);
		str = ft_itoa(stack->index);
		ft_putstr_fd(str, 1);
		free(str);
		ft_putstr_fd("\n", 1);
		stack = stack->next;
	}
}


// static void	ft_stack_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	if (ft_stacksize(*stack_a) <= 5)
// 		ft_basic_sort(stack_a, stack_b);
// 	else if (ft_stacksize(*stack_a) > 5)
// 		ft_radix(stack_a, stack_b);
// }

static	void	ft_get_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;
	char	**splitted;
	int		i;
	int		j;
	
	i = 1;
	while (i < argc)
	{
		splitted = ft_split(argv[i++], ' ');
		j = 0;
		while (splitted[j])
		{
			new = ft_stacknew(ft_atoi(splitted[j]));
			if (!new)
			{
				ft_free_str(splitted);
				ft_free_stack(stack);
				return ;
			}
			ft_stackadd_back(stack, new);
			j++;
		}
		ft_free_str(splitted);
	}
	//ft_index(stack);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (argc < 2)
		return (-1);
	validate_arguments(argv);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_get_stack(stack_a, argc, argv);
	// if (ft_check_sort(*stack_a))
	// {
	// 	ft_free_stack(stack_a);
	// 	ft_free_stack(stack_b);
	// 	return (0);
	// }
	display_stack(*stack_a);
	//ft_stack_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
